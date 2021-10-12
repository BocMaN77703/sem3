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

class Restriction : public Year
{
protected:
	int restriction;
public:
	Restriction(int initRest, int newYear, string newName): restriction(initRest), Year(newYear,newName)	{}
	~Restriction(){}
	void print()
	{
		cout << "Name: " << name << endl;
		cout << "Year: " << year << endl;
		cout << "Restriction: " << restriction <<"p"<< endl;
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

class ScreenType : public Diagonal, public Restriction
{
protected:
	string screenType;
public:
	ScreenType(string newType, int newRest, int newDiag, int newPrice, int newYear, string newName): screenType(newType), Television(newName),
		Diagonal(newDiag, newPrice, newName), Restriction(newRest, newYear, newName)
	{}
	~ScreenType(){}
	void print()
	{
		cout << "Name: " << name << endl;
		cout << "Price: " << price << "$" << endl;
		cout << "Year: " << year << endl;
		cout << "Restriction: " << restriction << "p" << endl;
		cout << "Diagonal: " << diagonal << " inches" << endl;
		cout << "Screen type: " << screenType << endl;
	}
};

int main()
{
	ScreenType object("IPS", 1440, 45, 1150, 2021, "LG");
	object.print();
	return 0;
}