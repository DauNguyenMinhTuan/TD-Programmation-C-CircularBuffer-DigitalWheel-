/*******Compléter****/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "digital_wheel_app_service.h"
#include "digital_wheel.h"
#include "class.h"
#include "instantiate.h"

#define NUMBER_OF_ROLL 5

static void display(char *str, int wheel_value){
    printf("%s[ %d ]", str, wheel_value);
}

int main(int argc, char **argv){
    int wheel_max_value = argc > 1 ? strtol(argv[1], NULL, 10) : -1;
    int rolling_speed = argc > 2 ? strtol(argv[2], NULL, 10) : -1;

    digital_wheel dw = digital_wheel_construct(0, wheel_max_value);
    display("Departure...\n", digital_wheel_get_current_position(dw));
    int i = NUMBER_OF_ROLL;
    printf("\nWheeling...");
    while(i-- > 0){
        run(dw, rolling_speed);
        display("\n", digital_wheel_get_current_position(dw));
    }
    return EXIT_SUCCESS;
}