#include "Floor.h"
#include <iostream>

using namespace std;
using namespace NAME;

Floor::Floor()
{
	floorNumber = 0;
}

Floor::Floor(int newFloor):floorNumber(newFloor){}

Floor::~Floor() {};

void Floor::see()
{
	cout << "Number of floor: " << floorNumber << endl;
}