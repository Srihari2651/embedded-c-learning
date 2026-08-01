/*
 * cluster.c
 * The C equivalent of the interactive instrument cluster widget above.
 *
 * Same three ideas as the widget, now in plain C:
 *   1. A gear STATE MACHINE (P/D) driven by speed - same pattern as
 *      your state_machine.c traffic light, just two states instead of four.
 *   2. A sensor-to-value mapping (speed -> RPM) - on real hardware this
 *      would come from a wheel-speed sensor read via ADC/timer capture,
 *      here we fake it with a simple formula, same as the widget's JS did.
 *   3. A tick function called on a fixed schedule (like a 100ms timer
 *      interrupt would do on an MCU), which is how instrument clusters
 *      actually update - not continuously, but on a scheduled tick.
 *
 * Compile with: gcc cluster.c -o cluster && ./cluster
 */

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

/*
 * Decide the gear from speed.
 *
 * NOTE - real-world gotcha: a hard threshold like "speed < 1.0f" will
 * flicker between P and D if the speed sensor reads 0.9, 1.1, 0.9, 1.1
 * due to sensor noise. Real ECUs use HYSTERESIS - e.g. switch to D above
 * 1.0 km/h, but only switch back to P below 0.3 km/h. That gap prevents
 * rapid state flapping. This simple version skips that for clarity -
 * try adding hysteresis yourself as a follow-up exercise.
 */
static gear_state_t decide_gear(float speed_kmh)
{
    return (speed_kmh < 1.0f) ? GEAR_PARK : GEAR_DRIVE;
}

/* Same formula as the widget's JS: rpm = (speed/220)*7 + 0.8, capped at 8 */
static float speed_to_rpm(float speed_kmh)
{
    float rpm = (speed_kmh / 220.0f) * 7.0f + 0.8f;
    return (rpm > 8.0f) ? 8.0f : rpm;
}

/* Call this once per tick - on an MCU, this would be called from a
 * TIM2 interrupt handler every 100ms, reading a real speed sensor. */
void cluster_tick(cluster_t *c, float new_speed_kmh)
{
    c->speed_kmh = new_speed_kmh;
    c->rpm       = speed_to_rpm(new_speed_kmh);
    c->gear      = decide_gear(new_speed_kmh);
}

int main(void)
{
    cluster_t cluster = {GEAR_PARK, 0.0f, 0.0f};

    /* Simulated speed readings over time - imagine this coming from
     * a wheel-speed sensor once per tick instead of a slider drag. */
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
