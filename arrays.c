//gcc arrays.c -g -w -o arrays
/*
podla tohto somimplementoval kniznicu
https://computer.howstuffworks.com/c15.htm

*/
#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"



//this function allocate and random generate an array
int *generate_array(int length)
{
	int* pole;
	
	pole = (int*)malloc(length * sizeof(int));
	// Check if the memory has been successfully 
    // allocated by malloc or not 
    if (pole == NULL) { 
        printf("Memory not allocated.\n"); 
        exit(0); 
    } 
    else { 
  
        // Memory has been successfully allocated 
        printf("Memory successfully allocated using malloc.\n");

        //assign random numbers to elements of array 1 -100
		for(int j = 0; j < length; j++)
		{
			pole[j]=rand() % 100 + 1;
		}

        return pole; 
    }    
}


//20191104
//this function display an array 
//input is pointer to array and lenght of array
/*
	https://www.geeksforgeeks.org/size_t-data-type-c-language/
*/
void print_array(int *pole, size_t length)
{
	size_t i = 0;
	// Print the elements of the array 
    printf("The elements of the array are: ");
    printf("\n"); 
    for( ; i < length; ++i )      
    	printf("%d\t", pole[i]);
    printf("\n");
}


/*
    20191125
    this function allocate random square array M x M
    the size is determined by parameter of function
    this function allocate and random generate an array
    
        source:
    https://thispointer.com/allocating-and-deallocating-2d-arrays-dynamically-in-c-and-c/

    call this function as
    int ** pole = generate_2D_array(row, col);
*/
int ** generate_2D_array(int row, int col)
{
    

    int ** pole = (int **) malloc(sizeof(int *)*row);
    for(int i = 0; i < row; i++)
    {
        pole[i] = (int *) malloc(sizeof(int)*col);
    }

    if (pole == NULL) { 
        printf("Memory not allocated.\n"); 
        exit(0); 
    } 
    else { 
  
        // Memory has been successfully allocated 
        printf("Memory successfully allocated using malloc.\n");

        //assign random numbers to elements of array 1 -100
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
                pole[i][j]=(rand() % 100 + 1) % 2;      //only 0 and 1
        }

        return pole; 
    }   
}


/*
    20191127
    this function allocate arrays on heap filled by zero
    
        source:
    https://thispointer.com/allocating-and-deallocating-2d-arrays-dynamically-in-c-and-c/

    call this function as
    int ** pole = generate_2D_array(row, col);
*/
int ** allocate_2D_array(int row, int col)
{


    int ** pole = (int **) malloc(sizeof(int *)*row);
    for(int i = 0; i < row; i++)
    {
        pole[i] = (int *) malloc(sizeof(int)*col);
    }

    if (pole == NULL) { 
        printf("Memory not allocated.\n"); 
        exit(0); 
    } 
    else { 
  
        // Memory has been successfully allocated 
        printf("Memory successfully allocated using malloc.\n");

        //assign random numbers to elements of array 1 -100
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
                pole[i][j]=0;
        }

        return pole; 
    }   
}

/*
*/
void print_2D_array(int ** pole, int row, int col)
{

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf(" %d", pole[i][j]);
        }
        printf("\n");
    }
}


/*
    20191127
    This function dealocates 2D array from memory
*/    
void deallocate_2D_array(int ** pole, int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        free(pole[i]);
    }
    free(pole);
}