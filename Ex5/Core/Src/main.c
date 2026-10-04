/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
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

/* USER CODE BEGIN PV */
int count = 0;
int timer_1 = 0;
int timer_2 = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

// Mã 7 đoạn Anode chung (0: BẬT, 1: TẮT)
uint8_t seg_code[10] = {
    0x40, // 0
    0x79, // 1
    0x24, // 2
    0x30, // 3
    0x19, // 4
    0x12, // 5
    0x02, // 6
    0x78, // 7
    0x00, // 8
    0x10  // 9
};

void display7SEG_1(int num) {
    if (num >= 0 && num <= 9) {
        uint8_t code = seg_code[num];
        HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, (code & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
        HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, (code & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET);
        HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, (code & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET);
        HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, (code & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET);
        HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, (code & 0x10) ? GPIO_PIN_SET : GPIO_PIN_RESET);
        HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, (code & 0x20) ? GPIO_PIN_SET : GPIO_PIN_RESET);
        HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, (code & 0x40) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    }
}

void display7SEG_2(int num) {
    if (num >= 0 && num <= 9) {
        uint8_t code = seg_code[num];
        HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, (code & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
        HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, (code & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET);
        HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, (code & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET);
        HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, (code & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET);
        HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, (code & 0x10) ? GPIO_PIN_SET : GPIO_PIN_RESET);
        HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, (code & 0x20) ? GPIO_PIN_SET : GPIO_PIN_RESET);
        HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, (code & 0x40) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    }
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
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
      if (count < 3)
      {
        // [0s, 1s, 2s]: Hướng 1 ĐỎ | Hướng 2 XANH
        HAL_GPIO_WritePin(Red_1_GPIO_Port, Red_1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(Yellow_1_GPIO_Port, Yellow_1_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(Green_1_GPIO_Port, Green_1_Pin, GPIO_PIN_SET);

        HAL_GPIO_WritePin(Red_2_GPIO_Port, Red_2_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(Yellow_2_GPIO_Port, Yellow_2_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(Green_2_GPIO_Port, Green_2_Pin, GPIO_PIN_RESET);

        timer_1 = 5 - count;
        timer_2 = 3 - count;
      }
      else if (count < 5)
      {
        // [3s, 4s]: Hướng 1 ĐỎ | Hướng 2 VÀNG
        HAL_GPIO_WritePin(Red_1_GPIO_Port, Red_1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(Yellow_1_GPIO_Port, Yellow_1_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(Green_1_GPIO_Port, Green_1_Pin, GPIO_PIN_SET);

        HAL_GPIO_WritePin(Red_2_GPIO_Port, Red_2_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(Yellow_2_GPIO_Port, Yellow_2_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(Green_2_GPIO_Port, Green_2_Pin, GPIO_PIN_SET);

        timer_1 = 5 - count;
        timer_2 = 5 - count;
      }
      else if (count < 8)
      {
        // [5s, 6s, 7s]: Hướng 1 XANH | Hướng 2 ĐỎ
        HAL_GPIO_WritePin(Red_1_GPIO_Port, Red_1_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(Yellow_1_GPIO_Port, Yellow_1_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(Green_1_GPIO_Port, Green_1_Pin, GPIO_PIN_RESET);

        HAL_GPIO_WritePin(Red_2_GPIO_Port, Red_2_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(Yellow_2_GPIO_Port, Yellow_2_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(Green_2_GPIO_Port, Green_2_Pin, GPIO_PIN_SET);

        timer_1 = 8 - count;
        timer_2 = 10 - count;
      }
      else
      {
        // [8s, 9s]: Hướng 1 VÀNG | Hướng 2 ĐỎ
        HAL_GPIO_WritePin(Red_1_GPIO_Port, Red_1_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(Yellow_1_GPIO_Port, Yellow_1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(Green_1_GPIO_Port, Green_1_Pin, GPIO_PIN_SET);

        HAL_GPIO_WritePin(Red_2_GPIO_Port, Red_2_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(Yellow_2_GPIO_Port, Yellow_2_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(Green_2_GPIO_Port, Green_2_Pin, GPIO_PIN_SET);

        timer_1 = 10 - count;
        timer_2 = 10 - count;
      }

      display7SEG_1(timer_1);
      display7SEG_2(timer_2);

      HAL_Delay(1000);

      count++;
      if (count >= 10)
      {
        count = 0;
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
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, Red_1_Pin|Yellow_1_Pin|Green_1_Pin|Red_2_Pin
                          |Yellow_2_Pin|Green_2_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, a1_Pin|b1_Pin|c1_Pin|d1_Pin|e1_Pin|f1_Pin|g1_Pin
                          |a2_Pin|b2_Pin|c2_Pin|d2_Pin|e2_Pin|f2_Pin|g2_Pin, GPIO_PIN_SET);

  /*Configure GPIO pins : Red_1_Pin Yellow_1_Pin Green_1_Pin Red_2_Pin
                           Yellow_2_Pin Green_2_Pin */
  GPIO_InitStruct.Pin = Red_1_Pin|Yellow_1_Pin|Green_1_Pin|Red_2_Pin
                          |Yellow_2_Pin|Green_2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : a1_Pin b1_Pin c1_Pin d1_Pin e1_Pin f1_Pin g1_Pin
                           a2_Pin b2_Pin c2_Pin d2_Pin e2_Pin f2_Pin g2_Pin */
  GPIO_InitStruct.Pin = a1_Pin|b1_Pin|c1_Pin|d1_Pin|e1_Pin|f1_Pin|g1_Pin
                          |a2_Pin|b2_Pin|c2_Pin|d2_Pin|e2_Pin|f2_Pin|g2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

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
#ifdef USE_FULL_ASSERT
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
