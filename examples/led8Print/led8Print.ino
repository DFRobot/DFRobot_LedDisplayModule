/*!
 * @file led8Print.ino
 * @brief The display experiment of digital tube
 * @n Experiment phenomenon: The digital tube displays "HALO"; in one second, displays "H.A.L.O.", then show value of the variable val after one second
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
 *In default, the IIC address of 8 bits digital tube is 0xE0
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
    Serial.println("");
    delay(1000);
  }
}

void loop() 
{    
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
  delay(1000);
  
  /* Show a viriable value
   * The viriable could be both integer and decimal
   * Here it can be compatible with the sensor return value, such as temperature, humdity and so on 
   */
  double val = 13.25;
  LED.setDisplayArea8(3,4,5,6);
  LED.print8(val);
  delay(1000);
}
