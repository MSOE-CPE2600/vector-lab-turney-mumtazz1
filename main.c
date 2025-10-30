/***********************************************************************
 * @file main.c
 * @brief Main source file which executes the interface for calculator
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

 #include "interface.h"
 #include "vect_ops.h"

 int main(int argc, char* argv[]){
    //allocate the vectors dynamic array
    allocate();
    user_interface(argc, argv);
    //free the vectors dynamic array
    deallocate();
    return 0;
 }
 