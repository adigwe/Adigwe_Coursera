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
 * @file stats.c 
 * @brief Calculates and prints statistics data for an array of numbers
 *
 * This function calculates and prints statistics data, of an array of given numbers,   
 * to the screen
 *
 * @author Ikechukwu Adigwe
 * @date 4th July 2017
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150,  90,  92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  print_array(SIZE, test);
  
  sort_array(SIZE, test);
  
  find_minimum(SIZE, test);
  
  find_maximum(SIZE, test);

  
  printf("\nMean = %f\n",find_mean(SIZE, test));

  

}

/* Add other Implementation File Code Here */

  void print_array(int a, unsigned char b[]){

   int i;

    for (i = 0; i < a; i++){
      printf("\ntest[%d] = %d", i, b[i]);
    }
  }


  void sort_array(int n, unsigned char number[]){

   int i, a, j;

  for (i = 0; i < n; ++i)
    {
        for (j = i + 1; j < n; ++j)
        {
            if (number[i] < number[j])
            {
                a = number[i];
                number[i] = number[j];
                number[j] = a;
            }
        }
    }
    printf("\n\nThe numbers arranged in descending order are given below\n");
    for (i = 0; i < n; ++i)
    {
        printf("%d\n", number[i]);
    }
 }


  void find_minimum(int c, unsigned char d[]){

  unsigned char smallest;
  int i;

/*Consider first element as smallest */
   smallest = d[0];
  
  
   for (i = 0; i < c; i++) {
      if (d[i] < smallest) {
         smallest = d[i];
      }
   }
 
   /* Print out the Result */
   printf("\nSmallest Element : %d", smallest);

  }


  void find_maximum(int e, unsigned char f[]){

  unsigned char largest;
  int i;

/*Consider first element as largest */
   largest = f[0];
   
   for (i = 0; i < e; i++) {
      if (f[i] > largest) {
         largest = f[i];
      }
   }
 
   /* Print out the Result */
   printf("\nLargest Element : %d", largest);

  }

  float find_mean(int m, unsigned char p[]) {
    int sum=0, i;
    for(i=0; i<m; i++)
        sum+=p[i];
    return((float)sum/m);
  }


