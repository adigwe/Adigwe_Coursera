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
 * @file data.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of converting
 * strings to numeric values and vice-versa. 
 * 
 * @author Ikechukwu Adidwe
 * @date September 22 2017
 *
 */
#include <stdint.h>
#include <math.h>
#include "data.h"

/***********************************************************
 Function Definitions
***********************************************************/
uint8_t my_itoa(uint32_t data, uint8_t *ptr, uint32_t base){

  uint8_t *temp;
  int length = 0;
  int j = 1;
  int k;
  bool isNegative = false;
  

/* Handle 0 explicitly */
  if (data == 0)
  {
    
       *ptr++ = '0';
       *ptr = '\0';
       j++;

    
/* Return length of converted data */

  return j;
  } 

/* Negative numbers are handled only in base 10*/

  if (data < 0 && base == 10)
  {   
    isNegative = true;
    data = -data;

  }

/*process individual digits */

  while (data != 0)
  {
    uint32_t rem = data % base;

    if (rem > 9){

      *ptr++ = (rem-10) + 'a';
    }

    
    else{

      *ptr++ = rem + '0';
    }
    
    data = data / base;

    length++;
  }

/* If number is negative, append '-'*/

  if (isNegative)
    *ptr++ = '-';
    length++;

/* append string terminator*/

  *ptr = '\0'; 
  length++; 

/* reverse the string */
 
  for (k = 0; k < length/2; k++){
   
    *temp = *(ptr + (length-k-1));
    *(ptr + (length-k-1)) = *(ptr + k);
    *(ptr + k) = *temp;
  }
  return length;

}


int32_t my_atoi(uint8_t *ptr, uint8_t digits, uint32_t base){


int i;
int sign = 1;
int32_t num = 0;
uint8_t *ptr_p = ptr;

/* Handle negative numbers */

  if (*ptr == '-')
  {
    sign = -1;
    *ptr++;
  }

  if (base == 10)
  
    for (i = 0; i < digits; i++){
     
      num = num*base + (*ptr++) - '0';
      
    }

  return sign*num;

/*Process individual digits*/
  while (*ptr_p)
  {

    if (*ptr_p++ > 9){

      *ptr_p++ = *ptr_p++ - 'a' + 10;
    }
    
    else{

      *ptr_p++ = *ptr_p++ - '0';
    }

  }

  return *ptr;

}


 

  





