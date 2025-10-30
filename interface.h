/***********************************************************************
 * @file interface.h
 * @brief Header file which declares the interface function
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

 
#ifndef INTERFACE_H

#define INTERFACE_H

/**
* @brief checks if a string is a valid float value for x, y, z
* @param string that needs to be checked
* 1 if it is a float, 0 if not
*/
int is_number(const char *string);

/**
* @brief handles the operation for loading a csv file
* into the dynamic array
* @param file_ptr points to the csv file
*/
void load(char *filename);

/**
* @brief handles the operation for saving the vectors in
* a csv file from the dynamic array
* @param filename of the csv file, given by user input
*/
void save(char *filename);

/**
* @brief handles the operations for the interface of the calculator
* @param argc for the number of arguments
* @param argv array of arguments
*/
void user_interface(int argc, char* argv[]);


#endif /*INTERFACE_H*/