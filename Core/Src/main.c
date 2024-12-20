/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include "ssd1306.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define SERVO_MIN 50
#define SERVO_MAX 100
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;

TIM_HandleTypeDef htim2;
<<<<<<< Updated upstream:capacitacao_embarcados/nucleo-f446re/irrigator-final/Core/Src/main.c

UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */
=======
TIM_HandleTypeDef htim3;

/* USER CODE BEGIN PV */
uint16_t tempdht11, umidht11;
>>>>>>> Stashed changes:capacitacao_embarcados/nucleo-f446re/irrigator/Core/Src/main.c
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_TIM2_Init(void);
<<<<<<< Updated upstream:capacitacao_embarcados/nucleo-f446re/irrigator-final/Core/Src/main.c
static void MX_I2C1_Init(void);
=======
static void MX_TIM3_Init(void);
>>>>>>> Stashed changes:capacitacao_embarcados/nucleo-f446re/irrigator/Core/Src/main.c
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
<<<<<<< Updated upstream:capacitacao_embarcados/nucleo-f446re/irrigator-final/Core/Src/main.c
=======
void dht11(uint16_t *temperatura, uint16_t *umidade)
{
	//Variáveis para execução de cálculos da função.
	uint16_t tempcalc, umidcalc;

	//Configurações para seleção da direção do Pino 'dht11' como saída digital:
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = GPIO_PIN_8;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	//Sinal em nivel lógico 0 - Conforme Datasheet.
	HAL_GPIO_WritePin(GPIOA, dht11_Pin, GPIO_PIN_RESET);

	//Tempo mínimo de 18ms - Conforme Datasheet.
	HAL_Delay(20); //Configura para 20ms

	//Sinal em nivel lógico 1 - Conforme Datasheet.
	HAL_GPIO_WritePin(GPIOA, dht11_Pin, GPIO_PIN_SET);

	//Configurações para seleção da direção do Pino 'dht11' como entrada digital:
	GPIO_InitStruct.Pin = GPIO_PIN_8;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	//Lógica Principal:
	//Seta contador Timer 2 para 0.
	__HAL_TIM_SET_COUNTER(&htim3, 0);

	//Variáveis Auxiliares.
	uint16_t ler[2];
	uint16_t dados[42];
	uint8_t bits[40];
	uint16_t temph = 0;
	uint16_t umidh = 0;

	//Lógica Para Captura do Tempo Alto dos Dados.
	for(int i = 0; i < 42; i++)
	{
		while(HAL_GPIO_ReadPin(GPIOA, dht11_Pin) == GPIO_PIN_RESET);
		ler[0] = __HAL_TIM_GET_COUNTER(&htim3);
		while(HAL_GPIO_ReadPin(GPIOA, dht11_Pin) == GPIO_PIN_SET);
		ler[1] = __HAL_TIM_GET_COUNTER(&htim3);
		dados[i] = ler[1] - ler[0];
	}

	//Definindo bits conforme tempos do datasheet.
	for(int i = 0; i < 40; i++)
	{
	    if((dados[i+2] >=20) && (dados[i+2] <=32))
	    {
		    bits[i] = 0;
	    }
	    else if((dados[i+2] >=65) && (dados[i+2] <=75))
	    {
		    bits[i] = 1;
	    }
	}

	//Cálculo da temperatura e umidade determinado pelos bits.
	for(int i = 0; i < 8; i++)
	{
	    temph += bits[i+16] << (7 - i);
	    umidh += bits[i] << (7 - i);
	}

	//Atribuição dos valores calculados nas variáveis
	tempcalc = temph;
	umidcalc = umidh;
	*temperatura = tempcalc;
	*umidade = umidcalc;
}
>>>>>>> Stashed changes:capacitacao_embarcados/nucleo-f446re/irrigator/Core/Src/main.c
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_TIM2_Init();
<<<<<<< Updated upstream:capacitacao_embarcados/nucleo-f446re/irrigator-final/Core/Src/main.c
  MX_I2C1_Init();
  /* USER CODE BEGIN 2 */
