/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h" // change this here and inside LiquidCrystal library accordingly
#include "LiquidCrystal.h"

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
RTC_HandleTypeDef hrtc;
typedef unsigned char byte;
int s,m,h,a,d,state,state1,state2,dg,cnt;
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_RTC_Init(void);
//static void MX_NVIC_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void lcdnumber0(int startposition)
{
    setCursor(startposition+0,0);
    print("0");

}
void lcdnumber1(int startposition)
{
    setCursor(startposition+0,0);
    write((0));

}
void lcdnumber2(int startposition)
{
    setCursor(startposition+0,0);
    write((1));

}
void lcdnumber3(int startposition)
{
    setCursor(startposition+0,0);
    write((2));

}
void lcdnumber4(int startposition)
{
    setCursor(startposition+0,0);
    print("8");

}
void lcdnumber5(int startposition)
{
    setCursor(startposition+0,0);
    write((3));  //5

}
void lcdnumber6(int startposition)
{
    setCursor(startposition+0,0);
    write((5));

}
void lcdnumber7(int startposition)
{
    setCursor(startposition+0,0);
    write((4));

}
void lcdnumber8(int startposition)
{
    setCursor(startposition+0,0);
    write((6));

}
void lcdnumber9(int startposition)
{
    setCursor(startposition+0,0);
    write((7));

}
  void numberprinter(int num , int pos)
{
  if(num == 0)
  {
    lcdnumber0(pos);
  }
  if(num == 1)
  {
    lcdnumber1(pos);
  }
  if(num == 2)
  {
    lcdnumber2(pos);
  }
  if(num == 3)
  {
    lcdnumber3(pos);
  }
  if(num == 4)
  {
    lcdnumber4(pos);
  }
  if(num == 5)
  {
    lcdnumber5(pos);
  }
  if(num == 6)
  {
    lcdnumber6(pos);
  }
  if(num == 7)
  {
    lcdnumber7(pos);
  }
  if(num == 8)
  {
    lcdnumber8(pos);
  }
  if(num == 9)
  {
    lcdnumber9(pos);
  }//serial.begin(9600);      
}  

    byte C0[8] = {0x10,0x08,0x04,0x02,0x01,0x02,0x1C,0x18}; //1
    byte C1[8] = {0x1E,0x01,0x01,0x06,0x18,0x04,0x02,0x01}; //2
    byte C2[8] = {0x0E,0x0E,0x01,0x11,0x11,0x11,0x0A,0x04}; //3
    byte C3[8] = {0x1F,0x12,0x14,0x17,0x11,0x11,0x1F,0x0E}; //5
    byte C5[8] = {0x11,0x12,0x14,0x13,0x11,0x11,0x0A,0x04}; //6
    byte C4[8] = {0x1F,0x11,0x11,0x1F,0x01,0x01,0x01,0x01}; //7
    byte C6[8] = {0x10,0x10,0x10,0x1F,0x1E,0x11,0x1F,0x1F}; //8
    byte C7[8] = {0x10,0x10,0x0C,0x02,0x01,0x1D,0x13,0x01}; //9
		
		// ISR Required by the library (for HAL_Delay)
void SysTick_Handler(void);
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
void SysTick_Handler(void);
	
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
  MX_RTC_Init();

  /* Initialize interrupts */
//  MX_NVIC_Init();
  /* USER CODE BEGIN 2 */
LiquidCrystal(GPIOB, GPIO_PIN_2, GPIO_PIN_1, GPIO_PIN_3, GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_6, GPIO_PIN_7);
	
  // create a new character
  createChar(0, C0);  //1
  // create a new character
  createChar(1, C1);  //2
  // create a new character
  createChar(2, C2); //3
  // create a new character
  createChar(3, C3);  //5
  // create a new character
  createChar(4, C4);  //7
  createChar(5, C5);  //6
  createChar(6, C6);  //8
  createChar(7, C7);  //9
	
	state=1;
  state1=1;
  state2=1;
	s=0;
  m=0;
  h=0;
  a=0;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
//if(digitalRead(8)&&state==1)
		setCursor(0, 1);
    write(cnt);
		
		if(cnt==0)
		{
			 setCursor(1, 1);
       print(":DISPLAY TIME");
			 setCursor(14, 1);
       print(" ");
		}
		
		
	if(cnt==1)
		{
			 setCursor(1, 1);
       print(":CHANGE MINUTE");
		}
		
	if(cnt==2)
		{
			 setCursor(1, 1);
       print(":CHANGE HOUR");
			 setCursor(13, 1);
       print("  ");
		}
		if(cnt==3)
		{
			 setCursor(1, 1);
       print(":CHANGE AM-PM");
			 setCursor(14, 1);
       print(" ");
		}
	if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_1)==GPIO_PIN_RESET && state==1)
{
    cnt++;
    state=0;
	  setCursor(0, 1);
    write(cnt);
	
    if(cnt>3){
      cnt=0;
			setCursor(0, 1);
      write(cnt);
      }
    }//else if(!digitalRead(8)&&state==0)
