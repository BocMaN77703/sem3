#include <iostream>

using namespace std;

class Screen
{
protected:
	int length;
	int width;
public:
	Screen() 
	{
		length = 0;
		width = 0;
	}
	Screen(int newLen, int newWidth):length(newLen), width(newWidth)	{}
	virtual ~Screen() { }
	virtual void print()= 0;
	virtual void pixels() = 0;
};

class Matrix :public Screen
{
protected:
	string type;
public:
	Matrix(int newLen, int newWidth, string newType):Screen(newLen, newWidth), type(newType){}
	~Matrix(){ }
	void print() 
	{
		cout << "Screen: " << length << "x" << width << endl;
		cout << "Matrix type: " << type << endl;
	}
	void pixels()
	{
		cout << "Number of pixels: " << length * width << " pixels" << endl;
	}
};

class Properties:public Screen
{
protected:
	int price;
	int year;
public:
	Properties(int newLen, int newWidth, int newPrice, int newYear):Screen(newLen, newWidth), price(newPrice), year(newYear){}
	~Properties(){ }
	void print()
	{
		cout << "Screen: " << length << "x" << width << endl;
		cout << "Price: " << price << "$" << endl;
		cout << "Year: " << year << endl;
	}
	void pixels()
	{
		cout << "Number of pixels: " << length * width << " pixels" << endl;
	}
};

class Model:public Properties
{
protected:
	string name;
public:
	Model(int newLen, int newWidth, int newPrice, int newYear, string newName):Properties(newLen, newWidth, newPrice, newYear), name(newName){}
	~Model() { }
	void print() override
	{
		cout << "Name: " << name << endl;
		cout << "Screen: " << length << "x" << width << endl;
		cout << "Price: " << price << "$" << endl;
		cout << "Year: " << year << endl;
	}
	void pixels()
	{
		cout << "Number of pixels: " << length * width << " pixels" << endl;
	}
};

int main()
{
	Screen** obj = new Screen*[3];
	Matrix* a=new Matrix(800, 640, "TNF");
	Properties* b=new Properties(1280, 720, 1900, 2020);
	Model* c=new Model(1920, 1080, 3000, 2021, "Samsung");
	obj[0] = a;
	obj[1] = b;
	obj[2] = c;
	for (int i = 0; i < 3; i++)
	{
		obj[i]->pixels();
		obj[i]->print();
		system("pause");
		system("cls");
	}
	for (int i = 0; i < 3; i++)
	{
		delete[]obj[i];
	}
	delete[] obj;
	return 0;
}