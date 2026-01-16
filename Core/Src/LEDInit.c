#include "main.h"

void LEDInit(void)
{
  HAL_GPIO_WritePin(aSeg_GPIO_Port, aSeg_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(bSeg_GPIO_Port, bSeg_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(cSeg_GPIO_Port, cSeg_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(dSeg_GPIO_Port, dSeg_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(eSeg_GPIO_Port, eSeg_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(fSeg_GPIO_Port, fSeg_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(gSeg_GPIO_Port, gSeg_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(dpSeg_GPIO_Port, dpSeg_Pin, GPIO_PIN_RESET);

  HAL_GPIO_WritePin(dig1_GPIO_Port, dig1_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(dig2_GPIO_Port, dig2_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(dig3_GPIO_Port, dig3_Pin, GPIO_PIN_SET);
}
