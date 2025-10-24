/***********************************************************************
 * @file main.c
 * @brief Main source file which executes the interface for calculator
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

 #include "interface.h"
 #include "vect_ops.h"

 int main(int argc, char* argv[]){
  allocate();
  user_interface(argc, argv);
  deallocate();
  return 0;
 }
 