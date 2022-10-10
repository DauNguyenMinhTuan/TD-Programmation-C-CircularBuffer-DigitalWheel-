/*******Compléter****/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "digital_wheel_app_service.h"
#include "digital_wheel.h"
#include "class.h"
#include "instantiate.h"

static void prompt(){
    puts("***************************************************************************");
    puts("*                      2 Digital Wheels Created                           *");
    puts("***************************************************************************");
    puts("***************************************************************************");
    puts("*   Input one character at a time and hit Enter to control the 2 wheels   *");
    puts("***************************************************************************");
    puts("***************************************************************************");
    puts("* [ < : Reset, > : Roll all wheels, ! : Stop all wheels, Ctrl + C: Quit ] *");
    puts("***************************************************************************");
}

int main(int argc, char **argv){
    int wheel_max_value = argc > 1 ? strtol(argv[1], NULL, 10) : -1;
    int rolling_speed_1 = argc > 2 ? strtol(argv[2], NULL, 10) : -1;
    int rolling_speed_2 = argc > 3 ? strtol(argv[3], NULL, 10) : -1;

    // Instruction
    prompt();

    // Initiate
    digital_wheel dw1 = create(0, wheel_max_value);
    digital_wheel dw2 = create(0, wheel_max_value);
    
    // Run
    digitalWheelAppService_run(dw1, dw2, rolling_speed_1, rolling_speed_2);

    // Clean up
    destroy(dw1);
    destroy(dw2);
    return EXIT_SUCCESS;
}