/*
	implementation of Conway's game of life according amazing book
	"Data structures and program design in C++"
	by Robert L. Kruse and Alexander J. Ryba, 1998
	ISBN 0–13–087697–6
	5.9.2019

g++ lifeMain.cpp life.cpp

g++ -c -g lifeMain.cpp life.cpp 
g++ -o main lifeMain.o life.o
*/

#include <iostream>
#include "life.h"

using namespace std;

void instructions()
/*
Pre: None
Post: Istructions for using the Life program have been printed
*/
{
	cout << "-------------------------------------------------------------------------\n"; 
	cout << "Conway's game of Life \n";
	cout << "This game uses a grid of size [" << maxrow << " X " <<maxcol <<"] in which \n";
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
	instructions();

	Life configuration;
	configuration.initialize();
	configuration.print();


	for(int row = 1; row <= maxrow; row++)
	{
		for(int col = 1; col <= maxcol; col++)
			cout << configuration.neighbor_count(row,col) <<" ";
		cout << "\n";
	}
	
	return 0;
}
