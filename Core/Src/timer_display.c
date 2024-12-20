#include "timer_display.h"
#include <stdio.h>

static int cont_seconds = 0;
static int cont_minutes = 0;
static int cont_hours = 0;
static char buffer[26] = {0};

void Timer_Display_Init(void)
{
    SSD1306_Init();
    SSD1306_Clear();
}

void Timer_Display_Update(void)
{
    cont_seconds++;

    if (cont_seconds >= 60) {
        cont_minutes++;
        cont_seconds = 0;
    }

    if (cont_minutes >= 60) {
        cont_hours++;
        cont_minutes = 0;
    }

    if (cont_hours >= 24)
        cont_hours = 0;

    SSD1306_Clear();
    SSD1306_GotoXY(25, 5);

    sprintf(buffer, "%02d:%02d:%02d", cont_hours, cont_minutes, cont_seconds);
    SSD1306_Puts(buffer, &Font_11x18, 1);
    SSD1306_UpdateScreen();
}
