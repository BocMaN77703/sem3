#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class ExceptionClass : public exception
{
public:
	ExceptionClass(const char* message) :exception(message) {}
	~ExceptionClass() {}
	void wrongValue()
	{
		cin.clear();
		cin.ignore(100, '\n');
	}
};

class Student
{
	char name[20];
	int course;
	float mark;
public:
	Student()
	{
		course = 0;
		mark = 0.0;
	}
	Student(const char* newName, int newCourse, float newMark): course(newCourse), mark(newMark)
	{
		int i = 0;
		for (i = 0; i < strlen(newName)&&i<20; i++)
		{
			name[i] = newName[i];
		}
		name[i] = '\0';
	}
	Student(const Student& a)
	{
		int i = 0;
		for (i = 0; i < strlen(a.name); i++)
		{
			name[i] = a.name[i];
		}
		name[i] = '\0';
		course = a.course;
		mark = a.mark;
	}
	~Student(){};
	void init()
	{
		while (1)
		{
			try
			{
				cout << "Enter name: ";
				//cin.ignore(100, '\n');
				cin.getline(name, 20);
				cout << "Enter course: ";
				cin >> course;
				if (cin.fail() || course < 1 || course>11)
				{
					system("cls");
					throw ExceptionClass("Error! Incorrect value for course!\n");
				}
				cout << "Enter mark: ";
				cin >> mark;
				if (cin.fail() || mark < 0.0 || mark>10.0)
				{
					system("cls");
					throw ExceptionClass("Error! Incorrect value for mark!\n");
				}
				break;
			}
			catch (ExceptionClass& ex)
			{
				ex.what();
				ex.wrongValue();
			}
		}
	}
	void see()
	{
		system("cls");
		cout << "Name: " << name << endl << "Course: " << course << endl << "Mark: " << mark << endl << endl;
	}
	friend ostream& operator<< (ostream& out, const Student& );
	friend istream& operator>> (istream& in, Student& );
	void writeTextFile(string fileName)
	{
		ofstream out(fileName, ios::in | ios::out | ios::app);
		try
		{
			if (!out)	throw ExceptionClass("Can't open the file!");
		}
		catch (ExceptionClass& ex)
		{
			ex.what();
		}
		out << (*this);
		out.close();
	}
	void readTextFile(string fileName)
	{
		ifstream in(fileName, ios::in | ios::out);
		try
		{
			if (!in)	throw ExceptionClass("Can't open the file!");
		}
		catch (ExceptionClass& ex)
		{
			ex.what();
		}
		in >> (*this);
		in.close();
	}
	void writeBinFile(string fileName)
	{
		ofstream out(fileName, ios::binary| ios::app);
		try
		{
			if (!out)	throw ExceptionClass("Can't open the file!");
		}
		catch (ExceptionClass& ex)
		{
			ex.what();
		}
		out.write((char*)this, sizeof(Student));
		out.close();
	}
	void readBinFile(string fileName)
	{
		ifstream in(fileName, ios::binary);
		try
		{
			if (!in)	throw ExceptionClass("Can't open the file!");
		}
		catch (ExceptionClass& ex)
		{
			ex.what();
		}
		in.read((char*)this, sizeof(Student));
		in.close();
	}
	friend void printTextFile(const char*);
	friend void printBinFile(const char*);
	friend void searchTextFile(const char*);
	friend void searchBinFile(const char*);
	friend void delTextFile(const char*);
	friend void delBinFile(const char*);
};

ostream& operator<< (std::ostream& out, const Student& a)
{
	out << a.name << " " << a.course << " " << a.mark<<"\n";
	return out;
}

istream& operator>> (std::istream& in, Student& a)
{
	in >> a.name;
	in >> a.course;
	in >> a.mark;
	return in;
}

