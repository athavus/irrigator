# pir_control.h

Este arquivo define os componentes e funções para o controle de um sensor PIR, integrado com um display SSD1306 e um controle de servo motor.

## Inclusões de cabeçalho

```c
#include "main.h"
#include "ssd1306.h"
#include "servo_control.h"
```
- `main.h`: Contém as definições e configurações principais do microcontrolador.
- `ssd1306.h`: Biblioteca para controle do display OLED SSD1306.
- `servo_control.h`: Biblioteca para o controle do servo motor.

## Definições de constantes

```c
#define SERVO_MIN 50
#define SERVO_MAX 100
```
- `SERVO_MIN`: Define o valor mínimo do ângulo do servo motor.
- `SERVO_MAX`: Define o valor máximo do ângulo do servo motor.

## Protótipo da função

```c
void PIR_Process(void);
```
- Declara a função `PIR_Process`, que gerencia o estado do sensor PIR e executa ações relacionadas.

## Proteção contra múltiplas inclusões

```c
#ifndef PIR_CONTROL_H
#define PIR_CONTROL_H
...
#endif /* PIR_CONTROL_H */
```
- Garante que este arquivo seja incluído apenas uma vez durante a compilação, evitando redefinições.

---

# pir_control.c

Este arquivo implementa a lógica para o controle do sensor PIR, display OLED e servo motor.

## Inclusão do cabeçalho

```c
#include "pir_control.h"
```
- Inclui o arquivo de cabeçalho `pir_control.h`, onde estão as definições e protótipos.

## Variáveis globais estáticas

```c
static int cont_seconds_stop = 0;
```
- `cont_seconds_stop`: Contador de segundos para monitorar o tempo que o sensor PIR permanece inativo.

## Função PIR_Process

```c
void PIR_Process(void)
{
    cont_seconds_stop++;
    uint8_t pir_state = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1);
```
- Incrementa `cont_seconds_stop` a cada chamada.
- Lê o estado do sensor PIR no pino `GPIO_PIN_1` da porta `GPIOA`.

```c
    if (pir_state == GPIO_PIN_RESET) {
```
- Verifica se o sensor PIR está inativo (`GPIO_PIN_RESET`).

```c
        SSD1306_GotoXY(25, 25);
        SSD1306_Puts("PIR NEGATIVO", &Font_7x10, 1);
        SSD1306_UpdateScreen();
```
- Exibe "PIR NEGATIVO" no display OLED na posição `(25, 25)`.

```c
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
```
- Liga o pino `GPIO_PIN_5` da porta `GPIOA`, indicando um estado de inatividade.

```c
        if (cont_seconds_stop == 10) {
            Servo_Sweep(SERVO_MIN, SERVO_MAX);
        }

        if (cont_seconds_stop == 20) {
            Servo_Sweep(SERVO_MAX, SERVO_MIN);
            cont_seconds_stop = 0;
        }
```
- Após 10 segundos, move o servo motor de `SERVO_MIN` para `SERVO_MAX`.
- Após 20 segundos, move o servo motor de volta para `SERVO_MIN` e reseta o contador.

```c
    } else {
        cont_seconds_stop = 0;
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
```
- Se o sensor PIR está ativo (`GPIO_PIN_SET`):
  - Reseta `cont_seconds_stop`.
  - Desliga o pino `GPIO_PIN_5` da porta `GPIOA`.

```c
        SSD1306_GotoXY(25, 25);
        SSD1306_Puts("PIR POSITIVO", &Font_7x10, 1);
        SSD1306_UpdateScreen();
        HAL_Delay(1000);
    }
}
```
- Exibe "PIR POSITIVO" no display OLED.
- Atraso de 1 segundo para evitar leituras excessivas.

## Documentação Detalhada do Código

- [main](./main.md)
- [pir_control](./pir_control.md)
- [servo_control](./servo_control.md)
- [timer_display](./timer_display.md)