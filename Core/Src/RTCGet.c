#include "main.h"

extern RTC_HandleTypeDef hrtc;

extern RTC_TimeTypeDef *Time;

void RTC_Get(void)
{
	RTC_DateTypeDef Date;
	HAL_RTC_GetTime(&hrtc, Time, RTC_FORMAT_BIN);
	HAL_RTC_GetDate(&hrtc, &Date, RTC_FORMAT_BIN);
}

// 获取hour
int getHour(void)
{
	RTC_Get();
	int hour = (*Time).Hours;
	return hour;
}

int getMin(void)
{
	RTC_Get();
	int min = (*Time).Minutes;
	return min;
}

int getSec()
{
	RTC_Get();
	int sec = (*Time).Seconds;
	return sec;
}
