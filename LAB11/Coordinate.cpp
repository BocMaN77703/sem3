#include "Coordinate.h"
#include <iostream>

using namespace std;
using namespace NAME;

Coordinate::Coordinate():latitude(0), longitude(0){}

Coordinate::Coordinate(int newLat, int newLong) : latitude(newLat), longitude(newLong) {};

Coordinate::~Coordinate() {};

void Coordinate::see()
{
	cout << "Coordinates: (" << latitude << ", " << longitude << ")" << endl;
}