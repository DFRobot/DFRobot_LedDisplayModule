/*!
 * @file led8Power.ino
 * @brief The switch experiment 
 * @n Experiment phenomenon: The digital tube shows "HALO.LED8", and the screen turns off in a second, then turns ON in the next one second
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author [Actor](wenzheng.wang@dfrobot.com),[TangJie](jie.tang@dfrobot.com)
 * @version  V1.0.1
 * @data  2022-03-21
 * @url https://github.com/DFRobot/DFRobot_LedDisplayModule
 */

# include "DFRobot_LedDisplayModule.h"
/**
 * DFRobot_LedDisplayModule Constructor
 * Parameter &wire  Wire
 * In default, the IIC address of 8 bits digital tube is 0xE0
 * The IIC address of 8 bits digital tube can be changed by combining A1 and A0
 * 1  1  1  0  | 0  A1 A0 0
 * 1  1  1  0  | 0  0  0  0    0xE0
 * 1  1  1  0  | 0  0  1  0    0xE2
 * 1  1  1  0  | 0  1  0  0    0xE4
 * 0  0  1  0  | 0  1  1  0    0xE6
 */ 
DFRobot_LedDisplayModule LED(Wire, 0xE0);

//Prepare: Connect the digital tube to the IIC interface of the mainboard
void setup()
{
  Serial.begin(115200);
  /*Wait for the chip to be initialized completely, and then exit*/
  while(LED.begin8() != 0)
  {
    Serial.println("Initialization of the chip failed, please confirm that the chip connection is correct!");
    delay(1000);
  }
  /* Set the display area*/
  LED.setDisplayArea8(1,2,3,4,5,6,7,8);
  
  /**
   * Display "HALO.LED8"
   * At present, it only supports showing the numbers 0 to 9, capital letters A, B, C, D, E, F, H, L, O, P, U and dash-,
   * and you can also bring decimal points, such as "0." "9." "A." "-."
   */
  LED.print8("H","A","L","O.","L","E","D","8");
  delay(1000);
}

void loop()
{ 
  /* Turn OFF the display */
  LED.displayOff();
  delay(1000);
  
  /* Turn ON the display */
  LED.displayOn();
  delay(1000);
}
