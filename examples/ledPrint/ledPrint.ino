/*!
 * @file ledPrint.ino
 * @brief Display experiment of the digital tube
 * @n Experiment phenomenon: The digital tube displays "HALO"，and in one second, displays "H.A.L.O.", then show value of the variable val after one second
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
 * Parameter: The IIC address in default is 0x48
 */
DFRobot_LedDisplayModule LED(&Wire, 0x48);

void setup() 
{
  Serial.begin(115200);
  /*Wait for the chip to be initialized completely, and then exit*/
  while(LED.begin4(LED.e4Bit) != 0)
  {
    Serial.println("Failed to initialize the chip , please confirm the chip connection!");
    delay(1000);
  }
  
  /**
   * Set the display area to 1, 2, 3, 4
   * It can show 4 bits, the region of each parameter is 1~4 
   * Please resend the display value if the display area is changed
   */
  LED.setDisplayArea(1,2,3,4);
}

void loop() 
{
  /**
   * Display "HALO"
   * At present, it only supports showing the numbers 0 to 9, capital letters A, B, C, D, E, F, H, L, O, P, U and dash-,
   * and you can also bring decimal points, such as "0." "9." "A." "-."
   */
  LED.print("H","A","L","O");
  delay(1000);
  
  LED.print("H.","A.","L.","O."); 
  delay(1000);
  
  /**
   * Show a viriable value
   * The viriable could be both integer and decimal
   * Here it can be compatible with the sensor return value, such as temperature, humdity and so on
   */
  double val = 13.25;
  LED.print(val);
  delay(1000);
}
