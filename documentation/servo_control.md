# servo_control.h

Este arquivo define as funções e protótipos para o controle de um servo motor usando PWM (Pulse Width Modulation) no microcontrolador.

## Protótipos das funções

```c
void Servo_Init(void);
void Servo_SetPosition(uint32_t position);
void Servo_Sweep(uint32_t start_pos, uint32_t end_pos);
```
- `Servo_Init`: Inicializa o controle PWM do servo motor.
- `Servo_SetPosition`: Define a posição do servo motor com base no valor do PWM.
- `Servo_Sweep`: Move o servo motor suavemente entre duas posições (inicial e final).

## Proteção contra múltiplas inclusões

```c
#ifndef SERVO_CONTROL_H
#define SERVO_CONTROL_H
...
#endif /* SERVO_CONTROL_H */
```
- Garante que o arquivo de cabeçalho seja incluído apenas uma vez durante a compilação, evitando redefinições.

---

# servo_control.c

Este arquivo implementa as funções para controlar o servo motor usando PWM (Pulse Width Modulation).

## Inclusão do cabeçalho

```c
#include "servo_control.h"
```
- Inclui o arquivo de cabeçalho `servo_control.h` para acessar as definições e protótipos das funções.

## Variáveis externas

```c
extern TIM_HandleTypeDef htim2;
```
- `htim2`: Handler do temporizador (timer) utilizado para gerar o sinal PWM no servo motor.

## Função `Servo_Init`

```c
void Servo_Init(void)
{
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
}
```
- Inicializa o temporizador `htim2` e começa a gerar o sinal PWM no canal 1, permitindo o controle do servo motor.

## Função `Servo_SetPosition`

```c
void Servo_SetPosition(uint32_t position)
{
    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, position);
    HAL_Delay(50);
}
```
- Ajusta a posição do servo motor configurando o valor de comparação do temporizador, que controla o ciclo de trabalho (duty cycle) do PWM.
- A função `HAL_Delay(50)` adiciona um pequeno atraso para garantir que a posição seja atingida.

## Função `Servo_Sweep`

```c
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
```
- Move o servo motor suavemente de `start_pos` para `end_pos`, ajustando a posição em pequenos passos.
- O ciclo de movimento pode ser realizado em ambas as direções (do menor para o maior valor ou vice-versa).
- Após completar o movimento, a função espera 1 segundo (`HAL_Delay(1000)`).

## Documentação Detalhada do Código

- [main](documentation/main.md)
- [pir_control](documentation/pir_control.md)
- [servo_control](documentation/servo_control.md)
- [timer_display](documentation/timer_display.md)