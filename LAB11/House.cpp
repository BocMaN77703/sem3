#include "House.h"
#include <iostream>

using namespace std;
using namespace NAME;

House::House():peopleNumber(0), street("NULL") {};

House::House(int newPeople, std::string newStreet, int newYear, int newLat, int newLong, Architect* newArch, int newRoomNumber, int newFloor)
	:peopleNumber(newPeople), street(newStreet), ArchitectualObject(newYear, newLat, newLong, newArch), Flat(newRoomNumber, newFloor) {};

House::~House() {};

void House::see()
{
	cout << "Number of people: " << peopleNumber << endl;
	cout << "Street: " << street << endl;
	Flat::see();
	ArchitectualObject::see();
}