else if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_1)!=GPIO_PIN_RESET && state==0)
		
		{
    state=1;
    }

//if(digitalRead(9)&&state1==1)
if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_2)==GPIO_PIN_RESET && state==1)	
{
    dg=1;
    state1=0;
     
    }
//else if(!digitalRead(9)&&state1==0)
else if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_2)!=GPIO_PIN_RESET && state==0)
	
{
    state1=1;
    }

//if(digitalRead(10)&&state2==1)
if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_3)==GPIO_PIN_RESET && state==1)	
	
{
     dg=-1;
     state2=0;
    }

//	else if(!digitalRead(10)&state2==0)
	else if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_3)!=GPIO_PIN_RESET && state==0)
	
	{
    state2=1;
    }
    
	switch(cnt)
		{
   case 1:
      m=m+dg;
      dg=0; 
   if(m>59)
		 {
    m=59;
		 }
    if(m<0)
			{
    m=0;
			}
	break;
     
  case 2:
      h=h+dg;
      dg=0;
	
      if(h>11)
				{
       h=11;
				}
    if(h<0)
			{
    h=0;
			}
   break;
			
  case 3:
     if(dg==1){
    a=1;
    dg=0;}
     if(dg==-1){
    a=0;
    dg=0;}
    break;
      }
  if(s>59){
    s=0;
    m++;
  
  if(m>59){
    m=0;
   h++;
  
  if(h>11){
    h=0;            //12 Hour Format
    a=!a;
  } 
  }
  }
	
  d=h%10;
  numberprinter(d, 4);
  d=h/10;
  numberprinter(d, 3);
	
  d=m%10;
  numberprinter(d, 7);
  d=m/10;
  numberprinter(d, 6);
	
	
  d=s%10;
  numberprinter(d, 10);
  d=s/10;
  numberprinter(d, 9);
	
  setCursor(14, 0);
  if(a){
       print("AM");
      
	}
	else{
       print("PM");
        
	}
    
	if(cnt==0){
           s++;
         setCursor(5, 0);
         print(" ");
        setCursor(8, 0);
        print(" ");

      HAL_Delay(1000);
      setCursor(5, 0);
      print(":");
      setCursor(8, 0);
      print(":");

       }
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
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_LSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI_DIV2;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_RTC;
  PeriphClkInit.RTCClockSelection = RCC_RTCCLKSOURCE_LSI;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief NVIC Configuration.
  * @retval None
  */
static void MX_NVIC_Init(void)
{
  /* PVD_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(PVD_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(PVD_IRQn);
  /* FLASH_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(FLASH_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(FLASH_IRQn);
  /* RCC_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(RCC_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(RCC_IRQn);
}

/**
  * @brief RTC Initialization Function
  * @param None
  * @retval None
  */
static void MX_RTC_Init(void)
{

  /* USER CODE BEGIN RTC_Init 0 */

  /* USER CODE END RTC_Init 0 */

  RTC_TimeTypeDef sTime = {0};
  RTC_DateTypeDef DateToUpdate = {0};

  /* USER CODE BEGIN RTC_Init 1 */

  /* USER CODE END RTC_Init 1 */
  /** Initialize RTC Only
  */
  hrtc.Instance = RTC;
  hrtc.Init.AsynchPrediv = RTC_AUTO_1_SECOND;
  hrtc.Init.OutPut = RTC_OUTPUTSOURCE_NONE;
  if (HAL_RTC_Init(&hrtc) != HAL_OK)
  {
    Error_Handler();
  }

  /* USER CODE BEGIN Check_RTC_BKUP */

  /* USER CODE END Check_RTC_BKUP */

  /** Initialize RTC and set the Time and Date
  */
  sTime.Hours = 0;
  sTime.Minutes = 0;
  sTime.Seconds = 0;

  if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN) != HAL_OK)
  {
    Error_Handler();
  }
  DateToUpdate.WeekDay = RTC_WEEKDAY_MONDAY;
  DateToUpdate.Month = RTC_MONTH_JANUARY;
  DateToUpdate.Date = 1;
  DateToUpdate.Year = 0;

  if (HAL_RTC_SetDate(&hrtc, &DateToUpdate, RTC_FORMAT_BIN) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN RTC_Init 2 */

  /* USER CODE END RTC_Init 2 */

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
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2|GPIO_PIN_1|GPIO_PIN_3|GPIO_PIN_4
                          |GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_RESET);

  /*Configure GPIO pins : PC1 PC2 PC3 */
  GPIO_InitStruct.Pin = GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

//  /*Configure GPIO pin : PB1 */
//  GPIO_InitStruct.Pin = GPIO_PIN_1;
//  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
//  GPIO_InitStruct.Pull = GPIO_NOPULL;
//  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
//  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PB2 PB3 PB4 PB5
                           PB6 PB7 */
  GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_1|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5
                          |GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
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
