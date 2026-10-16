#include "Start.h"
#include "Motor.h"

//UART1
uint8_t rx_buffer[100];//½ÓÊÕÊý×é
uint8_t rx_len = 0; //½ÓÊÕµ½µÄÊý¾Ý³¤¶È







uint16_t raw;



//×Ô¶¨ÒåusÑÓÊ±Æ÷£¬ÓÃTIM7×÷Îªus¶¨Ê±Æ÷
//void HAL_Delay_us(uint16_t nus)
//{
//	__HAL_TIM_SET_COUNTER(&htim7, 0);
//	__HAL_TIM_ENABLE(&htim7);
//	while (__HAL_TIM_GET_COUNTER(&htim7) < nus)
//	{
//	}
//	__HAL_TIM_DISABLE(&htim7);
//}



void Enable_IT(void)
{
	//1.³õÊ¼»¯TIM7¶¨Ê±Æ÷ÖÐ¶Ï     1ms¶¨Ê±ÖÐ¶Ï
	HAL_TIM_Base_Start_IT(&htim7);   //Ê¹ÄÜÖÐ¶Ï
//	HAL_TIM_Base_Stop(&htim15);       //¹Ø±ÕÖÐ¶Ï
	
	
	//2.UART1ÖØ¶¨Ïò£¬½ÓÊÕºÍ·¢ËÍ£¬ÖÐ¶ÏÓëDMA¿ªÆô
	//2-1.ÔÚuart.c¼ÓÈëÖØ¶¨Ïò 

	/*
	  * º¯Êý¹¦ÄÜ: ÖØ¶¨Ïòc¿âº¯Êýprintfµ½DEBUG_USARTx
	  * ÊäÈë²ÎÊý: ÎÞ
	  * ·µ »Ø Öµ: ÎÞ
	  * Ëµ    Ã÷£ºÎÞ
	  */
//	int fputc(int ch, FILE *f)
//	{
//	  HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 0xffff);
//	  return ch;
//	}
	 
	/*
	  * º¯Êý¹¦ÄÜ: ÖØ¶¨Ïòc¿âº¯Êýgetchar,scanfµ½DEBUG_USARTx
	  * ÊäÈë²ÎÊý: ÎÞ
	  * ·µ »Ø Öµ: ÎÞ
	  * Ëµ    Ã÷£ºÎÞ
	  */
//	int fgetc(FILE *f)
//	{
//	  uint8_t ch = 0;
//	  HAL_UART_Receive(&huart1, &ch, 1, 0xffff);
//	  return ch;
//	}
	
	//2-2.½ÓÊÕºÍ·¢ËÍ²¿·Ö£¬ÔÚit.cÀïµÄvoid USART1_IRQHandler(void)¼ÓÈëÏÂÃæ×¢ÊÍ²¿·Ö

//	if (__HAL_UART_GET_FLAG(&huart1,UART_FLAG_IDLE) != RESET)// Í¨¹ýIDLE±êÖ¾Î»ÅÐ¶Ï½ÓÊÕÊÇ·ñ½áÊø
//	   { 
//		  __HAL_UART_CLEAR_IDLEFLAG(&huart1);//Çå³ý±êÖ¾Î»
//		  HAL_UART_DMAStop(&huart1);               
//		  rx_len = 100 - __HAL_DMA_GET_COUNTER(&hdma_usart1_rx); //¼ÆËã³öÊý¾Ý³¤¶È
//		  HAL_UART_Transmit_DMA(&huart1, rx_buffer,rx_len);//½«ÊÕµ½µÄÊý¾Ý·¢ËÍ³öÈ¥
//		  HAL_UART_Receive_DMA(&huart1,rx_buffer,100);//¿ªÆôDMA½ÓÊÕ£¬·½±ãÏÂÒ»´Î½ÓÊÕÊý¾Ý
//	   }

    //2-3.ÖÐ¶ÏÓëDMA¿ªÆô
//	__HAL_UART_ENABLE_IT(&huart1, UART_IT_IDLE);    
//	HAL_UART_Receive_DMA(&huart1,rx_buffer,100);
	
	//3.¶¨Ê±Æ÷1PWM¿ªÆô
	//¿ªÆô¶¨Ê±Æ÷1
	HAL_TIM_Base_Start(&htim1);
	
	//´ò¿ªPWMÍ¨µÀ
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_4);
	HAL_TIMEx_PWMN_Start(&htim1,TIM_CHANNEL_1);
	HAL_TIMEx_PWMN_Start(&htim1,TIM_CHANNEL_2);
	HAL_TIMEx_PWMN_Start(&htim1,TIM_CHANNEL_3);

	//¸ø³õÊ¼Öµ
	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,2125);   //Duty=4225/8500
	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_2,2125);
	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_3,2125);
	
	//¿	ªÆôTIM1µÄOC4ÖÐ¶Ï  ÔÚHALÀïÃæÒªÏÈ¹´Ñ¡TIM1 update interrupt and TIM16 global interrupt
