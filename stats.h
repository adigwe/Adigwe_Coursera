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
 * 
 * print_array();
 * sort_array();
 * print_statistcs();
 * find_minimum();
 * find_maximum();
 * find_mean();
 * find_median();
 * 
 * 
 * 
 * @author Ikechukwu Adigwe
 * @date 10th July 2017
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 


 
/* Prints out the "test"  array to the screen */

  void print_array(int, unsigned char[]);


/* Sorts the "test" array in descending order */

  void sort_array(int, unsigned char[]);


/* Prints out the Minimum, Maximum, Mean, and Median values of the "test" array */

  void print_statistics(int, unsigned char[]);


/* Finds the smallest value in the "test" array */
 
  void find_minimum(int, unsigned char[]);


/* Finds the largest value in the "test" array */
  
  void find_maximum(int, unsigned char[]);


/* Calculates the mean value of the elements of the "test" array */

  unsigned char find_mean(int, unsigned char[]);


/* Calculates the median value of the elements of the "test" array */

  unsigned char find_median(int, unsigned char[]);


#endif /* __STATS_H__ */
