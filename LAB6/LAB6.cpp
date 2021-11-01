#include <iostream>
#include <string>

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
	Screen(int newLen, int newWidth):length(newLen), width(newWidth){}
	virtual ~Screen() { }
	virtual void print()= 0;
	virtual void pixels() = 0;
	virtual void initResolution() = 0;
	virtual void search(int, int, string) = 0;
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
	void initResolution()
	{
		cout << "Enter length: ";
		cin >> length;
		cout << "Enter width: ";
		cin >> width;
	}
	void search(int flag, int search = 0, string searchName = "NULL")
	{
		switch (flag)
		{
		case 1:
			if (search == length)	print();
			break;
		case 2:
			if (search == width)	print();
			break;
		case 6:
			if (searchName == type)	print();
			break;
		default:
			return;
		}
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
	void initResolution()
	{
		cout << "Enter length: ";
		cin >> length;
		cout << "Enter width: ";
		cin >> width;
	}
	void search(int flag, int search = 0, string searchName = "NULL")
	{
		switch (flag)
		{
		case 1:
			if (search == length)	print();
			break;
		case 2:
			if (search == width)	print();
			break;
		case 4:
			if (search == price)	print();
			break;
		case 5:
			if (search == year)		print();
			break;
		default:
			return;
		}
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
	void initResolution()
	{
		cout << "Enter length: ";
		cin >> length;
		cout << "Enter width: ";
		cin >> width;
	}
	void search(int flag, int search=0, string searchName="NULL")
	{
		switch (flag)
		{
		case 1:
			if (search == length)	print();
			break;
		case 2:
			if (search == width)	print();
			break;
		case 4:
			if (search == price)	print();
			break;
		case 5:
			if (search == year)		print();
			break;
		case 3:
			if (searchName == name)		print();
			break;
		default:
			return;
		}
	}
	//friend void search(int, Screen**);
};

void search(Screen** arr)
{
	while (1)
	{
		int choise;
		cout << "What to search:\n1)Length\n2)Width\n3)Name\n4)Price\n5)Year\n6)Type of matrix\n0)Exit\n";
		cin >> choise;
		int search;
		string searchName;
		switch (choise)
		{
		case 1:
			cout << "Enter length to search: ";
			cin >> search;
			for (int i = 0; i < 3; i++)
			{
				arr[i]->search(1, search, searchName);
			}
			break;
		case 2:
			cout << "Enter width to search: ";
			cin >> search;
			for (int i = 0; i < 3; i++)
			{
				arr[i]->search(2, search, searchName);
			}
			break;
		case 3:
			cout << "Enter name to search: ";
			cin >> searchName;
			search = 0;
			for (int i = 0; i < 3; i++)
			{
				arr[i]->search(3, search, searchName);
			}
			break;
		case 4:
			cout << "Enter price to search: ";
			cin >> search;
			for (int i = 0; i < 3; i++)
			{
				arr[i]->search(4, search, searchName);
			}
			break;
		case 5:
			cout << "Enter year to search: ";
			cin >> search;
			for (int i = 0; i < 3; i++)
			{
				arr[i]->search(5, search, searchName);
			}
			break;
		case 6:
			cout << "Enter type of matrix to search: ";
			cin >> searchName;
			search = 0;
			for (int i = 0; i < 3; i++)
			{
				arr[i]->search(6, search, searchName);
			}
			break;
		case 0:
			return;
		}
	}
}

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
		obj[i]->initResolution();
		obj[i]->pixels();
		obj[i]->print();
		system("pause");
		system("cls");
	}
	search(obj);
	for (int i = 0; i < 3; i++)
	{
		delete[]obj[i];
	}
	delete[] obj;
	return 0;
}


//разрешение с клавы
//поиск