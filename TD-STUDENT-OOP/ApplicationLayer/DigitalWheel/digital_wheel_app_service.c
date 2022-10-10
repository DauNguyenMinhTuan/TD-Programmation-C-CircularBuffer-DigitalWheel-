//TO COMPLETE
#include <stdio.h>
#include "digital_wheel_app_service.h"
#include "digital_wheel.h"
#include "class.h"
#include "instantiate.h"

void run(digital_wheel self, int rolling_speed){
    while(rolling_speed-- > 0){
        if(!digital_wheel_move_to_next_position(self)){
            printf("\nNew round...");
        }
    }
}