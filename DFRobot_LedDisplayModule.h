/*!
 * @file DFRobot_LedDisplayModule.h
 * @brief Define the basic structure of class DFRobot_LedDisplayModule
 * @n This is a 4bits/8bits digital tube that controlled by IIC interface. 
 * @n And the IIC address of 8bits digital tube can be changed by hardware
 * @n The main functions of the digital tube is as below:
 * @n Show 4bits / 8bot numbers and decimal points
 * @n At present, it only supports showing the numbers 0 to 9, capital letters A, B, C, D, E, F, H, L, O, P, U and dash-,
 * @n And you can also bring decimal points, such as "0." "9." "A." "-."
 *
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence     The MIT License (MIT)
 * @author [Actor](wenzheng.wang@dfrobot.com)
 * @version  V1.0
 * @date  2019-12-10
 * @https://github.com/DFRobot/DFRobot_LedDisplayModule
 */
#ifndef __DFRobot_LedDisplayModule_H__
#define __DFRobot_LedDisplayModule_H__

#include "Arduino.h"
#include <Wire.h>

//Define DBG, change 0 to 1 open the DBG, 1 to 0 to close  
#if 0
#define DBG(...) {Serial.print("["); Serial.print(__FUNCTION__); Serial.print("(): "); Serial.print(__LINE__); Serial.print(" ] "); Serial.println(__VA_ARGS__);}
#else
#define DBG(...)
#endif

#if 0
#define DBGI(...) {Serial.print("["); Serial.print(__FUNCTION__); Serial.print("(): "); Serial.print(__LINE__); Serial.print(" ] "); Serial.println(__VA_ARGS__);}
#else
#define DBGI(...)
#endif

#define CMD_HT16K33_OSCOFF      0x20  /**< Turn OFF the clock */
#define CMD_HT16K33_OSCON       0x21  /**< Turn ON the clock */
#define CMD_HT16K33_DISPLAYOFF  0x80  /**< Turn OFF the display */
#define CMD_HT16K33_DISPLAYON   0x81  /**< Turn ON the display*/
#define CMD_HT16K33_FLASHTWOS   0x87  /**< Set the mode to flash at 0.5Hz*/
#define CMD_HT16K33_FLASHONES   0x85  /**< Set the mode to flash at 1Hz*/
#define CMD_HT16K33_FLASHHALFS  0x83  /**< Set the mode to flash at 2Hz*/
#define CMD_HT16K33_STOPFLASH   0x81  /**< Flash end*/

class DFRobot_LedDisplayModule
{
public:  
  #define ERR_OK             0      //ok
  #define ERR_ADDR          -1      //error in I2C address  
    
public:
 /**
   * @brief Constructor
   * @param pWire I2C bus pointer object. When calling the function, you may transfer a parameter into it. Defaule as Wire
   * @param addr 8 bits I2C address, the IIC address of 4 bits digital tube in default is 0x48, The IIC address of 8 bits digital tube can be changed by combining A1 and A0
   * @n In default, the IIC address of 8 bits digital tube is 0xE0
   * 1  1  1  0  | 0  A1 A0 0
     1  1  1  0  | 0  0  0  0    0xE0
     1  1  1  0  | 0  0  1  0    0xE2
     1  1  1  0  | 0  1  0  0    0xE4
     0  0  1  0  | 0  1  1  0    0xE6
   */ 
  DFRobot_LedDisplayModule(TwoWire &wire, uint8_t ledAddress);

  /*!
   *  @brief  the 4 bits digital tube
   *  @return Return 0 if the initialization is successful, otherwise return non-zero
   */
  int begin4();
  
  /*!
   *  @brief Initialize the 8 bits digital tube
   *  @return Return 0 if the initialization is successful, otherwise return non-zero
   */ 
  int begin8();

  /*!
   *  @brief Turn ON the display
   *  @param IIC command to turn ON the display
   */
  void displayOn();
  
  /*!
   *  @brief Turn OFF the display 
   *  @param IIC command to turn OFF the display
   */  
  void displayOff();

  /*!
   *  @brief Flash mode of the 8 bits digital tube, flash at 0.5Hz
   *  @param IIC flash command
   */
  void flashTwos();
  
  /*!
   *  @brief Flash mode of the 8 bits digital tube, flash at 1Hz
   *  @param IIC flash command
   */
  void flashOnes();
  
  /*!
   *  @brief Flash mode of the 8 bits digital tube, flash at 2Hz
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
   *  @brief Display area of the 4 bits digital tube
   *  @param Display area from the first bit to the fourth bit could be number 1~4.
   */
  void setDisplayArea4(int areaData1 = 82,int areaData2 = 82,int areaData3 = 82,int areaData4 = 82);

  /*!
   *  @brief Display area of the 8 bits digital tube
   *  @param Display area from the first bit to the eighth bit could be number 1~8
   */
  void setDisplayArea8(int areaData1 = 82,int areaData2 = 82,int areaData3 = 82,int areaData4 = 82,int areaData5 = 82,int areaData6 = 82,int areaData7 = 82,int areaData8 = 82);

