#include "main.h"
#include "RTCGet.h"

#define highPin GPIO_PIN_SET

extern int *LEDStatus;
int numShow = 0;

void LEDToggle(void)
{
	// 重置显示的数码管，从6回到1
	if(*LEDStatus == 0)
	{
		HAL_GPIO_WritePin(dig1_GPIO_Port, dig1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(dig2_GPIO_Port, dig2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(dig3_GPIO_Port, dig3_Pin, GPIO_PIN_SET);
	}
	else if(*LEDStatus == 1)
	{
		HAL_GPIO_WritePin(dig1_GPIO_Port, dig1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(dig2_GPIO_Port, dig2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(dig3_GPIO_Port, dig3_Pin, GPIO_PIN_SET);
	}
	else if(*LEDStatus == 2)
	{
		HAL_GPIO_WritePin(dig1_GPIO_Port, dig1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(dig2_GPIO_Port, dig2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(dig3_GPIO_Port, dig3_Pin, GPIO_PIN_SET);
	}
	else if(*LEDStatus == 3)
	{
		HAL_GPIO_WritePin(dig1_GPIO_Port, dig1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(dig2_GPIO_Port, dig2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(dig3_GPIO_Port, dig3_Pin, GPIO_PIN_SET);
	}
	else if(*LEDStatus == 4)
	{
		HAL_GPIO_WritePin(dig1_GPIO_Port, dig1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(dig2_GPIO_Port, dig2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(dig3_GPIO_Port, dig3_Pin, GPIO_PIN_RESET);
	}
	else if(*LEDStatus == 5)
	{
		HAL_GPIO_WritePin(dig1_GPIO_Port, dig1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(dig2_GPIO_Port, dig2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(dig3_GPIO_Port, dig3_Pin, GPIO_PIN_RESET);
		*LEDStatus = -1; // 下次归零
	}
	else
	{
		HAL_GPIO_WritePin(dig1_GPIO_Port, dig1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(dig2_GPIO_Port, dig2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(dig3_GPIO_Port, dig3_Pin, GPIO_PIN_SET);
	}

	*LEDStatus += 1;
}

// 每个数字需要2位
void LEDTimeShow(void)
{
	int timeNum = 0;
	if(*LEDStatus == 1)
	{
		timeNum = getHour();
		numShow = timeNum / 10;
	}
	
	else if(*LEDStatus == 2)
	{
		timeNum = getHour();
		numShow = timeNum % 10;
		HAL_GPIO_WritePin(dpSeg_GPIO_Port, dpSeg_Pin, highPin);
	}
	
	else if(*LEDStatus == 3)
	{
		timeNum = getMin();
		numShow = timeNum / 10;
	}
	
	else if(*LEDStatus == 4)
	{
		timeNum = getMin();
		numShow = timeNum % 10;
		HAL_GPIO_WritePin(dpSeg_GPIO_Port, dpSeg_Pin, highPin);
	}
	
	else if(*LEDStatus == 5)
	{
		timeNum = getSec();
		numShow = timeNum / 10;
	}
	
	else
	{
		timeNum = getSec();
		numShow = timeNum % 10;
		
	}

	switch(numShow)
	{
		case 0:
			HAL_GPIO_WritePin(aSeg_GPIO_Port, aSeg_Pin, highPin);
			HAL_GPIO_WritePin(bSeg_GPIO_Port, bSeg_Pin, highPin);
			HAL_GPIO_WritePin(cSeg_GPIO_Port, cSeg_Pin, highPin);
			HAL_GPIO_WritePin(dSeg_GPIO_Port, dSeg_Pin, highPin);
			HAL_GPIO_WritePin(eSeg_GPIO_Port, eSeg_Pin, highPin);
			HAL_GPIO_WritePin(fSeg_GPIO_Port, fSeg_Pin, highPin);
			break;
		case 1:
			HAL_GPIO_WritePin(bSeg_GPIO_Port, bSeg_Pin, highPin);
			HAL_GPIO_WritePin(cSeg_GPIO_Port, cSeg_Pin, highPin);
			break;
		case 2:
			HAL_GPIO_WritePin(aSeg_GPIO_Port, aSeg_Pin, highPin);
			HAL_GPIO_WritePin(bSeg_GPIO_Port, bSeg_Pin, highPin);
			HAL_GPIO_WritePin(gSeg_GPIO_Port, gSeg_Pin, highPin);
			HAL_GPIO_WritePin(eSeg_GPIO_Port, eSeg_Pin, highPin);
			HAL_GPIO_WritePin(dSeg_GPIO_Port, dSeg_Pin, highPin);
			break;
		case 3:
			HAL_GPIO_WritePin(aSeg_GPIO_Port, aSeg_Pin, highPin);
			HAL_GPIO_WritePin(bSeg_GPIO_Port, bSeg_Pin, highPin);
			HAL_GPIO_WritePin(gSeg_GPIO_Port, gSeg_Pin, highPin);
			HAL_GPIO_WritePin(cSeg_GPIO_Port, cSeg_Pin, highPin);
			HAL_GPIO_WritePin(dSeg_GPIO_Port, dSeg_Pin, highPin);
			break;
		case 4:
			HAL_GPIO_WritePin(fSeg_GPIO_Port, fSeg_Pin, highPin);
			HAL_GPIO_WritePin(gSeg_GPIO_Port, gSeg_Pin, highPin);
			HAL_GPIO_WritePin(bSeg_GPIO_Port, bSeg_Pin, highPin);
			HAL_GPIO_WritePin(cSeg_GPIO_Port, cSeg_Pin, highPin);
			break;
		case 5:
			HAL_GPIO_WritePin(aSeg_GPIO_Port, aSeg_Pin, highPin);
			HAL_GPIO_WritePin(fSeg_GPIO_Port, fSeg_Pin, highPin);
			HAL_GPIO_WritePin(gSeg_GPIO_Port, gSeg_Pin, highPin);
			HAL_GPIO_WritePin(cSeg_GPIO_Port, cSeg_Pin, highPin);
			HAL_GPIO_WritePin(dSeg_GPIO_Port, dSeg_Pin, highPin);
			break;
		case 6:
			HAL_GPIO_WritePin(aSeg_GPIO_Port, aSeg_Pin, highPin);
			HAL_GPIO_WritePin(fSeg_GPIO_Port, fSeg_Pin, highPin);
			HAL_GPIO_WritePin(eSeg_GPIO_Port, eSeg_Pin, highPin);
			HAL_GPIO_WritePin(dSeg_GPIO_Port, dSeg_Pin, highPin);
			HAL_GPIO_WritePin(cSeg_GPIO_Port, cSeg_Pin, highPin);
			HAL_GPIO_WritePin(gSeg_GPIO_Port, gSeg_Pin, highPin);
			break;
		case 7:
			HAL_GPIO_WritePin(aSeg_GPIO_Port, aSeg_Pin, highPin);
			HAL_GPIO_WritePin(bSeg_GPIO_Port, bSeg_Pin, highPin);
			HAL_GPIO_WritePin(cSeg_GPIO_Port, cSeg_Pin, highPin);
			break;
		case 8:
			HAL_GPIO_WritePin(aSeg_GPIO_Port, aSeg_Pin, highPin);
			HAL_GPIO_WritePin(bSeg_GPIO_Port, bSeg_Pin, highPin);
			HAL_GPIO_WritePin(cSeg_GPIO_Port, cSeg_Pin, highPin);
			HAL_GPIO_WritePin(dSeg_GPIO_Port, dSeg_Pin, highPin);
			HAL_GPIO_WritePin(eSeg_GPIO_Port, eSeg_Pin, highPin);
			HAL_GPIO_WritePin(fSeg_GPIO_Port, fSeg_Pin, highPin);
			HAL_GPIO_WritePin(gSeg_GPIO_Port, gSeg_Pin, highPin);
			break;
		case 9:
			HAL_GPIO_WritePin(aSeg_GPIO_Port, aSeg_Pin, highPin);
			HAL_GPIO_WritePin(bSeg_GPIO_Port, bSeg_Pin, highPin);
			HAL_GPIO_WritePin(cSeg_GPIO_Port, cSeg_Pin, highPin);
			HAL_GPIO_WritePin(dSeg_GPIO_Port, dSeg_Pin, highPin);
			HAL_GPIO_WritePin(fSeg_GPIO_Port, fSeg_Pin, highPin);
			HAL_GPIO_WritePin(gSeg_GPIO_Port, gSeg_Pin, highPin);
			break;
		default:
			HAL_GPIO_WritePin(aSeg_GPIO_Port, aSeg_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(bSeg_GPIO_Port, bSeg_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(cSeg_GPIO_Port, cSeg_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(dSeg_GPIO_Port, dSeg_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(eSeg_GPIO_Port, eSeg_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(fSeg_GPIO_Port, fSeg_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(gSeg_GPIO_Port, gSeg_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(dpSeg_GPIO_Port, dpSeg_Pin, GPIO_PIN_RESET);
			break;
	}
}
