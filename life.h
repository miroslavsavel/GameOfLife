#ifndef LIFE
#define LIFE

#include <iostream>
#include "arrays.h"
#include <stdio.h>
#include <stdlib.h>

const int MAXROW = 20, MAXCOL=20;

class Life {
public:
	void initialize();
	void print();
	void update();
	void generateRandomGrid();
	void deallocateGrid();
	int neighbor_count(int row, int col);
private:
	//int grid[MAXROW+2][MAXCOL+2];	//allows for two extra rows and columns
	//int ** grid = allocate_2D_array(MAXROW+2, MAXCOL+2);			//array of zeroes
	int ** grid = generate_2D_array(MAXROW+2, MAXCOL+2);			//random array of zeroes and ones
};

#endif	