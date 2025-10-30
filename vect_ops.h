/***********************************************************************
 * @file vect_ops.h
 * @brief Header file which declares functions with struct
 * Course: CPE2600
 * Assignment: Lab 7 - Updated Vector Calculator
 * Author: Zoya Mumtaz
 * Date: 9/30/2025
 * Version: 2.0
 * Note: compile with
 *     $ make
 *     run with
 *     $ ./vectcalc
 ***********************************************************************/

#ifndef VECT_OPS_H

#define VECT_OPS_H

#include "vect.h"

/**
* @brief adds a vector to the vectors array
* @param new vector
* @return 1 if successful and 0 if array is full
*/
int add_new_vect(vect new);

/**
* @brief handles the operations for adding 2 vectors
* @param a for the first vector
* @param b for the second vector
* @return the resulting vector
*/
vect addvect(vect a, vect b);

/**
* @brief handles the operations for subtracting 2 vectors
* @param a for the first vector
* @param b for the second vector
* @return the resulting vector
*/
vect subvect(vect a, vect b);

/**
* @brief handles the operations for scalar multipying 1 vector and a num
* @param a vector to perform operation on
* @param num for the first vector
* @return the resulting vector
*/
vect multnum(vect a, float num);


/**
* @brief handles the operations for printing a list of the vectors
* @return 0
*/
void list(void);

/**
* @brief handles the operations for finding one vector
* @param input name of the vector
* @return the vector or NULL if not found
*/
vect* findvect(const char* input);

/**
* @brief handles the operations for finding a vector
* but at a specified index of the dynamic array
* @param index of the array
* @return the vector or NULL if index is more than the count
*/
vect* findvect2(int index);

/**
* @brief handles the operations for printing a given vector
* @param vector to print
*/
void print_vect(vect vec);

/**
* @brief handles the operations for clearing the vectors array by setting all values to 0
*/
void clear(void);

/**
* @brief prints the intructions for using the vector calculator
*/
void help(void);

/**
* @brief retrieves the vect_count 
* @return the vect_count
*/
int get_vect_count(void);

/**
* @brief malloc() the dynamic array when the program begins
*/
void allocate(void);

/**
* @brief frees the pointer once the program has finished
*/
void deallocate(void);


#endif  /*VECT_OPS_H*/ 