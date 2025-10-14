/***********************************************************************
 * @file interface.c
 * @brief Source file which implements the user interface
 * Course: CPE2600
 * Assignment: Lab 5 - Vector Calculator
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
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 #include <stdbool.h>


 int user_interface(int argc, char* argv[]){
    int instructions;

    puts("Welcome to the 3D Vector Calculator!");

    if (argc == 2 && strcmp(argv[1], "-h") == 0){ //read argument
        puts("Instructions:");
        instructions = help();//run the initial instructions
    }
   
    int run = 0;
    char user_input[100]; //user input string
    char *tokens[100]; //array of pointers, with pointer for each token
    int token_count;
 
    while (run == 0){
        //---------------------- String tokenization ----------------------------------------
        token_count = 0; //clear the tokens, if any

        printf("\nVectCalc> ");
        fgets(user_input, 50, stdin);
        
        int j = 0;
        while (user_input[j] != '\n' && user_input[j] != '\0'){
            j++;
        }
        user_input[j] = '\0'; //set the last character of the input to null terminator

        char *token = strtok(user_input, " ,"); //ignore commas and spaces

        while (token != NULL && token_count < 100){ //tokenize the string
            tokens[token_count] = token; //store current token to tokens array
            token_count++;
            token = strtok(NULL, " ,"); //get the next token
        }
        
        //-------------------- If user types only one token ---------------------------------
        if (token_count == 1){
            if (strcmp(tokens[0], "list") == 0){
                list();
            } else if (strcmp(tokens[0], "quit") == 0){
                run = 1;
            } else if (strcmp(tokens[0], "help") == 0){
                instructions = help();
            } else if (strcmp(tokens[0], "clear") == 0){
                int clr = clear();
            } else { //print out the information of the given vector name, if found
                vect *ref;
                ref = findvect(tokens[0]);
                if (ref == NULL){
                    puts("There is no such vector in the storage.");
                } else {
                    print_vect(*ref);
                }
            }
        }

        //-------------------- If user types many tokens --------------------------------------
        if (token_count > 1){ 
            //-------------- Input has an equal operation, so store the resulting vector ------
            if (strcmp(tokens[1], "=") == 0){
                //the process is repeated for each operation 
                if (strcmp(tokens[3], "+") == 0){ //for addition
                    vect *a;
                    vect *b;
                    a = findvect(tokens[2]);
                    b = findvect(tokens[4]);
                    if (a != NULL && b != NULL){ //make sure the given vectors exist in storage array
                        vect sum = addvect(*a, *b);
                        strcpy(sum.varname, tokens[0]); //set the varname
                        int added = add_new_vect(sum); //add the vector to the storage array
                        if (added == 1){
                            print_vect(sum); //print out the added vector's information
                        } else if (added == 0){
                            puts("Error: There is no more storage in the calculator. Please enter 'clear'.");
                        }
                    } else {
                        puts("Error: invalid input(s). Please try again.");
                    }     
                } else if (strcmp(tokens[3], "-") == 0){ //for subtraction
                    vect *a;
                    vect *b;
                    a = findvect(tokens[2]);
                    b = findvect(tokens[4]);
                    if (a != NULL && b != NULL){ 
                        vect difference = subvect(*a, *b);
                        strcpy(difference.varname, tokens[0]);
                        int added = add_new_vect(difference);
                        if (added == 1){
                            print_vect(difference);
                        } else if (added == 0){
                            puts("Error: There is no more storage in the calculator. Please enter 'clear'.");
                        }
                    } else {
                        puts("Error: invalid input(s). Please try again.");
                    }

                } else if (strcmp(tokens[3], "*") == 0 && atof(tokens[4]) == 0 && atof(tokens[2]) == 0){ //if multiplying 2 vectors, not an operation
                    puts("Error: Operation is not allowed. Please try again.");
                } else if (strcmp(tokens[3], "*") == 0 && atof(tokens[4]) != 0){ //multiplying a vector with a number
                    vect *a;
                    float num = atof(tokens[4]);
                    a = findvect(tokens[2]);
                    if (a != NULL){
                        vect product = multnum(*a, num);
                        strcpy(product.varname, tokens[0]);
                        int added = add_new_vect(product);
                        if (added == 1){
                            print_vect(product);
                        } else if (added == 0){
                            puts("Error: There is no more storage in the calculator. Please enter 'clear'.");
                        }
                    } else {
                        puts("Error: invalid input(s). Please try again.");
                    }
                } else if (strcmp(tokens[3], "*") == 0 && atof(tokens[2]) != 0){ //multiplying a number with a vector
                    vect *a;
                    float num = atof(tokens[2]);
                    a = findvect(tokens[4]);
                    if (a != NULL){
                        vect product = multnum(*a, num);
                        strcpy(product.varname, tokens[0]);
                        int added = add_new_vect(product);
                        if (added == 1){
                            print_vect(product);
                        } else if (added == 0){
                            puts("Error: There is no more storage in the calculator. Please enter 'clear'.");
                        }
                    } else {
                        puts("Error: invalid input(s). Please try again.");
                    }
                } else {
                    //-------------------- Add/Replace a vector in storage ------------------------------------
                    if (token_count == 5){ //input must have x, y, and z only
                        char name[50];
                        strcpy(name, tokens[0]);
                        char two = tokens[2][0]; //validate that the x y and z values are numbers by retrieving their first character
                        char three = tokens[3][0];
                        char four = tokens[4][0];
                        bool valid = two > 47 && two < 58; //validating that the char is a number using ascii values
                        bool valid2 = three > 47 && three < 58;
                        bool valid3 = four > 47 && four < 58;
                        if (valid && valid2 && valid3){
                            //convert token to float
                            float x_val = atof(tokens[2]);
                            float y_val = atof(tokens[3]);
                            float z_val = atof(tokens[4]);
                            vect new;
                            strcpy(new.varname, name);
                            new.x = x_val;
                            new.y = y_val;
                            new.z = z_val;
                            int added = add_new_vect(new); //add the vector to storage
                            if (added == 1){
                                print_vect(new);
                            } else if (added == 0){
                                puts("Error: There is no more storage in the calculator. Please enter 'clear'.");
                            } 
                        } else {
                            puts("Invalid value(s) entered. Please try again.");
                        }  
                    } else {
                        puts("Please enter the x, y, z values of the vector.");
                    }
                }

            //------------ For doing an operation but not storing its result -----------------------   
            } else if (strcmp(tokens[1], "+") == 0){ //addition
                vect *a;
                vect *b;
                a = findvect(tokens[0]);
                b = findvect(tokens[2]);
                if (a != NULL && b != NULL){
                    vect sum = addvect(*a, *b);
                    strcpy(sum.varname, "Operation");
                    print_vect(sum);
                } else {
                    puts("Error: invalid input(s). Please try again.");
                }        
            } else if (strcmp(tokens[1], "-") == 0){ //subtraction
                vect *a;
                vect *b;
                a = findvect(tokens[0]);
                b = findvect(tokens[2]);
                if (a != NULL && b != NULL){
                    vect difference = subvect(*a, *b);
                    strcpy(difference.varname, "Operation");
                    print_vect(difference);
                } else {
                    puts("Error: invalid input(s). Please try again.");
                }        
            } else if (strcmp(tokens[1], "*") == 0 && atof(tokens[2]) == 0 && atof(tokens[0]) == 0){ //multiplying two vectors is wrong
                puts("Error: Operation is not allowed. Please try again.");     
            } else if (strcmp(tokens[1], "*") == 0 && atof(tokens[2]) != 0){ //multiplying a vector and num
                vect *a;
                float num = atof(tokens[2]);
                a = findvect(tokens[0]);
                if (a != NULL){
                    vect product = multnum(*a, num);
                    strcpy(product.varname, "Operation");
                    print_vect(product);
                } else {
                    puts("Error: invalid input(s). Please try again.");
                }        
            } else if (strcmp(tokens[1], "*") == 0 && atof(tokens[0]) != 0){ //multiplying a num and a vector
                vect *a;
                float num = atof(tokens[0]);
                a = findvect(tokens[2]);
                if (a != NULL){
                    vect product = multnum(*a, num);
                    strcpy(product.varname, "Operation");
                    print_vect(product);
                } else {
                    puts("Error: invalid input(s). Please try again.");
                }        
            } else if (strcmp(tokens[1], "+") != 0 && strcmp(tokens[1], "-") != 0 && strcmp(tokens[1], "*") != 0){
                puts("Please enter a valid operation for the calculator.");
            } else if (token_count != 5 && token_count != 1 && token_count != 3){
                puts("Please enter a valid input for the calculator.");
            } 
        }
    }
    deallocate(); 
    return 0;
}