//	__HAL_TIM_ENABLE_IT(&htim1, TIM_IT_CC4);   // ¿ªÖÐ¶Ï±êÖ¾Î»
//	HAL_TIM_OC_Start_IT(&htim1, TIM_CHANNEL_4); // Æô¶¯Í¨µÀ 4 ²¢¸½ÖÐ¶Ï
	
	//²¢Ð´ÖÐ¶Ï»Øµ÷
	/* Ã¿Íê³ÉÒ»´Î CCR4 ±È½ÏÆ¥Åä¾Í½øÀ´ -------------------------- */
	/*
	void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
	{
		if (htim->Instance == TIM1 && htim->Channel == HAL_TIM_ACTIVE_CHANNEL_4)
		{
			
			HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);   // Ê¾Àý£º·­×ª LED
		}
	}
	*/
	
	//ADC1³õÊ¼»¯£¬ÓÃÓÚABÏàµçÁ÷²ÉÑùºÍÄ¸ÏßµçÑ¹²ÉÑù
	//HAL_ADC_Start_DMA(&hadc1,(uint32_t *)ADC1RegularDate,3);   //ÂÖÑ¯ºÍ×¢Èë¶þÑ¡Ò»£¬×¢ÈëËÙ¶È¸ü¿ì£¬²»¿ªÆôDMA
	Data_Init();
	FIR_DSP_Init();
	cordic_config();    //cordic¿â³õÊ¼»¯
	CANFD_Init_Config(); //CAN³õÊ¼»¯ÅäÖÃ
	HAL_ADCEx_Calibration_Start(&hadc1,ADC_SINGLE_ENDED);            //ÔöÒæÎó²îÐ£×¼
	__HAL_ADC_ENABLE_IT(&hadc1,ADC_IT_JEOC);    //ADC×¢ÈëÍ¨µÀÖÐ¶Ï    //»¹ÐèÒªÔÚit.cÀïÃæ´ò¿ªHAL_ADCEx_InjectedConvCpltCallbackÖÐ¶Ï¶ÁÈ¡    
	HAL_ADCEx_InjectedStart(&hadc1);            //¿ªÆôADC×¢Èë²ÉÑù
	
	
////×¢Èë×éADC²ÉÑùÖÐ¶Ï»Øµ÷
//void HAL_ADCEx_InjectedConvCpltCallback(ADC_HandleTypeDef *hadc)
//{
////	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,GPIO_PIN_SET);
//	//ADC²ÉÑù ABÏàµçÁ÷ºÍÄ¸ÏßµçÑ¹
//	ADC1InjectDate[0] = hadc->Instance->JDR1;    //AÏàµçÁ÷
//	ADC1InjectDate[1] = hadc->Instance->JDR2;    //BÏàµçÁ÷
//	ADC1InjectDate[2] = hadc->Instance->JDR3;    //CÏàµçÑ¹
//	ADC1InjectDate[3] = hadc->Instance->JDR4;    //Ä¸ÏßµçÑ¹

////	Adcpro(&adcvalue,&allflag,ADC1InjectDate);
////	encoder_str.Encoder = MT6701_ReadRaw();
//	Data_Treating();
////	Encoderpro(&encoder_str,&allflag);
////	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,GPIO_PIN_RESET);
//	
//}


	
}