void printTextFile(const char* fileName)
{
	while (1)
	{
		int choise, counter = 0;
		while (1)
		{
			try
			{
				cout << "How to print?\n1)From the begining\n2)From the end\n0)Exit\n";
				cin >> choise;
				if (cin.fail() || choise < 0 || choise>2)	throw ExceptionClass("Error! Incorrect value!!! Try again!\n");
				break;
			}
			catch (ExceptionClass& ex)
			{
				system("cls");
				ex.what();
				ex.wrongValue();
			}
		}
		Student temp;
		string str;
		ifstream in(fileName, ios::in | ios::out);
		while (in.peek() != EOF)
		{
			in >> temp;
			counter++;
			in.seekg(2, in.cur);
		}
		in.close();
		in.open(fileName, ios::in | ios::out);
		switch (choise)
		{
		case 1:
			system("cls");
			while (getline(in, str))
			{
				cout << str << endl;
			}
			in.close();
			break;
		case 2:
			system("cls");
			do
			{
				for (int i = 0; i < counter; i++)
				{
					getline(in, str);
				}
				counter--;
				cout << str<<endl;
				if (counter == 0) break;
				in.seekg(0, in.beg);
			} while (1);
			in.close();
			break;
		case 0:
			in.close();
			return;
		}
	}
}

void printBinFile(const char* fileName)
{
	while (1)
	{
		int choise, counter = 0;
		while (1)
		{
			try
			{
				cout << "How to print?\n1)From the begining\n2)From the end\n0)Exit\n";
				cin >> choise;
				if (cin.fail() || choise < 0 || choise>2)	throw ExceptionClass("Error! Incorrect value!!! Try again!\n");
				break;
			}
			catch (ExceptionClass& ex)
			{
				system("cls");
				ex.what();
				ex.wrongValue();
			}
		}
		Student temp;
		string str;
		ifstream in(fileName, ios::in | ios::out);
		int i = 1;
		while (in.read((char*)&temp, sizeof(Student)))
		{
			counter++;
		}
		in.close();
		in.open(fileName, ios::in | ios::out);
		switch (choise)
		{
		case 1:
			system("cls");
			while (in.read((char*)&temp, sizeof(Student)))
			{
				cout << temp.name << " " << temp.course << " " << temp.mark << endl;
			}
			in.close();
			break;
		case 2:
			system("cls");
			do
			{
				in.seekg((counter - i) * sizeof(Student), in.beg);
				in.read((char*)&temp, sizeof(Student));
				cout << temp.name << " " << temp.course << " " << temp.mark << endl;
				i++;
			} while (counter>=i);
			in.close();
			break;
		case 0:
			in.close();
			return;
		}
	}
}

void searchTextFile(const char* fileName)
{
	Student temp;
	string str;
	bool flag = false;
	ifstream in(fileName, ios::in | ios::out);
	try
	{
		if (!in)	throw ExceptionClass("Can't open the file!");
	}
	catch (ExceptionClass& ex)
	{
		ex.what();
	}
	cout << "Enter name to search: ";
	cin >> str;
	while (in >> temp)
	{
		if (str == temp.name)
		{
			temp.see();
			flag = true;
		}
	}
	in.close();
	if (flag == false)	cout << "Nothing found...\n";
}

void searchBinFile(const char* fileName)
{
	Student temp;
	string str;
	bool flag = false;
	ifstream in(fileName, ios::binary);
	try
	{
		if (!in)	throw ExceptionClass("Can't open the file!");
	}
	catch (ExceptionClass& ex)
	{
		ex.what();
	}
	cout << "Enter name to search: ";
	cin >> str;
	while (in.read((char*)&temp, sizeof(Student)))
	{
		if (str == temp.name)
		{
			temp.see();
			flag = true;
		}
	}
	in.close();
	if (flag == false)	cout << "Nothing found...\n";
}

void delTextFile(const char* fileName)
{
	Student temp;
	string str;
	int counter = 0;
	bool flag = false;
	ifstream in(fileName, ios::in | ios::out);
	try
	{
		if (!in)	throw ExceptionClass("Can't open the file!");
	}
	catch (ExceptionClass& ex)
	{
		ex.what();
	}
	cout << "Enter name to delete: ";
	cin >> str;
	while (in.peek() != EOF)
	{
		in >> temp;
		counter++;
		in.seekg(2, in.cur);
	}
	Student* arr = new Student[counter];
	in.close();
	in.open(fileName, ios::in | ios::out);
	for (int i = 0; i < counter; i++)	in >> arr[i];
	in.close();
	in.open(fileName, ios::in | ios::out);
	int c2 = 0;
	for (int i = 0; i < counter; i++)
	{
		if (str == arr[i].name)
		{
			arr[i].see();
			flag = true;
			c2++;
			for (int j = i; j < counter-1; j++)
			{
				arr[j] = arr[j + 1];
			}
		}
	}
	if (flag)	counter -= c2;
	in.close();
	if (flag == false)
	{
		cout << "Nothing found...\n";
		return;
		delete[]arr;
	}
	ofstream out(fileName, ios::out);
	out.close();
	for (int i = 0; i < counter; i++)
	{
		arr[i].writeTextFile(fileName);
	}
	delete[]arr;
}

