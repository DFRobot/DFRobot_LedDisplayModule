# DFRobot_LedDisplayModule
  * [中文版](./README_CN.md)
这是一个4位/ 8位数码管。 它通过IIC与主机通信，显示0 ~ 9的数字，大写字母A、B、C、D、E、F、H、L、O、P、U和破折号。   <br>
4位数码管的IIC地址默认为0x48。 <br>
8位数码管的IIC地址默认为0xE0。 该地址可以用显示器背面的2个焊点的不同组合来更改为0xE2、0xE4、0xE6。 <br>

![Product Image](./resources/images/DFR0646.png)

## 产品链接 (https://www.dfrobot.com.cn/goods-2601.html)

    SKU: DFR0646

## 目录
  - [概述](#概述)
  - [库安装](#库安装)
  - [方法](#方法)
  - [兼容性](#兼容性)
  - [版本](#版本)
  - [创作者](#创作者)

## 概述
这是一个Arduino IDE库，帮助实现4位/8位数码管与Arduino之间的通信  
该库简化了IIC对显示的控制  <br>

## 库安装

使用此库前，请首先下载库文件，将其粘贴到\Arduino\libraries目录中，然后打开examples文件夹并在该文件夹中运行演示。
## 方法

```C++
  /**
   * @fn begin4
   * @brief  the 4 bits digital tube
   * @return Return 0 if the initialization is successful, otherwise return non-zero
   */
  int begin4();
  
  /**
   * @fn begin8
   * @brief Initialize the 8 bits digital tube
   * @return Return 0 if the initialization is successful, otherwise return non-zero
   */ 
  int begin8();

  /**
   * @fn displayOn
   * @brief Turn ON the display
   * @param IIC command to turn ON the display
   * @return None
   */
  void displayOn();
  
  /**
   * @fn displayOff
   * @brief Turn OFF the display 
   * @param IIC command to turn OFF the display
   * @return None
   */  
  void displayOff();

  /**
   * @fn flashTwos
   * @brief Flash mode of the 8 bits digital tube, flash at 0.5Hz
   * @param IIC flash command
   * @return None
   */
  void flashTwos();
  
  /**
   * @fn flashOnes
   * @brief Flash mode of the 8 bits digital tube, flash at 1Hz
   * @param IIC flash command
   * @return None
   */
  void flashOnes();
  
  /**
   * @fn flashHalfs
   * @brief Flash mode of the 8 bits digital tube, flash at 2Hz
   * @param IIC flash command
   * @return None
   */
  void flashHalfs();
  
  /**
   * @fn stopFlash
   * @brief The 8 bits digital tube stops flash 
   * @param IIC command to stop flash
   * @return None
   */
  void stopFlash();

  /**
   * @fn setBrightness4
   * @brief Set brightness of the 4 bits digital tube
   * @param The brightness value can be set to numbers 1~8
   * @return None
   */
  void setBrightness4(int brightnessValue); 
  
  /**
   * @fn setBrightness8
   * @brief Set brightness of the 8 bits digital tube
   * @param The brightness value can be set to numbers 1~16
   * @return None
   */
  void setBrightness8(int brightnessValue);

  /**
   * @fn setDisplayArea4
   * @brief Display area of the 4 bits digital tube
   * @param Display area from the first bit to the fourth bit could be number 1~4.
   * @return None
   */
  void setDisplayArea4(int areaData1 = 82,int areaData2 = 82,int areaData3 = 82,int areaData4 = 82);

  /**
   * @fn setDisplayArea8
   * @brief Display area of the 8 bits digital tube
   * @param Display area from the first bit to the eighth bit could be number 1~8
   * @return None
   */
  void setDisplayArea8(int areaData1 = 82,int areaData2 = 82,int areaData3 = 82,int areaData4 = 82,int areaData5 = 82,int areaData6 = 82,int areaData7 = 82,int areaData8 = 82);

  /**
   * @fn print4
   * @brief Print data of the 4 bits digital tube
   * @param It could be both integer and decimal
   * @return None
   */  
  void print4(double sensorData);
  
  /**
   * @fn print4
   * @brief 4Print data of the 4 bits digital tube
   * @param print4 Displayed data of bit 1 to bit 4 could be the numbers 0 to 9, capital letters A, B, C, D, E, F, H, L, O, P, U and dash-,
   * @n and it also could be decimal points, such as "0." "9." "A." "-."
   * @return None
   */
  void print4(const char buf1[] = "82",const char buf2[] = "82",const char buf3[] = "82",const char buf4[] = "82");

  /**
   * @fn print8
   * @brief Print data of the 8 bits digital tube
   * @param could be both integer and decimal
   * @return None
   */
  void print8(double sensorData);
  
  /**
   * @fn print8
   * @brief Print data of the 8 bits digital tube
   * @param print8 Displayed data of bit 1 to bit 8 could be the numbers 0 to 9, capital letters A, B, C, D, E, F, H, L, O, P, U and dash-,
   * @n and it also could be decimal points, such as "0." "9." "A." "-."
   * @return None
   */
    void print8(const char buf1[] = "82",const char buf2[] = "82",const char buf3[] = "82",const char buf4[] = "82",const char buf5[] = "82",const char buf6[] = "82",const char buf7[] = "82",const char buf8[] = "82");
```

## 兼容性

MCU                | Work Well    | Work Wrong   | Untested    | Remarks
------------------ | :----------: | :----------: | :---------: | -----
Arduino Uno        |      √       |              |             | 
Mega2560        |      √       |              |             | 
Leonardo        |      √       |              |             | 
ESP32         |      √       |              |             | 
micro:bit        |      √       |              |             | 

## 版本

- 2019/12/10 - V1.0.0版本
- 2022/03/21 - V1.0.1版本

## 创作者

Written by(wenzheng.wang@dfrobot.com), 2019. (Welcome to our [website](https://www.dfrobot.com/))





