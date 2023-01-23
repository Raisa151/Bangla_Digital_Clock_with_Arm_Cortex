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
typedef unsigned char byte;
RTC_HandleTypeDef hrtc;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/


/* USER CODE BEGIN PV */
char time[10];


int hourupg;
int minupg;
int menu =0;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_RTC_Init(void);
//static void MX_NVIC_Init(void);
/* USER CODE BEGIN PFP */

void set_time(void)
	
{   
	
  RTC_TimeTypeDef sTime = {0};
  RTC_DateTypeDef DateToUpdate = {0};
	
	
/** Initialize RTC and set the Time and Date
  */
  sTime.Hours = 23;
  sTime.Minutes = 15;
  sTime.Seconds = 00;

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
	
	//HAL_RTCEx_BKUPWrite(&hrtc,RTC_BKP_DR1,0x32F2);
}

void get_time(void)
{
	
	RTC_TimeTypeDef gTime;
	
	HAL_RTC_GetTime(&hrtc,&gTime, RTC_FORMAT_BIN);

	
	sprintf((char*)time, "%02d:%02d:%02d",gTime.Hours,gTime.Minutes ,gTime.Seconds);
	
}

//void display_time(void)
//{
//setCursor(3, 1);
//print(time);
//}

//Character Functions

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

//Character functions
void DisplayTime()		
		//hour-digit2
{  RTC_TimeTypeDef gTime;

	HAL_RTC_GetTime(&hrtc,&gTime, RTC_FORMAT_BIN);
  
	 int d=gTime.Hours%10;
    numberprinter(d, 4);

 
 //hour-digit1
 int d1=gTime.Hours/10;
    numberprinter(d1, 3);

 //minute-digit2 
 int d2=gTime.Minutes%10;
     numberprinter(d2, 7);

 //minute-digit1   
  int d3=gTime.Minutes/10;
     numberprinter(d3, 6);

 //second-digit2
 int  d4=gTime.Seconds%10;
     numberprinter(d4, 10);
      
 //second-digit1     
 int  d5=gTime.Seconds/10;
     numberprinter(d5, 9);
	 }
void firstdigitHourMinus()
	
{
	
	RTC_TimeTypeDef gTime;
 
	HAL_RTC_GetTime(&hrtc,&gTime, RTC_FORMAT_BIN);
	int	d1=(gTime.Hours/10);
	  //HAL_Delay(500);
	int v=d1-1;
	  numberprinter(v, 3);
}
void seconddigitHourMinus()
	
{
	RTC_TimeTypeDef gTime;
 
	HAL_RTC_GetTime(&hrtc,&gTime, RTC_FORMAT_BIN);
	int	d=(gTime.Hours%10);
	  //HAL_Delay(500);
	  
	do{
		HAL_Delay(500);
		d=d-1;
	numberprinter(d, 4);}
while(d!=0);
	  
}
void DisplaySetHour()
{
  RTC_TimeTypeDef gTime;
 
	HAL_RTC_GetTime(&hrtc,&gTime, RTC_FORMAT_BIN);
	int	d=(gTime.Hours%10);   //d1d
	int d1=gTime.Hours/10;
	

while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_2)==GPIO_PIN_RESET)
	{
		
		HAL_Delay(500);
		d++;
	  numberprinter(d, 4);
		//numberprinter(d1, 3);
	};

  
while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_3)==GPIO_PIN_RESET)
	
	{
		HAL_Delay(750);
		seconddigitHourMinus();
		
	};
while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==GPIO_PIN_RESET)
	{
		
		HAL_Delay(500);
		d1++;
	 // numberprinter(d, 4);
		numberprinter(d1, 3);
	};
 while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==GPIO_PIN_RESET)
	
	{
		HAL_Delay(750);
		firstdigitHourMinus();
		
	};
	
	
		setCursor(0,0);
		print("1");
  HAL_Delay(200);
}


void DisplaySetMinute()
	
{ 
	RTC_TimeTypeDef sTime;
	RTC_TimeTypeDef gTime;
 
	HAL_RTC_GetTime(&hrtc,&gTime, RTC_FORMAT_BIN);
	int	d2=(gTime.Minutes%10);   //d3d2
	int d3=gTime.Minutes/10;
	
while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_2)==GPIO_PIN_RESET)
	{
		
		HAL_Delay(750);
		d3++;
	  numberprinter(d3, 6);
		//numberprinter(d2, 7);
	};
	

