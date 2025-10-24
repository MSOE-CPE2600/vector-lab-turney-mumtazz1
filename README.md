Vector Calculator Lab



The Vector Calculator is a program that that can perform certain math operations on two 3-Dimensional vectors provided by the user. Additionally, the user has an option to store the input vectors and the resulting vectors to be used in future operations. There are two versions of the Vector Calculator:



* **v1.0**: The version 1 tag holds the initial version of the Vector Calculator program. This program has a storage limit of 10 vectors (which is stored in an array of structs), meaning that the storage must be cleared once it has been filled with 10 vectors.



A Makefile is provided with the program, and the compilation can be executed through 'make'

To run the program, enter './vectcalc' as this is the name of the executable file.



The following commands can be entered in the program to perform the following operations:

1. help: To view the instructions of using the Vector Calculator app
2. list: To view the list of 10 vectors stored in the program
3. quit: To exit the program
4. clear: To delete all stored vectors from the program and restart
5. a = x, y, z: To store a vector in the program
6. c = a + b: To perform addition with two stored vectors and store the result in vector c
7. c = a - b: To perform subtraction with two stored vectors and store the result in vector c
8. c = a \* num: To perform scalar multiplication on a stored vector and store the result in vector c
9. a + b, a - b, a \* num: To perform an operation with the vector(s) without storing the resulting vector in the program
10. a: To view the x, y, and z values of a single existing vector



Note: Existing vectors in the storage can have their values reassigned (Ex: c = 1, 2, 3 -> c = a + b)

 





* **v2.0:** The version 2 tag holds the updated version of the Vector Calculator program. This program has 'unlimited' storage and can hold as many vectors as the user commands (stored in a dynamic array). Additionally, the user may load a .csv file that contains information of vectors into the program storage. The user may also store the vectors in a new .csv file.



The following commands can be entered in the program to perform the following operations:

1. help: To view the instructions of using the Vector Calculator app
2. list: To view the list of 10 vectors stored in the program
3. quit: To exit the program
4. clear: To delete all stored vectors from the program and restart
5. a = x, y, z: To store a vector in the program
6. c = a + b: To perform addition with two stored vectors and store the result in vector c
7. c = a - b: To perform subtraction with two stored vectors and store the result in vector c
8. c = a \* num: To perform scalar multiplication on a stored vector and store the result in vector c
9. a + b, a - b, a \* num: To perform an operation with the vector(s) without storing the resulting vector in the program
10. a: To view the x, y, and z values of a single existing vector
11. load file: To load a file and store its listed vectors in the program.
12. save new.csv, save new: To save the stored vectors of the program in a new .csv file. This file can be named by the user (Ex: save updated.csv). The user has an option to type the command without writing '.csv' after the name of the file.



Note: Existing vectors in the storage can have their values reassigned (Ex: c = 1, 2, 3 -> c = a + b)



This version uses dynamic memory to store the vectors in the program using malloc(). The dynamic memory allows the program to store as many vectors as demanded by the user by using realloc() to increase the size of the dynamic array when it is full.

