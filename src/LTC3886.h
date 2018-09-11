
/**
  * @file       ltc3886.h
  * @author     Simon Burkhardt github.com/mnemocron
  * @copyright  MIT license
  * @date       2018
  * @brief      C library for the LTC3886 Step-Down Controller for STM32 HAL.
  * @details
  * @see        github.com/eta-systems
  */


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LTC_3886_H
#define __LTC_3886_H

/**
  * @note  tested using STM32F373
  */
#ifndef STM32F3XX_H
#include "stm32f3xx_hal.h"
#endif

#ifndef STM32F3XX_HAL_I2C_H
#include "stm32f3xx_hal_i2c.h"
#endif

#ifndef MAIN_H
#include "main.h"
#endif

/**
  * @see Datasheet p. 35 - Table 2. Summary
  */

#define LTC3886_PAGE                            0x00
#define LTC3886_OPERATION                       0x01
#define LTC3886_ON_OFF_CONFIG                   0x02
#define LTC3886_CLEAR_FAULTS                    0x03
#define LTC3886_PAGE_PLUS_WRITE                 0x05
#define LTC3886_PAGE_PLUS_READ                  0x06
#define LTC3886_WRITE_PROTECT                   0x10
#define LTC3886_STORE_USER_ALL                  0x15
#define LTC3886_RESTORE_USER_ALL                0x16
#define LTC3886_CAPABILITY                      0x19
#define LTC3886_SMBALERT_MASK                   0x1B
#define LTC3886_VOUT_MODE                       0x20
#define LTC3886_VOUT_COMMAND                    0x21
#define LTC3886_VOUT_MAX                        0x24
#define LTC3886_VOUT_MARGIN_HIGH                0x25
#define LTC3886_VOUT_MARGIN_LOW                 0x26
#define LTC3886_VOUT_TRANSITION_RATE            0x27
#define LTC3886_FREQUENCY_SWITCH                0x33
#define LTC3886_VIN_ON                          0x35
#define LTC3886_VIN_OFF                         0x36
#define LTC3886_IOUT_CAL_GAIN                   0x38
#define LTC3886_VOUT_OV_FAULT_LIMIT             0x40
#define LTC3886_VOUT_OV_FAULT_RESPONSE          0x41
#define LTC3886_VOUT_OV_WARN_LIMIT              0x42
#define LTC3886_VOUT_UV_WARN_LIMIT              0x43
#define LTC3886_VOUT_UV_FAULT_LIMIT             0x44
#define LTC3886_VOUT_UV_FAULT_RESPONSE          0x45
#define LTC3886_IOUT_OC_FAULT_LIMIT             0x46
#define LTC3886_IOUT_OC_FAULT_RESPONSE          0x47
#define LTC3886_IOUT_OC_WARN_LIMIT              0x4A
#define LTC3886_OT_FAULT_LIMIT                  0x4F
#define LTC3886_OT_FAULT_RESPONSE               0x50
#define LTC3886_OT_WARN_LIMIT                   0x51
#define LTC3886_UT_FAULT_LIMIT                  0x53
#define LTC3886_UT_FAULT_RESPONSE               0x54
#define LTC3886_VIN_OV_FAULT_LIMIT              0x55
#define LTC3886_VIN_OV_FAULT_RESPONSE           0x56
#define LTC3886_VIN_UV_WARN_LIMIT               0x58
#define LTC3886_IIN_OC_WARN_LIMIT               0x5D
#define LTC3886_TON_DELAY                       0x60 
#define LTC3886_TON_RISE                        0x61 
#define LTC3886_TON_MAX_FAULT_LIMIT             0x62 
#define LTC3886_TON_MAX_FAULT_RESPONSE          0x63
#define LTC3886_TOFF_DELAY                      0x64 
#define LTC3886_TOFF_FALL                       0x65 
#define LTC3886_TOFF_MAX_WARN_LIMIT             0x66 
#define LTC3886_STATUS_BYTE                     0x78 
#define LTC3886_STATUS_WORD                     0x79 
#define LTC3886_STATUS_VOUT                     0x7A 
#define LTC3886_STATUS_IOUT                     0x7B
#define LTC3886_STATUS_INPUT                    0x7C 
#define LTC3886_STATUS_TEMPERATURE              0x7D 
#define LTC3886_STATUS_CML                      0x7E 
#define LTC3886_STATUS_MFR_SPECIFIC             0x80
#define LTC3886_READ_VIN                        0x88 
#define LTC3886_READ_IIN                        0x89 
#define LTC3886_READ_VOUT                       0x8B 
#define LTC3886_READ_IOUT                       0x8C 
#define LTC3886_READ_TEMPERATURE_1              0x8D 
#define LTC3886_READ_TEMPERATURE_2              0x8E 
#define LTC3886_READ_FREQUENCY                  0x95 
#define LTC3886_READ_POUT                       0x96 
#define LTC3886_READ_PIN                        0x97 
#define LTC3886_PMBUS_REVISION                  0x98 
#define LTC3886_MFR_ID                          0x99 
#define LTC3886_MFR_MODEL                       0x9A 
#define LTC3886_MFR_VOUT_MAX                    0xA5 
#define LTC3886_USER_DATA_00                    0xB0
#define LTC3886_USER_DATA_01                    0xB1
#define LTC3886_USER_DATA_02                    0xB2 
#define LTC3886_USER_DATA_03                    0xB3 
#define LTC3886_USER_DATA_04                    0xB4 
#define LTC3886_MFR_INFO                        0xB6
#define LTC3886_MFR_EE_UNLOCK                   0xBD 
#define LTC3886_MFR_EE_ERASE                    0xBE 
#define LTC3886_MFR_EE_DATA                     0xBF 
#define LTC3886_MFR_CHAN_CONFIG_LTC3886         0xD0
#define LTC3886_MFR_CONFIG_ALL_LTC3886          0xD1
#define LTC3886_MFR_FAULT_PROPAGATE_LTC3886     0xD2
#define LTC3886_MFR_PWM_COMP                    0xD3
#define LTC3886_MFR_PWM_MODE_LTC3886            0xD4
#define LTC3886_MFR_FAULT_RESPONSE              0xD5
#define LTC3886_MFR_OT_FAULT_RESPONSE           0xD6 
#define LTC3886_MFR_IOUT_PEAK                   0xD7 
#define LTC3886_MFR_ADC_CONTROL                 0xD8 
#define LTC3886_MFR_RETRY_DELAY                 0xDB 
#define LTC3886_MFR_RESTART_DELAY               0xDC 
#define LTC3886_MFR_VOUT_PEAK                   0xDD 
#define LTC3886_MFR_VIN_PEAK                    0xDE 
#define LTC3886_MFR_TEMPERATURE_1_PEAK          0xDF 
#define LTC3886_MFR_READ_IIN_PEAK               0xE1
#define LTC3886_MFR_CLEAR_PEAKS                 0xE3
#define LTC3886_MFR_READ_ICHIP                  0xE4 
#define LTC3886_MFR_PADS                        0xE5
#define LTC3886_MFR_ADDRESS                     0xE6 
#define LTC3886_MFR_SPECIAL_ID                  0xE7
#define LTC3886_MFR_IIN_CAL_GAIN                0xE8
#define LTC3886_MFR_FAULT_LOG_STORE             0xEA
#define LTC3886_MFR_FAULT_LOG_CLEAR             0xEC
#define LTC3886_MFR_FAULT_LOG                   0xEE 
#define LTC3886_MFR_COMMON                      0xEF 
#define LTC3886_MFR_COMPARE_USER_ALL            0xF0
#define LTC3886_MFR_TEMPERATURE_2_PEAK          0xF4 
#define LTC3886_MFR_PWM_CONFIG_LTC3886          0xF5
#define LTC3886_MFR_IOUT_CAL_GAIN_TC            0xF6 
#define LTC3886_MFR_RVIN                        0xF7 
#define LTC3886_MFR_TEMP_1_GAIN                 0xF8 
#define LTC3886_MFR_TEMP_1_OFFSET               0xF9
#define LTC3886_MFR_RAIL_ADDRESS                0xFA 
#define LTC3886_MFR_RESET                       0xFD





typedef struct {
  uint16_t devAddress;
  I2C_HandleTypeDef *wireIface;
} LTC3886;

uint8_t LTC3886_Init              (LTC3886 *chip, I2C_HandleTypeDef* wireIface, uint16_t address);
uint8_t LTC3886_Write8(LTC3886 *chip, uint8_t reg, uint8_t val);
uint8_t LTC3886_Read8(LTC3886 *chip, uint8_t reg, uint8_t *val);
uint8_t LTC3886_Write16(LTC3886 *chip, uint8_t reg, uint16_t val);
// uint8_t LTC3886_Write16(LTC3886 *chip, uint8_t reg, uint8_t highbyte, uint8_t lowbyte);
uint8_t LTC3886_Read16(LTC3886 *chip, uint8_t reg, uint16_t *val);

#endif /* __LTC_3886_H */
/************************ (C) COPYRIGHT ETA Systems *****END OF FILE****/

