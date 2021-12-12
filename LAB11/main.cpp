#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "House.h"

namespace NAME {
	Architect;
	ArchitectualObject;
	Coordinate;
	Flat;
	Floor;
	House;
}

using namespace NAME;
using namespace std;

int main()
{
	Architect* arch = new Architect("Ivanov");
	House myHouse(500, "Lenina", 2003, 45,58, arch, 3, 9);
	myHouse.see();
	delete arch;
	return 0;
}