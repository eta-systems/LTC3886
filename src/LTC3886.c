

#include "main.h"
#include "ltc3886.h"

/**
 * @brief      writes a single value into a LTC3886 register
 * @param      *chip, pointer to the LTC3886 typedef struct
 * @param      reg, the destination register's address
 * @param      val, the value for the destination register
 */
uint8_t LTC3886_Write8(LTC3886 *chip, uint8_t reg, uint8_t val){
 	if(HAL_I2C_Mem_Write(chip->wireIface, chip->devAddress, reg, 1, &val, 1, 10) != HAL_OK) 
		return 1;
	return 0;
}

/**
 * @brief       reads a single value from a LTC3886 register
 * @param       *chip, pointer to the LTC3886 typedef struct
 * @param       reg, the destination register's address
 * @param       val, pointer to the location where the value shall be stored
 * @return      0 on success, 1 on transmission error
 */
uint8_t LTC3886_Read8(LTC3886 *chip, uint8_t reg, uint8_t *val){
	if(HAL_I2C_Mem_Read(chip->wireIface, chip->devAddress, reg, 1, val, 1, 10) != HAL_OK) 
		return 1;
	return 0;
}

/**
 * @brief      writes a 2 byte word value into a LTC3886 register
 * @param      *chip, pointer to the LTC3886 typedef struct
 * @param      reg, the destination register's address
 * @param      val, the value for the destination register
 */
uint8_t LTC3886_Write16(LTC3886 *chip, uint8_t reg, uint16_t val){
	uint8_t high_low_byte[2];
	high_low_byte[1] = (uint8_t)(val >> 8);   // high byte second
	high_low_byte[0] = (uint8_t)(val & 0xFF); // low byte first
 	if(HAL_I2C_Mem_Write(chip->wireIface, chip->devAddress, reg, 1, high_low_byte, 2, 10) != HAL_OK) 
		return 1;
	return 0;
}

/**
 * @brief      writes a 2 byte word value into a LTC3886 register
 * @param      *chip, pointer to the LTC3886 typedef struct
 * @param      reg, the destination register's address
 * @param      val, the value for the destination register
 */
/*
uint8_t LTC3886_Write16(LTC3886 *chip, uint8_t reg, uint8_t highbyte, uint8_t lowbyte){
	uint8_t high_low_byte[2];
	high_low_byte[1] = highbyte;   // high byte second
	high_low_byte[0] = lowbyte;    // low byte first
 	if(HAL_I2C_Mem_Write(chip->wireIface, chip->devAddress, reg, 1, high_low_byte, 2, 10) != HAL_OK) 
		return 1;
	return 0;
}
*/

/**
 * @brief       reads a w byte word value from a LTC3886 register
 * @param       *chip, pointer to the LTC3886 typedef struct
 * @param       reg, the destination register's address
 * @param       val, pointer to the location where the value shall be stored
 * @return      0 on success, 1 on transmission error
 */
uint8_t LTC3886_Read16(LTC3886 *chip, uint8_t reg, uint16_t *val){
	uint8_t high_low_byte[2] = {0, 0};
	HAL_I2C_Mem_Read(chip->wireIface, chip->devAddress, reg, 1, high_low_byte, 2, 10);
	*val = (uint16_t)( (high_low_byte[1] << 8) | (high_low_byte[0]) );
	return 0;
}

/**
  * @brief 		Initalizer function
  * @param 		*chip, pointer to the LTC3886 typedef struct
  * @param 		*wireIface a pointer to a HAL I2C_HandleTypeDef
  * @param 		address of the chip on the I2C bus
  */
uint8_t LTC3886_Init(LTC3886 *chip, I2C_HandleTypeDef *wireIface, uint16_t address){
	chip->wireIface = wireIface;
	chip->devAddress = address;
	return 0;
}
