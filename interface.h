/***********************************************************************
 * @file interface.h
 * @brief Header file which declares the interface function
 * Course: CPE2600
 * Assignment: Lab 5
 * Author: Zoya Mumtaz
 * Date: 9/30/2025
 * Version: 1.0
 * Note: compile with
 *     $ make
 *     run with
 *     $ ./vectcalc
 ***********************************************************************/

 
#ifndef INTERFACE_H

#define INTERFACE_H

/**
* @brief handles the operations for the interface of the calculator
* @param argc for the number of arguments
* @param argv array of arguments
* @return 0;
*/
int user_interface(int argc, char* argv[]);

#endif /*INTERFACE_H*/