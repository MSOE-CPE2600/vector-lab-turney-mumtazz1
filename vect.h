/***********************************************************************
 * @file vect.h
 * @brief Header file which declares the vector structure
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


#ifndef VECT_H

#define VECT_H

/**
* @brief struct for a vector, containing its name, x, y, and z
*/
typedef struct vect {
    float x;
    float y;
    float z;
    char varname[50];
} vect;

#endif  /*VECT_H*/


