/*
 * splash_screen.c
 *
 * A simple "preview" program — prints an ASCII-art banner when run,
 * just like the visual banner at the top of a README.
 *
 * On a desktop: compile and run to see it in your terminal.
 *   gcc splash_screen.c -o splash_screen && ./splash_screen
 *
 * On an MCU: this same printf() pattern is exactly what you'd send
 * over UART as a "firmware boot banner" — many real ECUs print a
 * version/build banner like this over a debug UART on startup.
 */

#include <stdio.h>

static void print_car(void)
{
    printf("        ______________\n");
    printf("       /|             |\\\n");
    printf("      / |   HARI ECU  | \\\n");
    printf("     /__|_____________|__\\\n");
    printf("     |  ___         ___  |\n");
    printf("     |=(   )=======(   )=|\n");
    printf("     |  ~~~         ~~~  |\n");
    printf("     |_____________________|\n");
}

static void print_banner(void)
{
    printf("========================================\n");
    printf("   EMBEDDED-C-LEARNING :: BOOT PREVIEW\n");
    printf("========================================\n\n");

    print_car();

    printf("\n----------------------------------------\n");
    printf(" Target      : STM32F103 (Blue Pill)\n");
    printf(" Firmware    : v0.1 - LED + Ring Buffer\n");
    printf(" Status      : Engine started. Ready.\n");
    printf("----------------------------------------\n");
}

int main(void)
{
    print_banner();
    return 0;
}
