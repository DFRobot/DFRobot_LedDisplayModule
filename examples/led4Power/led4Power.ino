/*!
 * @file led4Power.ino
 * @brief Switch experiment of the digital tube.
 * @n Experiment phenomenon: The digital tube displays "HALO" and turns off the screen in a second, then turns it ON in the next one second.
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
DFRobot_LedDisplayModule LED(Wire, 0x48);

//Prepare: Connecting the digital tube to the IIC interface of the mainboard 
void setup()
{
  Serial.begin(115200);
  /*Wait for the chip to be initialized completely, and then exit*/
  while(LED.begin4() != 0)
  {
    Serial.println("Failed to initialize the chip , please confirm the chip connection!");
    delay(1000);
  }
  /* Set the display area */
  LED.setDisplayArea4(1,2,3,4);
  /** 
   * Display "HALO" 
   * At present, it only supports showing the numbers 0 to 9, capital letters A, B, C, D, E, F, H, L, O, P, U and dash-,
   * and you can also bring decimal points, such as "0." "9." "A." "-." 
   */
  LED.print4("H","A","L","O");
  delay(1000);
}

void loop()
{ 
  /* Turn OFF the display */
  LED.displayOff();
  delay(1000);
  
  /* Turn ON the display*/
  LED.displayOn();
  delay(1000);
}