while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_3)==GPIO_PIN_RESET)
	{
		HAL_Delay(300);
		d2++;
	 // numberprinter(d3, 6);
		numberprinter(d2, 7);
	};

	
	setCursor(0,0);
		print("2");
  //write(minupg);
  HAL_Delay(200);
}
void StoreAgg()
{
// Variable saving
  clear();
  
 // RTC.adjust(DateTime(yearupg,monthupg,dayupg,hourupg,minupg,0));
	
	  RTC_TimeTypeDef sTime;
    RTC_TimeTypeDef gTime;

	HAL_RTC_GetTime(&hrtc,&gTime, RTC_FORMAT_BIN);

	gTime.Hours = hourupg;
  gTime.Minutes =minupg;
	sprintf((char*)time, "%02d:%02d:%02d",gTime.Hours,gTime.Minutes ,gTime.Seconds);
  HAL_Delay(100);
}

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
// make some custom characters:

    byte C0[8] = {0x10,0x08,0x04,0x02,0x01,0x02,0x1C,0x18}; //1
    byte C1[8] = {0x1E,0x01,0x01,0x06,0x18,0x04,0x02,0x01}; //2
    byte C2[8] = {0x0E,0x0E,0x01,0x11,0x11,0x11,0x0A,0x04}; //3
    byte C3[8] = {0x1F,0x12,0x14,0x17,0x11,0x11,0x1F,0x0E}; //5
    byte C5[8] = {0x11,0x12,0x14,0x13,0x11,0x11,0x0A,0x04}; //6
    byte C4[8] = {0x1F,0x11,0x11,0x1F,0x01,0x01,0x01,0x01}; //7
    byte C6[8] = {0x10,0x10,0x10,0x1F,0x1E,0x11,0x1F,0x1F}; //8
    byte C7[8] = {0x10,0x10,0x0C,0x02,0x01,0x1D,0x13,0x01}; //9


/* USER CODE END 0 */

// ISR Required by the library (for HAL_Delay)
void SysTick_Handler(void);

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
  void SysTick_Handler(void);
	HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */
//  MX_NVIC_Init();
  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_RTC_Init();
  /* USER CODE BEGIN 2 */
	
	set_time();
// initialize the library by associating any needed LCD interface pin
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

  // Print a message to the lcd.
//	setCursor(3, 0); // This line is vital. You should set the cursor after you createChar.
//  print("0");
//  write((0)); 
//  write((1));
//	write((2));
//	print("8");
//	write((3));
//	write((5));
//  write((4));
//	write((6));
//  write((7));


setCursor(0, 0);
print("BANGLA DIGITAL")	;
setCursor(0, 1);
print("CLOCK WITH STM32")	;		
HAL_Delay(2000);
clear();

 /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
//    RTC_TimeTypeDef sTime = {0};
		RTC_TimeTypeDef gTime;

	HAL_RTC_GetTime(&hrtc,&gTime, RTC_FORMAT_BIN);
	
// check if you press the SET button and increase the menu index
  if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_1)==GPIO_PIN_RESET)
  {
   menu=menu+1;
		
  }
// in which subroutine should we go?
  if (menu==0)
    {
     DisplayTime(); // void DisplayDateTime
    setCursor(0,0);
		print("0");
    }
  if (menu==1)
    {
    DisplaySetHour();
//		setCursor(0,0);
//		print("1");
    }
  if (menu==2)
    {
    DisplaySetMinute();
//		setCursor(0,0);
//		print("2");
    }
	if (menu==3)
    {
		
    StoreAgg();
    		
    HAL_Delay(500);
    menu=0;
    }
		
    //HAL_Delay(100);

		
		setCursor(5, 0);    // 5-GAP, 6-7-Minute
    print(" ");
    setCursor(8, 0);//for second collen //8-GAP
    print(" ");

     HAL_Delay(800);
     setCursor(5, 0);
     print(":");
     setCursor(8, 0);
     print(":");
		 
 if(gTime.Hours>=12 && gTime.Hours< 24)   //24 Hour Format
	 {   setCursor(13, 0);                  //1 PM-13:00
		 print("PM");
 }
 else 
 {setCursor(13, 0); 
 print("AM");
 }
setCursor(3, 1); 
print("24H FORMAT");
 
    /* USER CODE BEGIN 3 */
 
//if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_2)==GPIO_PIN_SET)  //Check if button pressed
////            //  HAL_GPIO_WritePin(Led_GPIO_Port, Led_Pin,GPIO_PIN_SET);   
//            {    //(gTime.Seconds)++;
//							  sTime.Hours++;
//							
//							//sprintf((char*)time, "%02d:%02d:%02d",gTime.Hours++,gTime.Minutes++ ,gTime.Seconds++);
//						}

//// //If pressed Led Switch On
//        else
//				{  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2,GPIO_PIN_RESET);    }      //Else Led Switch Off
////             // {(gTime.Seconds)--;}
 
 
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
  * @brief RTC Initialization Function
  * @param None
  * @retval None
  */
