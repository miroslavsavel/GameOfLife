#include <iostream>
#include "life.h"

using namespace std;

void Life::initialize()
/*
Pre: None
Post: The Life object contains a configuration specified by the user
*/
{
	cout<<"------------------------------->>Life manual initialization<<-------------------------------\n";

	int row,col;
	for(row = 0; row <= maxrow + 1; row++)
		for(col=0; col <= maxcol + 1; col++)
			grid[row][col] = 0;
	cout<<"List the coordinates for living cells. \n";
	cout << "Terminate the list with the special pair -1-1 \n";
	cin >> row >> col;

	while(row != -1 || col != -1)
	{
		if(row >= 1 && row <= maxrow)
			if(col >= 1 && col <= maxcol)
				grid[row][col] = 1;
			else
				cout <<"Column " << col << " is out of range. \n";
		else
			cout << "Row " << row << " is out of range. \n";
		cin >> row >> col;
	}
}

void Life::generateRandomGrid() {};

void Life::print()
/*
Pre: The life object contains a configuration
Post: The configuration is written for the user
*/
{
	int row,col;
	cout << "\n------------------------------->>Printing the current Life configuration<<-------------------------------\n";
	for (row = 1; row <= maxcol; row++)
	{
		for (col = 1; col <= maxcol; col++)
			if(grid[row][col] == 1)
				cout << "*";
			else
				cout << " ";
		cout << "\n";
	}
	cout << "\n"; 
}

void Life::update()
/*
Pre: The Life object contains a configuration
Post: The Life object contains the next generation of configuration
We first use the data stored in the configuration to calculate entries of rectangular array
*/
{
	int row,col;
	int new_grid[maxrow+2][maxcol+2];

	for (row = 1; row <= maxrow; row++)
	{
		for(col = 1; col <= maxcol;col++)
		{
			switch(neighbor_count(row,col))
			{
				case 2:		//status stays the same
					new_grid[row][col] = grid[row][col];
					break;
				case 3:		//Cell is now alive
					new_grid[row][col] = 1;	
					break;
				default:	//Cell is now dead
					new_grid[row][col] = 0;
			}
		}
	}
	for (row = 1; row <= maxrow; row++)
		for (col = 1; col <= maxcol; col++)
			grid[row][col] = new_grid[row][col];
}


int Life::neighbor_count(int row, int col)
	{
		/*
		Pre: the life object contains a configuration and the coordinates row and col define a cell inside its hedge
		Post: the number of living neighbors of the specified cell is returned
		*/
		int i,j;
		int count = 0;
		for (int i = row-1; i <= row+1; i++)
		{
			for(j=col-1; j<=col+1;j++)
			{
				count += grid[i][j];	//increase the count if neighbor is alive
			}
		}
		count -= grid[row][col];		//reduce count, since cell is not its own neighbor
		return count;
	}