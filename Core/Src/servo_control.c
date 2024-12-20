#include "servo_control.h"

extern TIM_HandleTypeDef htim2;

void Servo_Init(void)
{
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
}

void Servo_SetPosition(uint32_t position)
{
    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, position);
    HAL_Delay(50);
}

void Servo_Sweep(uint32_t start_pos, uint32_t end_pos)
{
    uint32_t duty;
    if (start_pos < end_pos) {
        for (duty = start_pos; duty <= end_pos; duty++) {
            Servo_SetPosition(duty);
        }
    } else {
        for (duty = start_pos; duty >= end_pos; duty--) {
            Servo_SetPosition(duty);
        }
    }
    HAL_Delay(1000);
}