//static void MX_NVIC_Init(void)
//{
//  /* PVD_IRQn interrupt configuration */
//  HAL_NVIC_SetPriority(PVD_IRQn, 0, 0);
//  HAL_NVIC_EnableIRQ(PVD_IRQn);
//  /* FLASH_IRQn interrupt configuration */
//  HAL_NVIC_SetPriority(FLASH_IRQn, 0, 0);
//  HAL_NVIC_EnableIRQ(FLASH_IRQn);
//  /* RCC_IRQn interrupt configuration */
//  HAL_NVIC_SetPriority(RCC_IRQn, 0, 0);
//  HAL_NVIC_EnableIRQ(RCC_IRQn);
//  /* EXTI2_IRQn interrupt configuration */
//  HAL_NVIC_SetPriority(EXTI2_IRQn, 0, 0);
//  HAL_NVIC_EnableIRQ(EXTI2_IRQn);
//  /* EXTI3_IRQn interrupt configuration */
//  HAL_NVIC_SetPriority(EXTI3_IRQn, 0, 0);
//  HAL_NVIC_EnableIRQ(EXTI3_IRQn);
//  /* EXTI4_IRQn interrupt configuration */
//  HAL_NVIC_SetPriority(EXTI4_IRQn, 0, 0);
//  HAL_NVIC_EnableIRQ(EXTI4_IRQn);
//  /* EXTI9_5_IRQn interrupt configuration */
//  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
//  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
//}
static void MX_RTC_Init(void)
{

  /* USER CODE BEGIN RTC_Init 0 */

  /* USER CODE END RTC_Init 0 */

//  RTC_TimeTypeDef sTime = {0};
//  RTC_DateTypeDef DateToUpdate = {0};

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

//  /** Initialize RTC and set the Time and Date
//  */
//  sTime.Hours = 10;
//  sTime.Minutes = 20;
//  sTime.Seconds = 30;

//  if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN) != HAL_OK)
//  {
//    Error_Handler();
//  }
//  DateToUpdate.WeekDay = RTC_WEEKDAY_MONDAY;
//  DateToUpdate.Month = RTC_MONTH_JANUARY;
//  DateToUpdate.Date = 1;
//  DateToUpdate.Year = 0;

//  if (HAL_RTC_SetDate(&hrtc, &DateToUpdate, RTC_FORMAT_BIN) != HAL_OK)
//  {
//    Error_Handler();
//  }
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
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2|GPIO_PIN_1|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5
                          |GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_RESET);

  
	

//  /*Configure GPIO pins : SecondPlus_Pin SecondMinus_Pin MinutePlus_Pin MinuteMinus_Pin
//                           HourPlus_Pin HourMinus_Pin */
//  GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_8
//                          |GPIO_PIN_9;
//  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
//  GPIO_InitStruct.Pull = GPIO_NOPULL;
//  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
	
	  /*Configure GPIO pins : PC1 PC2 PC3 PC4 PC5*/
  GPIO_InitStruct.Pin = GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
	
	/*Configure GPIO pins : PB2 PB1 PB3 PB4 PB5
                           PB6 PB7 */
  GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_1|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5
                          |GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

///* EXTI2_IRQn interrupt configuration */
//  HAL_NVIC_SetPriority(EXTI2_IRQn, 0, 0);
//  HAL_NVIC_EnableIRQ(EXTI2_IRQn);
//  /* EXTI3_IRQn interrupt configuration */
//  HAL_NVIC_SetPriority(EXTI3_IRQn, 0, 0);
//  HAL_NVIC_EnableIRQ(EXTI3_IRQn);
//  /* EXTI4_IRQn interrupt configuration */
//  HAL_NVIC_SetPriority(EXTI4_IRQn, 0, 0);
//  HAL_NVIC_EnableIRQ(EXTI4_IRQn);
//  /* EXTI9_5_IRQn interrupt configuration */
//  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
//  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);



}

/* USER CODE BEGIN 4 */
//void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {

//	UNUSED(GPIO_Pin);
//	RTC_TimeTypeDef gTime;
//	
//	HAL_RTC_GetTime(&hrtc,&gTime, RTC_FORMAT_BIN);
//	switch(GPIO_Pin) {
////		case GPIO_PIN_1: if (alarmflag) alarmflag = 0; else alarmflag = 1; break;
//		case GPIO_PIN_2:  (gTime.Seconds)++; break;
//		case GPIO_PIN_4:  gTime.Minutes++; break;
//		case GPIO_PIN_8:  gTime.Hours++; break;
//		case GPIO_PIN_3:  gTime.Seconds--; break;
//		case GPIO_PIN_5:  gTime.Minutes--; break;
//		case GPIO_PIN_9:  gTime.Hours--; break;
//	}
////	if(alarmflag) HAL_RTC_SetAlarm(&hrtc, &sAlarm, RTC_FORMAT_BIN);

//}

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
