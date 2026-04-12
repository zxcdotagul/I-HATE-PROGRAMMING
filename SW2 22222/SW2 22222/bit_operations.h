#ifndef _bit_operations_h_
#define _bit_operations_h_

/*#include */

/*prototypde functions for tasks*/
void swapHalfWord(unsigned int* words); //< task1
void cycleShift(int* number, int N, int left); //< task2 
int getMaxBit(const int* array, int N); //< task3  
unsigned char getCount1Bit(int number); //< task4 


void cycleShiftArray(int* array, int size, int N, bool left);	//< task1 SW_3
void setBit(int* number, int numBit); //< task2 SW_3   
void clearBit(int* number, int numBit); //< task3 SW_3 

#endif

