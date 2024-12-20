# Irrigador com Sensor de Presença

## Descrição do Projeto
Este projeto é um sistema embarcado desenvolvido para STM32 que integra um display OLED, um sensor PIR de presença e um servo motor. O sistema funciona como um timer digital que exibe as horas no display OLED e reage a detecções de presença, controlando um servo motor em resposta. Simulando um irrigador de campo aberto no qual assim que alguém é detectado, para de girar o servo motor.

## Funcionalidades

### Cronômetro Digital
* Exibição de um cronômetro no formato HH:MM:SS
* Display OLED SSD1306 para interface visual
* Contagem contínua com reset automático a cada 24 horas

### Detecção de Presença
* Sensor PIR para detecção de movimento
* Indicação visual no display do estado do sensor
* LED indicador de status (GPIO PA5)

### Controle de Servo Motor
* Aguarda área livre (sem pessoas)
* Inicia ciclo de irrigação com varredura completa
* Retorna à posição inicial
* Possui sistema de segurança que interrompe se detectar pessoas

## Hardware Necessário
* Microcontrolador STM32
* Display OLED SSD1306
* Sensor PIR HC-SR501
* Servo Motor 
* LED (conectado ao GPIO PA5)
* Interface I2C para comunicação com display

## Conexões
* Display OLED: I2C1 | SDA E SCL
* Servo Motor: Timer 2, Canal 1 | GPIO PA0
* Sensor PIR: GPIO PA1
* LED Indicador: GPIO PA5

## Configuração do Projeto
* IDE: STM32CubeIDE
* Timer PWM configurado para controle do servo
* I2C configurado para comunicação com display OLED (necessário o include path da biblioteca do display i2c, presente na pasta Drivers)
* GPIO configurado para leitura do sensor PIR e controle do LED

## Estrutura do Código
O projeto está organizado em módulos para melhor manutenção e legibilidade, naturalmente, basta utilizar o git clone para utilizar da mesma estrutura:

```
├── Core
│   ├── Inc
│   │   ├── main.h
│   │   ├── timer_display.h
│   │   ├── servo_control.h
│   │   └── pir_control.h
│   │   └── ...outros_arquivos
│   └── Src
│       ├── main.c
│       ├── timer_display.c
│       ├── servo_control.c
│       └── pir_control.c
│       └── ...outros_arquivos
```

## Como Usar

1. Clone o repositório
2. Abra o projeto no STM32CubeIDE
3. Compile e faça o upload para seu dispositivo STM32
4. O sistema iniciará automaticamente com:
   * Display mostrando o timer
   * Monitoramento contínuo do sensor PIR
   * Controle automático do servo motor baseado na detecção

## Configurações Personalizáveis

```c
#define SERVO_MIN 50  // Posição mínima do servo
#define SERVO_MAX 100 // Posição máxima do servo
```

## Detalhes de Implementação
* O timer é atualizado continuamente no loop principal
* O sensor PIR é verificado a cada ciclo
* O servo motor é controlado por PWM através do Timer 2
* O display é atualizado via I2C para mostrar o tempo e status

## Limitações e Considerações
* O sistema requer calibração do sensor PIR para o ambiente
* As posições do servo podem precisar de ajustes dependendo do modelo usado

## Melhorias Futuras Possíveis
1. Melhorias no Sistema de Detecção
2. Otimização de Energia
3. Implementar diferentes modos de operação (dia/noite)
4. Detecção de travamento ou sobrecarga no servo
5. Armazenamento de configurações em memória não-volátil

## Contribuições
Qualquer tipo de comentário é bem vindo, sinta-se a vontade para:
* Reportar bugs
* Sugerir melhorias
* Abrir issues!
