/*
	implementation of Conway's game of life according amazing book
	"Data structures and program design in C++"
	by Robert L. Kruse and Alexander J. Ryba, 1998
	ISBN 0–13–087697–6
	5.9.2019

g++ lifeMain.cpp life.cpp

g++ -c -g lifeMain.cpp life.cpp arrays.c
g++ -o main lifeMain.o life.o arrays.o
*/

#include <iostream>
#include <stdlib.h>
#include "life.h"
#include "arrays.h"

using namespace std;

void instructions()
/*
Pre: None
Post: Istructions for using the Life program have been printed
*/
{
	cout << "-------------------------------------------------------------------------\n"; 
	cout << "Conway's game of Life \n";
	cout << "This game uses a grid of size [" << MAXROW << " X " <<MAXCOL <<"] in which \n";
	cout <<	"each cell can either be occupied by an organism or not. \n";
	cout << "-------------------------------------------------------------------------\n"; 
}

bool user_say_yes()
/*
Touto funkciou zadava uzivatel pozicie zivych buniek do gridu
*/
{
	int c;
	bool initial_response =  true;

	do                              //Loop until an appropriate input is received
		{
			if(initial_response)
				cout << "(y,n)? " << flush;
			else
				cout << "Respond with either y or n: " << flush;
			do                     //ignore white spaces
			{
				c = cin.get();
			} while (c == '\n' || c == ' ' || c == '\t');
			initial_response = false;
		} while (c != 'y' && c != 'Y' && c != 'n' && c != 'N');	
	return(c == 'y' || c == 'Y');
}



int main()
/*
Pre: None.
Post: Verifies that the method neighbor_count() returns the coorrect values
Uses: The class Life and its method initialize()
*/
{

	srand(time(0));		//this is because of function that randomly populate grid by zeroes and ones
	instructions();

	Life configuration;
	//configuration.generateRandomGrid();		//warning there is memory leak!
	//configuration.initialize();				//clumsy manual initialization by setting coordinates for every cell
	configuration.print();


	/*
	for(int row = 1; row <= MAXROW; row++)
	{
		for(int col = 1; col <= MAXCOL; col++)
			cout << configuration.neighbor_count(row,col) <<" ";
		cout << "\n";
	}
	*/
	configuration.deallocateGrid();
	return 0;
}
