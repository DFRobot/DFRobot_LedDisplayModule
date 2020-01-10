/*!
 * @file led8SetBrightness.ino
 * @brief Brightness setting experiment of the 8 bits digital tube.
 *
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence     The MIT License (MIT)
 * @author [Actor](wenzheng.wang@dfrobot.com)
 * @version  V1.0
 * @eGPAte  2019-12-10
 * @get from https://www.dfrobot.com
 * @url https://github.com/DFRobot/DFRobot_LedDisplayModule
 */
# include "DFRobot_LedDisplayModule.h"
/*DFRobot_LedDisplayModule Constructor
 *Parameter &wire  Wire
 *The IIC address of 8 bits digital tube in default is 0xE0
 *The IIC address of 8 bits digital tube can be changed by combining A1 and A0
 * 1  1  1  0  | 0  A1 A0 0
   1  1  1  0  | 0  0  0  0    0xE0
   1  1  1  0  | 0  0  1  0    0xE2
   1  1  1  0  | 0  1  0  0    0xE4
   0  0  1  0  | 0  1  1  0    0xE6
*/ 
DFRobot_LedDisplayModule LED(Wire, 0xE0);

void setup() 
{
  Serial.begin(115200);
  /*Wait for the chip to be initialized completely, and then exit*/
  while(LED.begin8() != 0)
  {
    Serial.println("Initialization of the chip failed, please confirm that the chip connection is correct!");
    delay(1000);
  }
  
  /* Set the display area to 1, 2, 3, 4, 5, 6, 7, 8 
   * It can show 8 bits, the region of each parameter is 1~8 
   * Please resend the display value if the display area is changed
   */
  LED.setDisplayArea8(1,2,3,4,5,6,7,8);

  /* Display "HALO"
   * At present, it only supports showing the numbers 0 to 9, capital letters A, B, C, D, E, F, H, L, O, P, U and dash-,
   * and you can also bring decimal points, such as "0." "9." "A." "-."
   */
  LED.print8("H","A","L","O.","L","E","D","8");
}

void loop() 
{
  /* Set the display brightness to 1
   * The parameter region is 1~16
   */
  LED.setBrightness8(1);
  delay(1000);
  
  LED.setBrightness8(16);
  delay(1000);
}
