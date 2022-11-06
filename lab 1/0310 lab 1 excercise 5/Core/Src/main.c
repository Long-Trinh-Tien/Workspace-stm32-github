/* USER CODE BEGIN Header */
// Trinh Tien Long, Student Login.
// MICROPROCESSORS-MICROCONTROLLERS (LAB) (CO3010) _ Mr. Nguyen
// Date: 30/10/2022
// Lab 1
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "led7.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
void vertical_GreenLightOn(void);
void vertical_GreenLightOff(void);
void vertical_YellowLightOn(void);
void vertical_YellowLightOff(void);
void horizontal_GreenLightOn(void);
void horizontal_GreenLightOff(void);
void horizontal_YellowLightOn(void);
void horizontal_YellowLightOff(void);
void StartTheLight();
/* USER CODE BEGIN PFP */
//#define
//#define
//#define
//#define
//#define
//#define
#define	RED_TIMING	5
#define YELLOW_TIMING	2
#define	GREEN_TIMING	3
static int32_t countVertical = GREEN_TIMING;//initial status: Vertical green light start
static int32_t RedCountDown=RED_TIMING;
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void StartTheLight()
{
	//OFF everything
	HAL_GPIO_WritePin(LED_RED_Horizontal_GPIO_Port	, LED_RED_Horizontal_Pin, 0);
	HAL_GPIO_WritePin(LED_YELLOW_Horizontal_GPIO_Port, LED_YELLOW_Horizontal_Pin, 0);
	HAL_GPIO_WritePin(LED_GREEN_Horizontal_GPIO_Port, LED_GREEN_Horizontal_Pin, 0);
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, 0);
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, 0);
	HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, 0);
}

// VERTICAL GREEN ON-OFF
void vertical_GreenLightOn()
{
	HAL_GPIO_WritePin(LED_RED_Horizontal_GPIO_Port	, LED_RED_Horizontal_Pin, 1);//Turn horizontal red light on
	HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, 1);
	display7SEG(countVertical);
	HAL_Delay(1000);
	if(countVertical>=1)
	{
		countVertical--;
	}
}

void vertical_GreenLightOff()
{
	HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, 0);
}


//VERTICAL YELLOW ON-OFF
void vertical_YellowLightOn()
{
	HAL_GPIO_WritePin(LED_RED_Horizontal_GPIO_Port	, LED_RED_Horizontal_Pin, 1);//Turn horizontal red light on
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, 1);
	display7SEG(countVertical);
	HAL_Delay(1000);
	if(countVertical>=1)
	{
		countVertical--;
	}
}
void vertical_YellowLightOff()
{
	HAL_GPIO_WritePin(LED_RED_Horizontal_GPIO_Port	, LED_RED_Horizontal_Pin, 0);//Turn horizontal red light on
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, 0);
}

//HORIZONTAL GREEN ON-OFF
void horizontal_GreenLightOn(void)
{
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, 1);
	HAL_GPIO_WritePin(LED_GREEN_Horizontal_GPIO_Port, LED_GREEN_Horizontal_Pin, 1);
//	display7SEG(countVertical);
	HAL_Delay(1000);
	if(countVertical>=1)
	{
		countVertical--;
	}
}
void horizontal_GreenLightOff(void)
{
	HAL_GPIO_WritePin(LED_GREEN_Horizontal_GPIO_Port, LED_GREEN_Horizontal_Pin, 0);
}

//HORIZONTAL YELLOW ON-OFF
void horizontal_YellowLightOn(void)
{
	HAL_GPIO_WritePin(LED_RED_GPIO_Port	, LED_RED_Pin, 1);//Turn horizontal red light on
	HAL_GPIO_WritePin(LED_YELLOW_Horizontal_GPIO_Port, LED_YELLOW_Horizontal_Pin, 1);
//	display7SEG(countVertical);
	HAL_Delay(1000);
	if(countVertical>=1)
	{
		countVertical--;
	}
}
void horizontal_YellowLightOff(void)
{
	HAL_GPIO_WritePin(LED_RED_GPIO_Port	, LED_RED_Pin, 0);//Turn horizontal red light on
	HAL_GPIO_WritePin(LED_YELLOW_Horizontal_GPIO_Port, LED_YELLOW_Horizontal_Pin, 0);
}
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
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
	StartTheLight();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
//vertical process - horizontal red always on
	  while(countVertical!=0)
	  {
		  vertical_GreenLightOn();
	  }
	  vertical_GreenLightOff();
	  countVertical=YELLOW_TIMING;

	  while(countVertical!=0)
	  {
		  vertical_YellowLightOn();
	  }
	  vertical_YellowLightOff();
	  countVertical=GREEN_TIMING;


//horizontal process - vertical red always on
	  while(countVertical!=0)
	  {
		  display7SEG(RedCountDown);//show count down number on vertical
		  horizontal_GreenLightOn();
		  if(RedCountDown >=1)
		  {
			  RedCountDown--;
		  }
	  }
	  horizontal_GreenLightOff();
	  countVertical=YELLOW_TIMING;

	  while(countVertical!=0)
	  {
		  display7SEG(RedCountDown);////show count down number on vertical
		  horizontal_YellowLightOn();
		  if(RedCountDown >=1)
		  {
			  RedCountDown--;
		  }
	  }
	  horizontal_YellowLightOff();
	  countVertical=GREEN_TIMING;
	  RedCountDown=RED_TIMING;
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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
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

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
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
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_RED_Pin|LED_YELLOW_Pin|LED_GREEN_Pin|LED_RED_Horizontal_Pin
                          |LED_YELLOW_Horizontal_Pin|LED_GREEN_Horizontal_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, Label_A_Pin|Label_B_Pin|Label_C_Pin|Label_D_Pin
                          |Label_E_Pin|Label_F_Pin|Label_G_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_RED_Pin LED_YELLOW_Pin */
  GPIO_InitStruct.Pin = LED_RED_Pin|LED_YELLOW_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : LED_GREEN_Pin LED_RED_Horizontal_Pin LED_YELLOW_Horizontal_Pin LED_GREEN_Horizontal_Pin */
  GPIO_InitStruct.Pin = LED_GREEN_Pin|LED_RED_Horizontal_Pin|LED_YELLOW_Horizontal_Pin|LED_GREEN_Horizontal_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : Label_A_Pin Label_B_Pin Label_C_Pin Label_D_Pin
                           Label_E_Pin Label_F_Pin Label_G_Pin */
  GPIO_InitStruct.Pin = Label_A_Pin|Label_B_Pin|Label_C_Pin|Label_D_Pin
                          |Label_E_Pin|Label_F_Pin|Label_G_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
