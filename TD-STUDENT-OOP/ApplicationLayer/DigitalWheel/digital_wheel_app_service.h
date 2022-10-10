//TO COMPLETE
#ifndef DW_APP_SERVICE_H
#define DW_APP_SERVICE_H

#include "digital_wheel.h"

digital_wheel create(int start, int end);

void digitalWheelAppService_display(char *str, digital_wheel dw1, digital_wheel dw2);

void digitalWheelAppService_run(digital_wheel dw1, digital_wheel dw2, int rolling_speed_1, int rolling_speed_2);

void destroy(digital_wheel dw);

#endif
// Completed