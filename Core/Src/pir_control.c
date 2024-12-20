/* pir_control.c */
#include "pir_control.h"

static int cont_seconds_stop = 0;

void PIR_Process(void)
{
    cont_seconds_stop++;
    uint8_t pir_state = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1);

    if (pir_state == GPIO_PIN_RESET) {
        SSD1306_GotoXY(25, 25);
        SSD1306_Puts("PIR NEGATIVO", &Font_7x10, 1);
        SSD1306_UpdateScreen();
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);

        if (cont_seconds_stop == 10) {
            Servo_Sweep(SERVO_MIN, SERVO_MAX);
        }

        if (cont_seconds_stop == 20) {
            Servo_Sweep(SERVO_MAX, SERVO_MIN);
            cont_seconds_stop = 0;
        }
    } else {
        cont_seconds_stop = 0;
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
        SSD1306_GotoXY(25, 25);
        SSD1306_Puts("PIR POSITIVO", &Font_7x10, 1);
        SSD1306_UpdateScreen();
        HAL_Delay(1000);
    }
}
