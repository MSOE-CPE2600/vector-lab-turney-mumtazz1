/***********************************************************************
 * @file vect.c
 * @brief Source file which implements functions and struct
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

 #include "vect_ops.h"
 #include <string.h>
 #include <stdio.h>

 #define MAX_VECTS 10

 static vect vectors[MAX_VECTS] = {0};
 static int vect_count = 0;

 int add_new_vect(vect new){
    for(int i = 0; i < 10; i++){
        //if vector already exists, replace its values
        if (strcmp(new.varname, vectors[i].varname) == 0){
            vectors[i].x = new.x;
            vectors[i].y = new.y;
            vectors[i].z = new.z;
            return 1;
        }
    }
    //add new vector if not already in the storage
    if (vect_count < MAX_VECTS){
        vectors[vect_count] = new;
        vect_count++;
        return 1;
    }
    return 0;
 }

vect addvect(vect a, vect b){
    vect result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    return result;
}

vect subvect(vect a, vect b){
    vect result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    return result;
}


vect multnum(vect a, float num){
    vect result;
    result.x = a.x * num;
    result.y = a.y * num;
    result.z = a.z * num;
    return result;
}

int list(void){
    for(int i=0; i<10; i++){
        printf("%5s : %0.4f, %0.4f, %0.4f\n", vectors[i].varname, vectors[i].x, vectors[i].y, vectors[i].z);
    }
    return 0;
}

vect* findvect(const char* input){
    for (int i = 0; i<vect_count; i++){
        if (strcmp(vectors[i].varname, input) == 0){
            return &vectors[i]; //return the vector found
        }
    }
    return NULL; //if vector is not found
}

void print_vect(vect vec){
    printf("%s : %0.4f, %0.4f, %0.4f\n", vec.varname, vec.x, vec.y, vec.z);
}

int clear(void){
    for(int i = 0; i<10; i++){
        vectors[i].varname[0] = '\0';
        vectors[i].x = 0.00;
        vectors[i].y = 0.00;
        vectors[i].z = 0.00;
        vect_count = 0;
    }
    puts("The calculator storage has been cleared.");
    return 0;

}

int help(void){
    puts("Enter the x, y, z values of a vector (Ex: a = 1, 2, 3)");
    puts("Or, enter a function to perform a math operation on two existing vectors (Ex: c = a + b)");
    puts("You may perform addition or subtraction with two vectors");
    puts("You may perform scalar multiplication with one vector and a number (Ex: b = a * 2)");
    puts("You may also perform an operation without storing its result in a vector (Ex: a + b)\n");
    puts("Note: the calculator can only hold 10 vectors at a time. Once storage is full, it must be cleared.");
    puts("Note: you can reassign values of an existing vector.");
    puts("Note: please add spaces between each term that is typed!\n");
    puts("To free space and restart, enter 'clear' to delete all created vectors");
    puts("To view the existing vectors, Enter 'list' to view all 10 vectors.");
    puts("To view a single vector, enter its name (Ex: b)");
    puts("To quit the vector calculator program, enter 'quit'.");
    return 0;
}

