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
	//Architect* arch = new Architect("Ivanov");
	//House myHouse(500, "Lenina", 2003, 45,58, arch, 3, 9);
	//myHouse.see();
	//delete arch;
	Architect** arch=NULL;

	int num = 0;
	cout << "Enter number of houses: ";
	cin >> num;
	House** myHouse = new House * [num];
	arch = new Architect*[num];
	int num2 = 0;
	for (int i = 0; i < num; i++)
	{
		Architect temp;
		temp.init();
		if (i == 0)
		{
			num2++;
			arch[i]= new Architect(temp.name);
			myHouse[i] = new House(500, "Lenina", 2003, 45, 58, arch[i], 3, 9);
		}
		for (int k = 0; k < i; k++)
		{
			if (temp.name != arch[k]->name)
			{
				num2++;
				arch[i] = new Architect(temp.name);
				myHouse[i] = new House(500, "Lenina", 2003, 45, 58, arch[i], 3, 9);
			}
			else
			{
				myHouse[i] = new House(500, "Lenina", 2003, 45, 58, arch[k], 3, 9);
				break;
			}
		}
	}
	for (int i = 0; i < num; i++)
	{
		myHouse[i]->see();
	}
	cout << endl << endl;
	for (int i = 0; i < num2; i++)
	{
		arch[i]->see();
	}
	return 0;
}
//несколько домов
//ввод архитектора с клавы, без повторений