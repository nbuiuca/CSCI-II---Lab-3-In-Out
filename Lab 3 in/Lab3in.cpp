//Lab 3 in
//Displays a set of images at random location

#include <iostream>
#include <ctime>
#include "graph1.h"

using namespace std;

//Protoypes
int getNoObjects();
int* getXCoords(int no_objects);
int* getYCoords(int no_objects);
void displayObjects(int* x_coords, int* y_coords, int no_objects);

int main()
{
	int no_objects = 0;
	int* x_coords = NULL;
	int* y_coords = NULL;
	char repeat;
	do {
		//Variable Declaration/Initialization

		

		//Initialize seed
		srand(time(0));

		//Display graphics
		displayGraphics();

		//1. Get the number of objects to be displayed
		no_objects = getNoObjects();

		//2. Generate the x-coords for each object
		x_coords = getXCoords(no_objects);


		//3. Generate the y-coords for each object
		y_coords = getXCoords(no_objects);

		//4. Display the objects at the randomly generated coordinates

		displayObjects(x_coords, y_coords, no_objects);

		//Cleanup memory	
		delete[] x_coords, y_coords, no_objects;

		cout << "Repeat program? (y/n)";
		cin >> repeat;
	}//repeat program

	while (tolower(repeat) == 'y');

	return 0;
}






//Implement functions below
int getNoObjects()
{
	//Variable declaration/initialization
	int no_objects = 0;

	//Prompt for # objects – should be between 2 and 30 inclusive
	do {
		cout << "Enter # of Object: ";
		cin >> no_objects;
		if (no_objects < 2 || no_objects > 30)
		{
			cout << "Error! Values must be between 2 and 30 inclusively! Please Re-enter! " << endl;
		}
	} while (no_objects < 2 || no_objects > 30);

	//Perform data validation
	return no_objects;
}

int* getXCoords(int no_objects)
{
	//Variable declaration/initialization
	//int* xcoords = 0;

	//Dynamically allocate the array for x-coords
	//Generates x-coords for each object randomly
	// for (i =0;i < no_objects; i++){
	// 
	//xcoords[i] = rand() % 640 + 1;
	// }
	//return xcoords;

	int i = 0;
	int* x = new int[no_objects];
	for (i = 0; i < no_objects; i ++) {
		x[i] = rand() % 601;
	}
	return x;
}

int* getYCoords(int no_objects)
{
	//Variable declaration/initialization

	int i = 0;

	//Dynamically allocate the array for y-coords
	int* y = new int[no_objects];
	//Generates y-coords for each object randomly
	for (i = 0; i < no_objects; i++) {
		y[i] = rand() % 400;
	}
	return y;
}

void displayObjects(int* x_coords, int* y_coords, int no_objects)
{
	//Variable declaration/initialization
	int i = 0;



	//Display all objects at x/y random positions stored in x_coords/y_coords

	for (i = 0; i < no_objects; i++) {
		if ( i % 2 == 0) {
			displayPNG("even.png", x_coords[i], y_coords[i]);
		}
		else {
			displayPNG("odd.png", x_coords[i], y_coords[i]);
		}
	}

}
