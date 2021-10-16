#include <iostream>
#include <string>

using namespace std;

class Television
{
protected:
	string name;
public:
	Television(string newName) : name(newName) {}
	Television(){}
	~Television(){}
	void print()
	{
		cout << "Name: " << name<<endl;
	}
};

class Price : virtual public Television
{
protected:
	int price;
public:
	Price(int newPrice, string newName) :price(newPrice), Television(newName)	{}
	~Price(){}
	void print()
	{
		
		cout << "Name: "<<name<<endl;
		cout << "Price: " << price <<"$"<< endl;
	}
};

class Year : virtual public Television
{
protected:
	int year;
public:
	Year(int newYear, string newName) : year(newYear), Television(newName)	{}
	~Year(){}
	void print()
	{
		cout << "Name: " << name << endl;
		cout << "Year: " << year << endl;
	}
};

class Resolution : public Year
{
protected:
	int resolution;
public:
	Resolution(int initRest, int newYear, string newName): resolution(initRest), Year(newYear,newName)	{}
	~Resolution(){}
	void print()
	{
		cout << "Name: " << name << endl;
		cout << "Year: " << year << endl;
		cout << "Restriction: " << resolution <<"p"<< endl;
	}
};

class Diagonal : public Price
{
protected:
	int diagonal;
public:
	Diagonal(int initDiag, int newPrice, string newName): diagonal(initDiag), Price(newPrice, newName)	{}
	~Diagonal(){}
	void print()
	{
		cout << "Name: " << name << endl;
		cout << "Price: " << price <<"$"<< endl;
		cout << "Diagonal: " << diagonal <<" inches"<< endl;
	}
};

class ScreenType : public Diagonal, public Resolution
{
protected:
	string screenType;
public:
	ScreenType(string newType, int newRest, int newDiag, int newPrice, int newYear, string newName): screenType(newType), Television(newName),
		Diagonal(newDiag, newPrice, newName), Resolution(newRest, newYear, newName)
	{}
	~ScreenType(){}
	void print()
	{
		cout << "Name: " << name << endl;
		cout << "Price: " << price << "$" << endl;
		cout << "Year: " << year << endl;
		cout << "Restriction: " << resolution << "p" << endl;
		cout << "Diagonal: " << diagonal << " inches" << endl;
		cout << "Screen type: " << screenType << endl;
	}
	void edit()
	{
		cout << "Enter name: ";
		string newName;
		rewind(stdin);
		getline(cin, newName);
		name = newName;
		cout << "Enter price: ";
		int edit;
		cin >> edit;
		price = edit;
		cout << "Enter year: ";
		cin >> edit;
		year = edit;
	}
};

int menu()
{
	cout << "Choose:\n1)Show\n2)Edit\n3)Exit\n";
	int n;
	cin >> n;
	system("cls");
	return n;
}

int main()
{
	ScreenType object("IPS", 1440, 45, 1150, 2021, "LG");
	//object.print();
	while (1)
	{
		switch (menu())
		{
		case 1:
			object.print();
			break;
		case 2:
			object.edit();
			break;
		case 3:
			/*((Television)object).print();
			((Price)object).print();
			((Year)object).print();*/
			return 0;
		}
	}
}
//в первые 3 все с клавы
//редактирование