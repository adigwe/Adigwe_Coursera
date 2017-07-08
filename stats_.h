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
 * @file   stats.h
 * @brief Includes function declarations of functions in stats.c
 *
 * This library includes function declarations for the following functions:
 * print_statistcs();
 * print_array();
 * find_median();
 * find_mean();
 * find_maximum();
 * find_minimum();
 * sort_array();
 * 
 * @author Ikechukwu Adigwe
 * @date 10th May 2017
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief print_statistcs() prints the statistics of an array including minimum,    * maximum, mean, and median
 *
 * The function takes two(2) input parameters - An unsigned char pointer to an n- * element data array,and an unsigned integer as the size of the array - and returns  * an unsigned char result from the function
 *
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 *
 * @return <Add Return Informaiton here>
 */

  void print_array(int, unsigned char[]);

  void sort_array(int, unsigned char[]);
  
  void find_minimum(int, unsigned char[]);
  
  void find_maximum(int, unsigned char[]);

  float find_mean(int, unsigned char[]);

#endif /* __STATS_H__ */
