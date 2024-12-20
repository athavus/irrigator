# timer_display.h

Este arquivo define as funções e protótipos para o controle e atualização do display de tempo utilizando o display OLED SSD1306.

## Inclusões de cabeçalho

```c
#include "main.h"
#include "ssd1306.h"
```
- `main.h`: Contém as definições e configurações principais do microcontrolador.
- `ssd1306.h`: Biblioteca para controle do display OLED SSD1306.

## Protótipos das funções

```c
void Timer_Display_Init(void);
void Timer_Display_Update(void);
```
- `Timer_Display_Init`: Inicializa o display e limpa a tela para iniciar a contagem de tempo.
- `Timer_Display_Update`: Atualiza o display com o tempo atual, incrementando segundos, minutos e horas.

## Proteção contra múltiplas inclusões

```c
#ifndef TIMER_DISPLAY_H
#define TIMER_DISPLAY_H
...
#endif /* TIMER_DISPLAY_H */
```
- Garante que o arquivo de cabeçalho seja incluído apenas uma vez durante a compilação, evitando redefinições.

---

# timer_display.c

Este arquivo implementa as funções para inicializar e atualizar o display de tempo no SSD1306.

## Inclusão do cabeçalho

```c
#include "timer_display.h"
#include <stdio.h>
```
- Inclui o arquivo de cabeçalho `timer_display.h` para acessar as definições e protótipos das funções.
- A biblioteca `stdio.h` é usada para formatar e imprimir a string com o tempo no display.

## Variáveis globais estáticas

```c
static int cont_seconds = 0;
static int cont_minutes = 0;
static int cont_hours = 0;
static char buffer[26] = {0};
```
- `cont_seconds`: Contador de segundos.
- `cont_minutes`: Contador de minutos.
- `cont_hours`: Contador de horas.
- `buffer`: String para armazenar o tempo formatado a ser exibido no display.

## Função `Timer_Display_Init`

```c
void Timer_Display_Init(void)
{
    SSD1306_Init();
    SSD1306_Clear();
}
```
- Inicializa o display SSD1306 e limpa a tela, preparando para exibir o tempo.

## Função `Timer_Display_Update`

```c
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
```
- A cada chamada, incrementa o contador de segundos (`cont_seconds`).
- Se os segundos alcançarem 60, incrementa os minutos e reseta os segundos.
- Se os minutos alcançarem 60, incrementa as horas e reseta os minutos.
- Se as horas alcançarem 24, reseta as horas para 0.

```c
    SSD1306_Clear();
    SSD1306_GotoXY(25, 5);

    sprintf(buffer, "%02d:%02d:%02d", cont_hours, cont_minutes, cont_seconds);
    SSD1306_Puts(buffer, &Font_11x18, 1);
    SSD1306_UpdateScreen();
}
```
- Limpa o display e posiciona o cursor na posição `(25, 5)`.
- Usa `sprintf` para formatar a string de tempo (`HH:MM:SS`).
- Exibe o tempo formatado no display e atualiza a tela.

## Documentação Detalhada do Código

- [main](documentation/main.md)
- [pir_control](documentation/pir_control.md)
- [servo_control](documentation/servo_control.md)
- [timer_display](documentation/timer_display.md)