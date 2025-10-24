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
 #include <stdlib.h>

 //using a dynamic array
 static vect *vectors = NULL;
 static int size = 20;
 static int vect_count = 0;

 void allocate(void){
    if (vectors == NULL){
        vectors = (vect*)malloc(sizeof(vect) * size);
        if (vectors == NULL){ //if it is still NULL
            puts("Malloc() failed.");
            return;
        }
    }
 }

 void deallocate(void){
    if (vectors != NULL){
        free(vectors);
        vectors = NULL;
    }
}

 int add_new_vect(vect new){
    for(int i = 0; i < vect_count; i++){
        //if vector already exists, replace its values
        if (strcmp(new.varname, vectors[i].varname) == 0){
            vectors[i].x = new.x;
            vectors[i].y = new.y;
            vectors[i].z = new.z;
            return 1;
        }
    }
    //add new vector if not already in the storage
    if (vect_count < size){
        vectors[vect_count] = new;
        vect_count++;
        return 1;
    } else if (vect_count == size){
        //Reallocate to increase the size of the dynamic array
        size = size * 2;
        vect *temp_vects = (vect*)realloc(vectors, size * sizeof(vect));
        if (temp_vects == NULL) {
            perror("Realloc() failed");
            size = size / 2; //return to original size
            return 0;
        }
        vectors = temp_vects; 
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

void list(void){
    for(int i=0; i<vect_count; i++){
        printf("%5s : %0.4f, %0.4f, %0.4f\n", vectors[i].varname, vectors[i].x, vectors[i].y, vectors[i].z);
    }
}

vect* findvect(const char* input){
    for (int i = 0; i<vect_count; i++){
        if (strcmp(vectors[i].varname, input) == 0){
            return &vectors[i]; //return the vector found
        }
    }
    return NULL; //if vector is not found
}

vect* findvect2(int index){
    if (index < vect_count){
        return &vectors[index]; //return the vector found
    } else {
        return NULL; //if vector is not found
    }
}

void print_vect(vect vec){
    printf("%s : %0.4f, %0.4f, %0.4f\n", vec.varname, vec.x, vec.y, vec.z);
}

void clear(void){
    deallocate();
    vectors = NULL;
    vect_count = 0;
    puts("The calculator storage has been cleared.");

}

int get_vect_count(void){
    return vect_count;
}

void help(void){
    puts("To load a csv file, enter 'load' and the name of the file.");
    puts("(Ex: [load list.csv] or you may enter the relative or absolute path, without spaces)");
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
    puts("To save the current vectors in a new csv file, enter 'save' and the name of the new file.");
    puts("Ex: [save new] OR [save new.csv] (Note: An existing file with the same name will be overwritten.)");
    puts("To exit the vector calculator program, enter 'quit'.");
}



