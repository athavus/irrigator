#ifndef SERVO_CONTROL_H
#define SERVO_CONTROL_H

#include "main.h"

void Servo_Init(void);
void Servo_SetPosition(uint32_t position);
void Servo_Sweep(uint32_t start_pos, uint32_t end_pos);

#endif /* SERVO_CONTROL_H */
