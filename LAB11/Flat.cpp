#include "Flat.h"
#include <iostream>

using namespace std;
using namespace NAME;

Flat::Flat()
{
	roomNumber = 0;
	floor = 0;
}

Flat::Flat(int newRoomNumber, int numberOfFloor) :roomNumber(newRoomNumber)
{
	floor = new Floor(numberOfFloor);
}

Flat::~Flat()
{
	delete floor;
}

void Flat::see()
{
	cout << "Number of rooms: " << roomNumber << endl;
	floor->see();
}