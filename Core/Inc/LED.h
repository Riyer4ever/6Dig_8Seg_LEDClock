#ifndef LED_H
#define LED_H

/**
 * 138译码器周期显示数码管位，对应如下：
 * 000->1Dig
 * 001->2Dig
 * 010->3Dig
 * 011->4Dig
 * 100->5Dig
 * 101->6Dig
 * 110->7Dig
 * 111->8Dig
 * 因为只有6位，所有不需要110和111
 */

void LEDToggle(void);
void LEDTimeShow(void);

#endif
