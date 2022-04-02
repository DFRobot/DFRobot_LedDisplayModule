/*!
 * @file ledFlash.ino
 * @brief The digital tube flash experiment
 * @n Experiment phenomenon: The digital tube shows "FLASH", and flashes to show 0.5HZ in 2 seconds,
 * @n then flashes to show 1HZ in 3 seconds and flashes to show 2HZ in the other 3 seconds. Finally, shows HOLD in another 3s.
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


void setup() 
{
  Serial.begin(115200);
  /*Wait for the chip to be initialized completely, and then exit*/
  while(LED.begin(LED.e8Bit) != 0)
  {
    Serial.println("Initialization of the chip failed, please confirm that the chip connection is correct!");
    delay(1000);
  }
  /**
   * Set the display area to 1, 2, 3, 4, 5, 6, 7, 8 
   * It can show 8 bits, the region of each parameter is 1~8
   * Please resend the display value if the display area is changed
   */
  LED.setDisplayArea(3,4,5,6,7);
  /**
   * Display "HALO"
   * At present, it only supports showing the numbers 0 to 9, capital letters A, B, C, D, E, F, H, L, O, P, U and dash-,
   * and you can also bring decimal points, such as "0." "9." "A." "-."
   */
  LED.print("F","L","A","5","H");
  delay(2000);
}

void loop() 
{    
  LED.setDisplayArea(3,4,5,6,7);
  LED.print("0.","5","-","H","2");
  /* Start flash at 0.5Hz.*/
  LED.flashTwos();
  delay(3000);

  LED.setDisplayArea(3,4,5,6);
  LED.print("1","-","H","2");
  /* Start flash at 1Hz.*/
  LED.flashOnes();
  delay(3000);
  
  LED.setDisplayArea(3,4,5,6);
  LED.print("2","-","H","2"); 
  /* Start flash at 2Hz.*/ 
  LED.flashHalfs();
  delay(3000);

  LED.setDisplayArea(3,4,5,6);
  LED.print("H","O","L","D");
  /* Stop flash*/
  LED.stopFlash();
  delay(3000);
}