=======
  MX_TIM3_Init();
  /* USER CODE BEGIN 2 */

>>>>>>> Stashed changes:capacitacao_embarcados/nucleo-f446re/irrigator/Core/Src/main.c
  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
  HAL_TIM_Base_Start(&htim3);
  dht11(&tempdht11, &umidht11);
  char buffer[20];
	SSD1306_Init();
<<<<<<< Updated upstream:capacitacao_embarcados/nucleo-f446re/irrigator-final/Core/Src/main.c

  int cont_seconds = 0;
  int cont_minutes = 0;
  int cont_hours = 0;
  int cont_seconds_stop = 0;

  char buffer[26] = {0};
=======
	SSD1306_Clear();
	SSD1306_GotoXY(20, 25);
	sprintf(buffer, "Temp: %d C", tempdht11);
	SSD1306_Puts(buffer, &Font_7x10, 1);
	SSD1306_GotoXY(20, 45);
	sprintf(buffer, "Humid: %d%%", umidht11);
	SSD1306_Puts(buffer, &Font_7x10, 1);
	SSD1306_UpdateScreen();
>>>>>>> Stashed changes:capacitacao_embarcados/nucleo-f446re/irrigator/Core/Src/main.c
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
  	cont_seconds++;
  	cont_seconds_stop++;

  	SSD1306_Clear();
		SSD1306_GotoXY(25, 5);

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

		sprintf(buffer, "%02d:%02d:%02d",
				cont_hours,
				cont_minutes,
				cont_seconds);

		SSD1306_UpdateScreen();

		SSD1306_Puts(buffer, &Font_11x18, 1);

		uint32_t duty;

  	uint8_t pir_state = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1);

		if (pir_state == GPIO_PIN_RESET)
		{
			SSD1306_GotoXY(25, 25);
			SSD1306_Puts("PIR NEGATIVO", &Font_7x10, 1);
			SSD1306_UpdateScreen();
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);

			if (cont_seconds_stop == 10) {
				for (duty = SERVO_MIN; duty <= SERVO_MAX; duty++)
				{
					__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, duty);
					HAL_Delay(50);
				}

				HAL_Delay(1000);
			}

			if (cont_seconds_stop == 20) {
				for (duty = SERVO_MAX; duty >= SERVO_MIN; duty--)
				{
					__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, duty);
					HAL_Delay(50);
				}

				cont_seconds_stop = 0;
				HAL_Delay(1000);
			}
		} else {
			cont_seconds_stop = 0;

			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
			SSD1306_GotoXY(25, 25);
			SSD1306_Puts("PIR POSITIVO", &Font_7x10, 1);
			SSD1306_UpdateScreen();
			HAL_Delay(1000);
		}
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 150;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 400000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 1680-1;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 1000-1;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */
  HAL_TIM_MspPostInit(&htim2);

}

/**
<<<<<<< Updated upstream:capacitacao_embarcados/nucleo-f446re/irrigator-final/Core/Src/main.c
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */
=======
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 75-1;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 65535;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */
>>>>>>> Stashed changes:capacitacao_embarcados/nucleo-f446re/irrigator/Core/Src/main.c

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(dht11_GPIO_Port, dht11_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

<<<<<<< Updated upstream:capacitacao_embarcados/nucleo-f446re/irrigator-final/Core/Src/main.c
  /*Configure GPIO pin : pir_hc_sr501_Pin */
  GPIO_InitStruct.Pin = pir_hc_sr501_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(pir_hc_sr501_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LD2_Pin dht11_Pin */
  GPIO_InitStruct.Pin = LD2_Pin|dht11_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
=======
  /*Configure GPIO pins : USART_TX_Pin USART_RX_Pin */
  GPIO_InitStruct.Pin = USART_TX_Pin|USART_RX_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : LD2_Pin */
  GPIO_InitStruct.Pin = LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : dht11_Pin */
  GPIO_InitStruct.Pin = dht11_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(dht11_GPIO_Port, &GPIO_InitStruct);
>>>>>>> Stashed changes:capacitacao_embarcados/nucleo-f446re/irrigator/Core/Src/main.c

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
