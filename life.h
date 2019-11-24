#include <iostream>



const int maxrow = 20, maxcol=60;

class Life {
public:
	void initialize();
	void print();
	void update();
	void generateRandomGrid();
	int neighbor_count(int row, int col);
private:
	int grid[maxrow+2][maxcol+2];	//allows for two extra rows and columns
};