void delBinFile(const char* fileName)
{
	Student temp;
	string str;
	int counter = 0;
	bool flag = false;
	ifstream in(fileName, ios::in | ios::out);
	try
	{
		if (!in)	throw ExceptionClass("Can't open the file!");
	}
	catch (ExceptionClass& ex)
	{
		ex.what();
	}
	cout << "Enter name to delete: ";
	cin >> str;
	while (in.read((char*)&temp, sizeof(Student)))
	{
		counter++;
	}
	Student* arr = new Student[counter];
	in.close();
	in.open(fileName, ios::in | ios::out);
	for (int i = 0; i < counter; i++)	in.read((char*)&arr[i], sizeof(Student));
	in.close();
	in.open(fileName, ios::in | ios::out);
	int c2 = 0;
	for (int i = 0; i < counter; i++)
	{
		if (str == arr[i].name)
		{
			arr[i].see();
			flag = true;
			c2++;
			for (int j = i; j < counter - 1; j++)
			{
				arr[j] = arr[j + 1];
			}
		}
	}
	if (flag)	counter -= c2;
	in.close();
	if (flag == false)
	{
		cout << "Nothing found...\n";
		return;
		delete[]arr;
	}
	ofstream out(fileName, ios::out);
	out.close();
	for (int i = 0; i < counter; i++)
	{
		arr[i].writeBinFile(fileName);
	}
	delete[]arr;
}

int main()
{
	cout << "Creating new files...\n";
	ofstream out("textFile.txt", ios::out);
	out.close();
	out.open("textBinFile.txt", ios::out);
	out.close();
	out.open("binFile.bin", ios::out);
	out.close();
	Student a("Alexander", 2, 9.9), b("Stepan", 2, 8.3), c("Karen", 4, 3.3), d("Ivan", 1, 7.5), e("Olga", 3, 5.1), x;
	a.writeTextFile("textFile.txt");
	a.writeBinFile("textBinFile.txt");
	a.writeBinFile("binFile.bin");
	b.writeTextFile("textFile.txt");
	b.writeBinFile("textBinFile.txt");
	b.writeBinFile("binFile.bin"); 
	c.writeTextFile("textFile.txt");
	c.writeBinFile("textBinFile.txt");
	c.writeBinFile("binFile.bin");
	d.writeTextFile("textFile.txt");
	d.writeBinFile("textBinFile.txt");
	d.writeBinFile("binFile.bin");
	e.writeTextFile("textFile.txt");
	e.writeBinFile("textBinFile.txt");
	e.writeBinFile("binFile.bin");


	cout << "Reading text file...\n";
	/*x.readTextFile("textFile.txt");
	x.see();
	system("pause");
	system("cls");
	x.readBinFile("textBinFile.txt");
	x.see();
	system("pause");
	system("cls");
	x.readBinFile("binFile.bin");
	x.see();
	system("pause");
	system("cls");*/
	printTextFile("textFile.txt");
	system("cls");

	cout << "Reading binary file...\n";
	printBinFile("binFile.bin");
	system("cls");

	cout << "Reading text file in binary view...\n";
	printBinFile("textBinFile.txt");
	system("cls");


	cout << "Search in text file...\n";
	searchTextFile("textFile.txt");
	system("pause");
	system("cls");

	cout << "Search in binary file...\n";
	searchBinFile("binFile.bin");
	system("pause");
	system("cls");

	cout << "Search in text file in binary view...\n";
	searchBinFile("textBinFile.txt");
	system("pause");
	system("cls");


	cout << "Delete in text file...\n";
	delTextFile("textFile.txt");
	system("pause");
	system("cls");

	cout << "Delete in binary file...\n";
	delBinFile("binFile.bin");
	system("pause");
	system("cls");

	cout << "Delete in text file with binary view...\n";
	delBinFile("textBinFile.txt");
	system("pause");
	system("cls");


	return 0;
}