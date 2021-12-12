#include "Architect.h"
#include <string>
#include <iostream>

using namespace NAME;
using namespace std;

Architect::Architect() :name("NULL") {};

Architect::Architect(std::string newName):name(newName) {};

Architect::~Architect() {};

void Architect::see()
{
	cout << "Architect Name: "<<name<<endl;
}