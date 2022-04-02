/*!
 * @file ledSetDisplayArea.ino
 * @brief The experiment to set the display area of the digital tube
 * @n Experiment phenomenon: The 13 zone of the digital tube shows "HL", and the 24 zone show "AO" in one second, then 1234 zone show "HALO" in one second.
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
DFRobot_LedDisplayModule LED(&Wire, 0xE0);

/**
 * DFRobot_LedDisplayModule Constructor
 * In default, the IIC address of 4 bits digital tube is 0x48 
 */
//DFRobot_LedDisplayModule LED(&Wire, 0x48);

void setup() 
{
  Serial.begin(115200);
  /*Wait for the chip to be initialized completely, and then exit*/
  while(LED.begin(LED.e8Bit) != 0)
  {
    Serial.println("Failed to initialize the chip , please confirm the chip connection!");
    delay(1000);
  }
}

void loop() 
{
  /**
   * Set the display area to 1, 3
   * It can show 4 bits, the region of each parameter is 1~4 
   * Please resend the display value if the display area is changed
   */
  LED.setDisplayArea(1,3);
  /**
   * Display "HL"  
   * At present, it only supports showing the numbers 0 to 9, capital letters A, B, C, D, E, F, H, L, O, P, U and dash-;
   * and you can also bring decimal points, such as "0." "9." "A." "-."
   */
  LED.print("H","L"); 
  delay(1000);
 
  LED.setDisplayArea(2,4);
  LED.print("A","O");
  delay(1000);
  
  LED.setDisplayArea(1,2,3,4);
  LED.print("H","A","L","O");
  //LED.print4("H.","A.","L.","O.");
  delay(1000);
}
