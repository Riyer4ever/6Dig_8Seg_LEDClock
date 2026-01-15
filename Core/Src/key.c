#include "main.h"

int keyScan(void)
{
	int key1Value = HAL_GPIO_ReadPin(key1_GPIO_Port, key1_Pin);
	int key2Value = HAL_GPIO_ReadPin(key2_GPIO_Port, key2_Pin);
	int key3Value = HAL_GPIO_ReadPin(key3_GPIO_Port, key3_Pin);
	int key4Value = HAL_GPIO_ReadPin(key4_GPIO_Port, key4_Pin);
	
	int stateOfKey = 0x04;
	if(key1Value == 0)
	{
		stateOfKey = 0x00;					// key1按下
	}
	
	if(key1Value == 0)
	{
		stateOfKey = 0x01;					// key2按下
	}
	
	if(key3Value == 0)
	{
		stateOfKey = 0x02;					// key3按下
	}
	
	if(key4Value == 0)
	{
		stateOfKey = 0x03;					// key4按下
	}
	
	return stateOfKey;
}
