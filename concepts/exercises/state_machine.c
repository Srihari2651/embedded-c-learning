#include <stdio.h>
#include <stdint.h>

typedef enum {
    GEAR_PARK = 0,
    GEAR_DRIVE
} gear_state_t;

typedef struct {
    gear_state_t gear;
    float        speed_kmh;
    float        rpm;
} cluster_t;

static const char *gear_name(gear_state_t g)
{
    return (g == GEAR_PARK) ? "P" : "D";
}
r_state_t decide_gear(float speed_kmh)
{
    return (speed_kmh < 1.0f) ? GEAR_PARK : GEAR_DRIVE;
}

/* Same formula as the widget's JS: rpm = (speed/220)*7 + 0.8, capped at 8 */
static float speed_to_rpm(float speed_kmh)
{
    float rpm = (speed_kmh / 220.0f) * 7.0f + 0.8f;
    return (rpm > 8.0f) ? 8.0f : rpm;
}
void cluster_tick(cluster_t *c, float new_speed_kmh)
{
    c->speed_kmh = new_speed_kmh;
    c->rpm       = speed_to_rpm(new_speed_kmh);
    c->gear      = decide_gear(new_speed_kmh);
}

int main(void)
{
    cluster_t cluster = {GEAR_PARK, 0.0f, 0.0f};
    float test_speeds[] = {0.0f, 0.0f, 5.0f, 40.0f, 90.0f, 140.0f, 200.0f, 60.0f, 0.5f};
    int   num_samples   = (int)(sizeof(test_speeds) / sizeof(test_speeds[0]));

    printf("tick  speed(km/h)  rpm(x1000)  gear\n");
    printf("----  -----------  ----------  ----\n");

    for (int tick = 0; tick < num_samples; tick++) {
        cluster_tick(&cluster, test_speeds[tick]);
        printf("%3d   %10.1f   %9.1f   %4s\n",
               tick, cluster.speed_kmh, cluster.rpm, gear_name(cluster.gear));
    }

    return 0;
}
