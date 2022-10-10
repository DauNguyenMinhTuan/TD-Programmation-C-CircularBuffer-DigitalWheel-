//TO COMPLETE
#include <stdio.h>
#include "digital_wheel_app_service.h"
#include "digital_wheel.h"
#include "class.h"
#include "instantiate.h"

digital_wheel create(int start, int end){
    return digital_wheel_construct(start, end);
}

void digitalWheelAppService_display(char *str, digital_wheel dw1, digital_wheel dw2){
    printf("%s[ %d ] [ %d ]", str, digital_wheel_get_current_position(dw1), digital_wheel_get_current_position(dw2));
}

void digitalWheelAppService_run(digital_wheel dw1, digital_wheel dw2, int rolling_speed_1, int rolling_speed_2){
    digitalWheelAppService_display("Departure with...\n", dw1, dw2);
    char control;
    while(control != EOF){
        printf("\nCommand: ");
        fflush(stdin);
        control = getchar();
        switch(control){
            case '<':
                // Reset
                digital_wheel_initialize(dw1);
                digital_wheel_initialize(dw2);
                digitalWheelAppService_display("Everything is reset!\nDeparture with...\n", dw1, dw2);
                break;
            case '>':{
                // Continue
                int cnt;
                cnt = rolling_speed_1;
                while(cnt--){
                    digital_wheel_move_to_next_position(dw1);
                }
                cnt = rolling_speed_2;
                while(cnt--){
                    digital_wheel_move_to_next_position(dw2);
                }
                digitalWheelAppService_display("Continue running...\n", dw1, dw2);
                break;
            }
            case '!':
                // Stop
                digitalWheelAppService_display("We stop here at...\n", dw1, dw2);
                return;
            default:
                // Invalid command
                break;
        }
    }
}

void destroy(digital_wheel dw){
    digital_wheel_collect(dw);
}