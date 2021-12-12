#include "ArchitectualObject.h"
#include <iostream>

using namespace std;
using namespace NAME;

ArchitectualObject::ArchitectualObject()
{
	year = 0;
	coordinates = 0;
	architect = 0;
}

ArchitectualObject::ArchitectualObject(int newYear, int newLat, int newLong, Architect* newArch):year(newYear), architect(newArch)
{
	coordinates = new Coordinate(newLat, newLong);
}

ArchitectualObject::~ArchitectualObject()
{
	delete coordinates;
}

void ArchitectualObject::see()
{
	cout << "Year: " << year << endl;
	coordinates->see();
	architect->see();
}