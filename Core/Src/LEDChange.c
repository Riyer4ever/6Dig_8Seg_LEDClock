#include "LED.h"
#include "main.h"

extern int *modeOfLED;
extern RTC_TimeTypeDef *Time;

void LEDModeChange(void)
{
  // mode1, 校准时间模式
  if(*modeOfLED == 1)
  {
    uint8_t hour = 0;
    uint8_t min = 0;
    uint8_t sec = 0;
    int numDig = 3;

    while(1)
    {
      HAL_Delay(1);
      LEDToggle();
      LEDTimeShow();

      if((HAL_GPIO_ReadPin(key3_GPIO_Port, key3_Pin)) == GPIO_PIN_RESET)      // 位切换
      {
        numDig -= 1;
        if(numDig < 1)
        {
          numDig = 3;
        }
      }

      // 修改对应位的时间数值
      if(HAL_GPIO_ReadPin(key2_GPIO_Port, key2_Pin) == GPIO_PIN_RESET)        // +1
      {
        swich(numDig)
        {
          case 3:
            sec += 1;
            if(sec >= 60)
            {
                sec = 0;
            }
            break;
          case 2:
            min += 1;
            if(min >= 60)
            {
                min = 0;
            }
            break;
          case 1:
            hour += 1;
            if(hour >= 24)
            {
              hour = 0;
            }
            break;
          default:
            break;
          
            
        }
      }
      (*Time).Hour = hour;
      (*Time).Minutes = min;
      (*Time).Seconds = sec;


      if((HAL_GPIO_ReadPin(key4_GPIO_Port, key4_Pin)) == GPIO_PIN_RESET)
      {
        break;
      }
    }
  }

  else if(*modeOfLED == 2)
  {

  }

  else if(modeOfLED == 3)
  {

  }
  else
  {

  }
}