  /*!
   *  @brief Print data of the 4 bits digital tube
   *  @param It could be both integer and decimal
   */  
  void print4(double sensorData);
  
  /*!
   *  @brief 4Print data of the 4 bits digital tube
   *  @param 
   *  @n Displayed data of bit 1 to bit 4 could be the numbers 0 to 9, capital letters A, B, C, D, E, F, H, L, O, P, U and dash-,
   *  @n and it also could be decimal points, such as "0." "9." "A." "-."
   */
  void print4(const char buf1[] = "82",const char buf2[] = "82",const char buf3[] = "82",const char buf4[] = "82");

  /*!
   *  @brief Print data of the 8 bits digital tube
   *  @param could be both integer and decimal
   */
  void print8(double sensorData);
  
  /*!
   *  @brief Print data of the 8 bits digital tube
   *  @param 
   *  @n Displayed data of bit 1 to bit 8 could be the numbers 0 to 9, capital letters A, B, C, D, E, F, H, L, O, P, U and dash-,
   *  @n and it also could be decimal points, such as "0." "9." "A." "-."
   */
    void print8(const char buf1[] = "82",const char buf2[] = "82",const char buf3[] = "82",const char buf4[] = "82",const char buf5[] = "82",const char buf6[] = "82",const char buf7[] = "82",const char buf8[] = "82");

private:
  TwoWire *_pWire;
  uint8_t _ledAddress;  /**< IIC Address */
  int displayAreaFlag;  /**< Display area flag */
  int data1,data2,data3,data4,data5,data6,data7,data8;  /**< Display data buffer*/
  unsigned char ledData1,ledData11,ledData2,ledData22,ledData3,ledData33,ledData4,ledData44,ledData5,ledData55,ledData6,ledData66,ledData7,ledData77,ledData8,ledData88;  /**< Input data buffer */
  
  int d11;
  int d21,d22;
  int d31,d32,d33;
  int d41,d42,d43,d44;  
  int d51,d52,d53,d54,d55;
  int d61,d62,d63,d64,d65,d66;
  int d71,d72,d73,d74,d75,d76,d77;
  int d81,d82,d83,d84,d85,d86,d87,d88;   /**< Display area data buffer*/

  int d1,d2,d3,d4,d5,d6,d7;
  int a1,a2,a3,a4,a5,a6,a7;  /**< Display address data buffer*/

  const unsigned char TAB2[38]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  /**< 0~9 */
                                0x77,0x7C,0x39,0x5E,0x79,0x71,  /**< A~F */
                                0x00,
                                0x76,                /**< H */
                                0x00,0x00,0x00,
                                0x38,                /**< L */
                                0x00,0x00,0x5C,      /**< O */
                                0x73,                /**< P */
                                0x00,0x00,0x00,0x40, /**< - */
                                0x3E};               /**< U */                                                                   /**< Display data */
                 
  const unsigned char TAB_Point2[38]={0xBF,0x86,0xDB,0xCF,0xE6,0xED,0xFD,0x87,0xFF,0xEF,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
                                      0xF7,0xFC,0xB9,0xDE,0xF9,0xF1, 
                                      0x00,
                                      0xF6,
                                      0x00,0x00,0x00,
                                      0xB8,
                                      0x00,0x00,0xDC,
                                      0xF3,
                                      0x00,0x00,0x00,0xC0,
                                      0xBE};                                                                                     /**< Display data, light up the decimal point*/
  
  /*!
   *  @brief Send IIC command
   *  @param IIC command
   */
  void i2cWriteCmd(uint8_t cmd);
  
  /*!
   *  @brief The 8-bit digital tube sends IIC data 
   *  @param Register address
   *  @param IIC data
   */
  void i2cWriteData(uint8_t reg,uint8_t data);
  
  /*!
   *  @brief 4-bit digital tube to send IIC data
   *  @param Register address
   *  @param IIC data
   */
  void i2cWriteData4(uint8_t reg,uint8_t data);

 /*!
  *  @brief Reset the print buffer area 
  */
  void printCacheReset();
  
  /*!
   *  @brief Get display date of bit 1 to bit 8 from the user input
   */
  void  getDisplayData();

  /*!
   *  @brief The 4bits digital tube to get the display address
   */
  void getDisplayAddress41();
  void getDisplayAddress42();
  void getDisplayAddress43(); 
  
  /*!
   *  @brief The 8bits digital tube to get the display address
   */
  void getDisplayAddress81();
  void getDisplayAddress82();
  void getDisplayAddress83();
  void getDisplayAddress84();
  void getDisplayAddress85();
  void getDisplayAddress86();
  void getDisplayAddress87();

  /*!
   *  @brief The 4bits digital tube to get the display address(sensor data mode)
   */
  void sensorGetDisplayAddress4();
   
  /*!
   *  @brief The 8bits digital tube to get the display address(sensor data mode)
   */
  void sensorGetDisplayAddress8();
  
  /**
   * @brief I2C address detection
   * @param addr I2C address
   * @return Return 0 if IIC address is set correctly, otherwise return non-zero. 
   */
  int i2cdetect(uint8_t _ledAddress);
};

#endif