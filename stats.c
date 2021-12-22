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
 * @brief assignment-1 
 *
 * 
 *
 * @author Yuvraj Singh 
 * @date 21 December 2021
 *
 */

#include <stdio.h>
#include "stats.h"
/* Size of the Data Set , which is 40*/
#define SIZE (40)

/* ALL function declaration */
void print_statistics (unsigned char min, unsigned char max, float mean, unsigned char med);
void print_array (unsigned char *arr, unsigned int counter);
unsigned char find_median (unsigned char *arr, unsigned int counter);
float find_mean (unsigned char *arr, unsigned int counter);
unsigned char find_maximum (unsigned char *arr, unsigned int counter);
unsigned char find_minimum (unsigned char *arr, unsigned int counter);
void sort_array (unsigned char *arr, unsigned int counter);


int main() // main function 
{

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6, 
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90}; // test array 

  /* Other Variable Declarations Go Here */
  unsigned char min = 0; // initializing min = 0
  unsigned char max = 0; // initializing max = 0
  unsigned char med = 0; // initializing median = 0
  float mean = 0; // initializing mean = 0
  
  /* Statistics and Printing Functions Go Here */
  printf("Array without treatment : ");
  print_array(&test,SIZE);
  med = find_median(&test, SIZE);
  mean = find_mean(&test, SIZE);
  max = find_maximum(&test, SIZE);
  min = find_minimum(&test, SIZE);
  print_statistics(min, max, mean, med);
  sort_array(&test, SIZE);
  printf("Array after treatment (DESENDING) : ");
  print_array(&test, SIZE);
}

/* Add other Implementation File Code Here */
void print_statistics (unsigned char min, unsigned char max, float mean, unsigned char med) 
{
  printf("Minimum value is %d \n", min);
  printf("Maximum value is %d \n", max);
  printf("Median  value is %d \n", med);
  printf("Mean value is %f \n", mean);
  
}

void print_array (unsigned char *arr, unsigned int counter) // print_array function 
{
  for (int i=0 ; i<counter; i++) // traversing through array 
    {
    printf("%d", *(arr + i)); // printing elements of aray 
    if(i < SIZE-1)
    printf(", ");
    }
  printf("\n");
}

unsigned char find_median (unsigned char *arr, unsigned int counter) // function for finding median value 
{
  unsigned char med;
  med = *(arr + (counter/2) -1); // median formula 
  return med; // retuning median value 
}

float find_mean (unsigned char *arr, unsigned int counter) // function for finding mean value 
{
  unsigned int sm = 0;
  float mean;
  for (int i=0; i<counter; i++) // traversing through array 
    {
    sm = sm + arr[i]; // adding all element in array 
    }
  mean = sm / ((float) counter); // average = total sum / total elements 
  return mean; // retuning mean 
}

unsigned char find_maximum (unsigned char *arr, unsigned int counter) // function for finding maximum value in array "test"
{
  unsigned char max = *arr ; 
  for (int i=1; i<counter; i++) // traversing through array 
    { 
    if (*(arr + i) > max) // condition for checking maximum value 
    {
      max = *(arr + i); // putting maximum value in max 
    }
  }
  return max;
}

unsigned char find_minimum (unsigned char *arr, unsigned int counter) // function for finding minimum value in array "test"
{
  unsigned char min = *arr; 
  for (int i=1; i<counter; i++) // traversing through array 
    { 
    if (*(arr + i) < min) // condition for checking minimum value
      {
      min = *(arr + i); // putting minimum value in min 
    }
  }
  return min;
}

void sort_array (unsigned char *arr, unsigned int counter) // function for sorting elements in decending order
{
  char pt = 0; 
  unsigned char temp;
  do 
    {
    pt =0; 
    for (int i=0; i<counter; i++)
      {
      if ( arr[i] == arr[i+1] || arr[i] > arr[i+1]) 
        {
        continue;
      }
      else if (arr[i] < arr[i +1])  // loop for sorting elements in decending order 
      {                              
        temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
        pt = 1; 
      }
    }
  }
  while (pt ==1); 
}


