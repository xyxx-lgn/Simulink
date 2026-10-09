#ifndef __Motor_H
#define __Motor_H		


//头文件包含
#include "ALL_H.h"

void Data_Init(void);
float Angle_Limit(float raw,float Limit);
float Coridc_Angle(float angle);

void Adc_Task(AdcValue *adcvalue,AllFlag *allflag,uint16_t *adc_raw);
void Encoder_Task(Encoder_Struct *encoder_str,AllFlag *allflag);
void Mode_Task(Encoder_Struct *encoder_str,AllFlag *allflag);

void My_Task(void);
void pwm_set(float U_PWM,float V_PWM,float W_PWM);
void Simulink_Task(void);
#endif
