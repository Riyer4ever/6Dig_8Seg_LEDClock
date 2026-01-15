#include "main.h"

extern RTC_HandleTypeDef hrtc;

RTC_TimeTypeDef Time = {0 };

void RTC_Get(void)
{
	HAL_RTC_GetTime(&hrtc, &Time, RTC_FORMAT_BCD);
}

// 获取hour
int getHour(void)
{
	int hour = Time.Hours;
	return hour;
}

int getMin(void)
{
	int min = Time.Minutes;
	return min;
}

int getSec()
{
	int sec = Time.Seconds;
	return sec;
}
