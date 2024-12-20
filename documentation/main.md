# main.c

## Inclusões de cabeçalho

```c
#include <stdio.h>
#include "ssd1306.h"
#include "timer_display.h"
#include "servo_control.h"
#include "pir_control.h"
```
- `stdio.h`: Biblioteca padrão para entrada e saída, necessária para operações como `printf`.
- `ssd1306.h`: Biblioteca para controle do display OLED SSD1306.
- `timer_display.h`: Biblioteca para controle e atualização do display com o timer.
- `servo_control.h`: Biblioteca para controle do servo motor.
- `pir_control.h`: Biblioteca para o controle do sensor PIR.

## Funções de Inicialização

```c
Timer_Display_Init();
Servo_Init();
```
- `Timer_Display_Init()`: Inicializa o display de tempo, configurando o temporizador e preparando o display OLED para exibição de informações.
- `Servo_Init()`: Inicializa o controle PWM para o servo motor, permitindo que o sistema controle a posição do servo.

## Loop principal

```c
while (1)
{
    Timer_Display_Update();
    PIR_Process();
}
```
  - `Timer_Display_Update()`: Atualiza o display com o tempo ou outras informações associadas ao temporizador.
  - `PIR_Process()`: Verifica o estado do sensor PIR e executa ações com base no estado (como mover o servo ou atualizar o display).