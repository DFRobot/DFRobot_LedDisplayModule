# DFRobot_LedDisplayModule
This is a 4bits / 8bits digital tube. It communicates with the host via IIC to show numbers from 0 to 9, capital letters A, B, C, D, E, F, H, L, O, P, U and dash-. <br>
The IIC address of 4 bits digital tube in default is 0x48. <br>
The IIC address of 8 bits digital tube in default is 0xE0. This address can be changed to 0xE2, 0xE4, 0xE6 with different combinations of 2 welding points that in the back of the display. <br>

## DFRobot_LedDisplayModule for Arduino
---------------------------------------------------------
Provide an Arduino library for the Led Display Module.
   
## Table of Contents

* [Summary](#summary)
* [Installation](#installation)
* [Methods](#methods)
* [Compatibility](#compatibility)
* [History](#history)
* [Credits](#credits)

## Summary
This is an Arduino IDE library to help realize the communication between the 4bits/8bits digital tube and Arduino<br>
The library ease the control of display by IIC<br>

## Installation

To use this library, please download the library file first and paste it into the \Arduino\libraries directory, then open the examples folder and run the demo in the folder.

## Methods

```C++
  int begin4();
  
  /*!
   *  @brief Initialize the 8bits 
   *  @return Return 0 if initialization succeeds, otherwise return non-zero.
   */ 
  int begin8();

  /*!
   *  @brief Start display
   *  @param Command to start display
   */
  void displayOn();
  
  /*!
   *  @brief End display
   *  @param Command to end displaying
   */  
  void displayOff();

  /*!
   *  @brief Flash mode of the 8 bits digital tube, flash at 0.5Hz
   *  @param IIC flash command
   */
  void flashTwos();
  
  /*!
   *  @brief Flash mode of the 8 bits digital tube, flash at 1HZ
   *  @param IIC flash command
   */
  void flashOnes();
  
  /*!
   *  @brief Flash mode of the 8 bits digital tube, flash at 2HZ 
   *  @param IIC flash command
   */
  void flashHalfs();
  
  /*!
   *  @brief The 8 bits digital tube stops flash 
   *  @param IIC command to stop flash
   */
  void stopFlash();

  /*!
   *  @brief Set brightness of the 4 bits digital tube
   *  @param The brightness value can be set to numbers 1~8
   */
  void setBrightness4(int brightnessValue); 
  
  /*!
   *  @brief Set brightness of the 8 bits digital tube
   *  @param The brightness value can be set to numbers 1~16
   */
  void setBrightness8(int brightnessValue);

  /*!
   *  @brief Display area of the 4bits digital tube 
   *  @param The display address of the first bit to fourth bit could be numbers 1~4
   */
  void setDisplayArea4(int areaData);
  void setDisplayArea4(int areaData1,int areaData2);
  void setDisplayArea4(int areaData1,int areaData2,int areaData3);
  void setDisplayArea4(int areaData1,int areaData2,int areaData3,int areaData4);

  /*!
   *  @brief Display area of the 8bits digital tube
   *  @param The display address of the first bit to eighth bit could be numbers 1~8
   */
  void setDisplayArea8(int areaData);
  void setDisplayArea8(int areaData1,int areaData2);
  void setDisplayArea8(int areaData1,int areaData2,int areaData3);
  void setDisplayArea8(int areaData1,int areaData2,int areaData3,int areaData4);
  void setDisplayArea8(int areaData1,int areaData2,int areaData3,int areaData4,int areaData5);
  void setDisplayArea8(int areaData1,int areaData2,int areaData3,int areaData4,int areaData5,int areaData6);
  void setDisplayArea8(int areaData1,int areaData2,int areaData3,int areaData4,int areaData5,int areaData6,int areaData7);
  void setDisplayArea8(int areaData1,int areaData2,int areaData3,int areaData4,int areaData5,int areaData6,int areaData7,int areaData8);

  /*!
   *  @brief Print data of the 4 bits digital tube
   *  @param It could be both integer and decimal
   */  
  void print4(double sensorData);
  
  /*!
   *  @brief Print data of the 4 bits digital tube
   *  @param Displayed data of bit 1 to bit 4 could be the numbers 0 to 9, capital letters A, B, C, D, E, F, H, L, O, P, U and dash-. 
   *  @n and also could be decimal points, such as "0." "9." "A." "-."
   */
  void print4(const char buf1[]);
  void print4(const char buf1[],const char buf2[]);
  void print4(const char buf1[],const char buf2[],const char buf3[]);
  void print4(const char buf1[],const char buf2[],const char buf3[],const char buf4[]);

  /*!
   *  @brief Print data of the 8 bits digital tube
   *  @param It could be both integer and decimal
   */
  void print8(double sensorData);
  
  /*!
   *  @brief Print data of the 8 bits digital tube
   *  @param Displayed data of bit 1 to bit 8 could be the numbers 0 to 9, capital letters A, B, C, D, E, F, H, L, O, P, U and dash-.
   *  @n and also could be decimal points, such as "0." "9." "A." "-."
   */
  void print8(const char buf1[]);
  void print8(const char buf1[],const char buf2[]);
  void print8(const char buf1[],const char buf2[],const char buf3[]);
  void print8(const char buf1[],const char buf2[],const char buf3[],const char buf4[]);
  void print8(const char buf1[],const char buf2[],const char buf3[],const char buf4[],const char buf5[]);
  void print8(const char buf1[],const char buf2[],const char buf3[],const char buf4[],const char buf5[],const char buf6[]);
  void print8(const char buf1[],const char buf2[],const char buf3[],const char buf4[],const char buf5[],const char buf6[],const char buf7[]);
  void print8(const char buf1[],const char buf2[],const char buf3[],const char buf4[],const char buf5[],const char buf6[],const char buf7[],const char buf8[]);
```

## Compatibility

MCU                | Work Well    | Work Wrong   | Untested    | Remarks
------------------ | :----------: | :----------: | :---------: | -----
Arduino Uno        |      √       |              |             | 
Mega2560        |      √       |              |             | 
Leonardo        |      √       |              |             | 
ESP32         |      √       |              |             | 
micro:bit        |      √       |              |             | 

## History

- Data 2019-12-10
- Version V1.0

## Credits

Written by(wenzheng.wang@dfrobot.com), 2019. (Welcome to our [website](https://www.dfrobot.com/))





