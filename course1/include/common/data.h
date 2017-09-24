/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file data.h
 * @brief Abstraction of data type conversion operations
 *
 * This header file provides an abstraction of converting strings to integers
 * vice versa via function calls. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#ifndef __DATA_H__
#define __DATA_H__

/**
 * @brief Converts data from standard integer type to ASCII string 
 *
 * Given a data value function converts data to ASCII string, and stores in 
 * location  provided.
 *
 * @param base number base of data value
 * @param ptr Pointer to converted character string
 * @param data Data value
 *
 * @return length Length of converted data.
 */
uint8_t my_itoa(uint32_t data, uint8_t *ptr, uint32_t base);

/**
 * @brief Converts data from ASCII string type to standard integer 
 *
 * Given an ASCII string, function converts string to standard interger 
 * and stores in the location  provided.
 *
 * @param ptr Pointer to character string to convert
 * @param digits number of digits of character set 
 * @param base number base of converted string
 *
 * @return *ptr interger value of ASCII string.
 */
int32_t my_atoi(uint8_t *ptr, uint8_t digits, uint32_t base);



#endif /* __DATA_H__ */
