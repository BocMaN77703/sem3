#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

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
				rewind(stdin);
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
	friend void sortBinFile(const char*);
	friend void sortTextFile(const char*);
	friend void paramTextFile(const char*, int, int);
	friend void paramBinFile(const char*, int, int);
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
			while (in >> temp)
			{
				//cout << str << endl;
				cout << "Name: " << temp.name << endl;
				cout << "Course: " << fixed <<showpos<< temp.course << endl;
				cout << "Mark: " << fixed << setprecision(1) << temp.mark<<endl<<endl;
			}
			in.close();
			break;
		case 2:
			system("cls");
			do
			{
				for (int i = 0; i < counter; i++)
				{
					in >> temp;
				}
				counter--;
				cout << "Name: " << temp.name << endl;
				cout << "Course: " << fixed << showpos << temp.course << endl;
				cout << "Mark: " << fixed << setprecision(1) << temp.mark << endl << endl;
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
				cout << "Name: " << temp.name << endl;
				cout << "Course: " << fixed << showpos << temp.course << endl;
				cout << "Mark: " << fixed << setprecision(1) << temp.mark << endl << endl;
			}
			in.close();
			break;
		case 2:
			system("cls");
			do
			{
				in.seekg((counter - i) * sizeof(Student), in.beg);
				in.read((char*)&temp, sizeof(Student));
				cout << "Name: " << temp.name << endl;
				cout << "Course: " << fixed << showpos << temp.course << endl;
				cout << "Mark: " << fixed << setprecision(1) << temp.mark << endl << endl;
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

void sortTextFile(const char* fileName)
{
	ifstream in(fileName, ios::in | ios::out);
	Student temp;
	int counter=0;
	while (in.peek() != EOF)
	{
		in >> temp;
		counter++;
		in.seekg(2, in.cur);
	}
	if (counter == 0)
	{
		cout << "File is empty!";
		return;
	}
	Student* arr = new Student[counter];
	in.close();
	in.open(fileName, ios::in | ios::out);
	for (int i = 0; i < counter; i++)	in >> arr[i];
	in.close();
	for (int i = 0; i < counter; i++)
	{
		for (int j = 0; j < counter; j++)
		{
			if (arr[j].course > arr[j + 1].course)
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	ofstream out(fileName, ios::out);
	out.close();
	for (int i = 0; i < counter; i++)
	{
		arr[i].writeTextFile(fileName);
	}
	delete[]arr;
}

void sortBinFile(const char* fileName)
{
	ifstream in(fileName, ios::in | ios::out);
	Student temp;
	int counter = 0;
	while (in.read((char*)&temp, sizeof(Student)))
	{
		counter++;
	}
	if (counter == 0)
	{
		cout << "File is empty!";
		return;
	}
	Student* arr = new Student[counter];
	in.close();
	in.open(fileName, ios::in | ios::out);
	for (int i = 0; i < counter; i++)	in.read((char*)&arr[i], sizeof(Student));
	in.close();
	for (int i = 0; i < counter; i++)
	{
		for (int j = 0; j < counter; j++)
		{
			if (arr[j].course > arr[j + 1].course)
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	ofstream out(fileName, ios::out);
	out.close();
	for (int i = 0; i < counter; i++)
	{
		arr[i].writeTextFile(fileName);
	}
	delete[]arr;
}

int menu()
{
	int choise;
	while (true)
	{
		try
		{
			cout << "Choose:\n1)Add\n2)Show\n3)Sort\n4)Copy\n5)Print by parameter\n6)Delete\n0)Exit\n";
			cin >> choise;
			if (cin.fail() || choise < 0 || choise>6)
			{
				system("cls");
				throw ExceptionClass("Incorrect value!!!Try again...\n");
			}
			break;
		}
		catch (ExceptionClass& ex)
		{
			cout << ex.what();
			ex.wrongValue();
		}
	}
	return choise;
}

void add()
{
	Student* arr = NULL;
	int size;
	while (1)
	{
		try
		{
			cout << "Enter number of students you want to add:";
			cin >> size;
			if (cin.fail() || size < 1)
			{
				system("cls");
				throw ExceptionClass("Incorrect value!!!Try again...\n");
			}
			break;
		}
		catch (ExceptionClass &ex)
		{
			cout << ex.what();
			ex.wrongValue();
		}
	}
	arr = new Student[size];
	for (int i = 0; i < size; i++)
	{
		arr[i].init();
		arr[i].writeBinFile("textBinFile.txt");
		arr[i].writeTextFile("textFile.txt");
		arr[i].writeBinFile("binFile.bin");
	}

}

void print()
{
	int choise;
	while (1)
	{
		try
		{
			cout << "1)Print text file\n2)Print bin file\n3)print textbin file\n";
			cin >> choise;
			if (cin.fail() || choise < 1||choise>3)
			{
				system("cls");
				throw ExceptionClass("Incorrect value!!!Try again...\n");
			}
			break;
		}
		catch (ExceptionClass& ex)
		{
			cout << ex.what();
			ex.wrongValue();
		}
	}
	switch (choise)
	{
	case 1:
		printTextFile("textFile.txt");
		break;
	case 2:
		printBinFile("binFile.bin");
		break;
	case 3:
		printBinFile("textBinFile.txt");
		break;
	}
}

void del()
{
	int choise;
	while (1)
	{
		try
		{
			cout << "1)Delete text file\n2)Delete bin file\n3)Delete textbin file\n";
			cin >> choise;
			if (cin.fail() || choise < 1 || choise>3)
			{
				system("cls");
				throw ExceptionClass("Incorrect value!!!Try again...\n");
			}
			break;
		}
		catch (ExceptionClass& ex)
		{
			cout << ex.what();
			ex.wrongValue();
		}
	}
	switch (choise)
	{
	case 1:
		delTextFile("textFile.txt");
		break;
	case 2:
		delBinFile("binFile.bin");
		break;
	case 3:
		delBinFile("textBinFile.txt");
		break;
	}
}

void sort()
{
	int choise;
	while (1)
	{
		try
		{
			cout << "1)Sort text file\n2)Sort bin file\n3)Sort textbin file\n";
			cin >> choise;
			if (cin.fail() || choise < 1 || choise>3)
			{
				system("cls");
				throw ExceptionClass("Incorrect value!!!Try again...\n");
			}
			break;
		}
		catch (ExceptionClass& ex)
		{
			cout << ex.what();
			ex.wrongValue();
		}
	}
	switch (choise)
	{
	case 1:
		sortTextFile("textFile.txt");
		break;
	case 2:
		sortBinFile("binFile.bin");
		break;
	case 3:
		sortBinFile("textBinFile.txt");
		break;
	}
}

void copyTextFile(const char* fileName)
{
	ifstream in(fileName, ios::in | ios::out);
	Student temp;
	int counter = 0;
	while (in.peek() != EOF)
	{
		in >> temp;
		counter++;
		in.seekg(2, in.cur);
	}
	if (counter == 0)
	{
		cout << "File is empty!";
		return;
	}
	Student* arr = new Student[counter];
	in.close();
	in.open(fileName, ios::in | ios::out);
	for (int i = 0; i < counter; i++)	in >> arr[i];
	in.close();
	int count = 0;
	Student* plenty = NULL;
	int* pl = NULL;
	for (int i = 0; i < counter; i++)
	{
		count++;
		plenty = (Student*)realloc(plenty, count * sizeof(Student));
		pl = (int*)realloc(pl, count * sizeof(int));
		cout << "Enter number of element of plenty: ";
		cin >> pl[i];
		if (cin.fail() || pl[i] <= pl[i - 1])
		{
			system("cls");
			throw ExceptionClass("Incorrect value!!!Try again...\n");
		}
		cout << "Do you want to continue(y/n): ";
		rewind(stdin);
		if (getchar() == 'n') break;
	}
	for (int i = 0, j = 0; i < counter; i++)
	{
		if (pl[j] == i)
		{
			plenty[j] = arr[i];
			j++;
		}
	}
	int pos1 = pl[0];
	int pos2 = 0;
	while (1)
	{
		cout << "Enter number of position on which you want to put your plenty: ";
		cin >> pos2;
		if (cin.fail() || pos2 < 0 || pos2>(10 - count + 1))
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Incorrect value!\n";
		}
		break;
	}
	int i = 0, j = 0;
	for (i = pos2, j = 0; j < count; i++, j++)
	{
		temp = arr[i];
		arr[i] = plenty[j];
		plenty[j] = temp;
	}
	if (pos2 > pos1)
	{
		for (i = pos1, j = pos1 + count; j < pos2 + 1; i++, j++)
		{
			arr[i] = arr[j];
		}
		for (i = i - 1, j = 0; j < count; i++, j++)
		{
			arr[i] = plenty[j];
		}
	}
	else if (pos1 > pos2)
	{
		for (i, j = 0; j < count; i++, j++)
		{
			if (i >= count + pos1) break;
			temp = arr[i];
			arr[i] = plenty[j];
			plenty[j] = temp;
			if (j + 1 == count)	j = -1;
		}
	}
	free(plenty);
	free(pl);
	ofstream out(fileName, ios::out);
	out.close();
	for (int i = 0; i < counter; i++)
	{
		arr[i].writeTextFile(fileName);
	}
	delete[]arr;
}

void copyBinFile(const char* fileName)
{
	ifstream in(fileName, ios::in | ios::out);
	Student temp;
	int counter = 0;
	while (in.read((char*)&temp, sizeof(Student)))
	{
		counter++;
	}
	if (counter == 0)
	{
		cout << "File is empty!";
		return;
	}
	Student* arr = new Student[counter];
	in.close();
	in.open(fileName, ios::in | ios::out);
	for (int i = 0; i < counter; i++)	in.read((char*)&arr[i], sizeof(Student));
	in.close();
	int count = 0;
	Student* plenty = NULL;
	int* pl = NULL;
	for (int i = 0; i < counter; i++)
	{
		count++;
		plenty = (Student*)realloc(plenty, count * sizeof(Student));
		pl = (int*)realloc(pl, count * sizeof(int));
		cout << "Enter number of element of plenty: ";
		cin >> pl[i];
		if (cin.fail() || pl[i] <= pl[i - 1])
		{
			system("cls");
			throw ExceptionClass("Incorrect value!!!Try again...\n");
		}
		cout << "Do you want to continue(y/n): ";
		rewind(stdin);
		if (getchar() == 'n') break;
	}
	for (int i = 0, j = 0; i < counter; i++)
	{
		if (pl[j] == i)
		{
			plenty[j] = arr[i];
			j++;
		}
	}
	int pos1 = pl[0];
	int pos2 = 0;
	while (1)
	{
		cout << "Enter number of position on which you want to put your plenty: ";
		cin >> pos2;
		if (cin.fail() || pos2 < 0 || pos2>(10 - count + 1))
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Incorrect value!\n";
		}
		break;
	}
	int i = 0, j = 0;
	for (i = pos2, j = 0; j < count; i++, j++)
	{
		temp = arr[i];
		arr[i] = plenty[j];
		plenty[j] = temp;
	}
	if (pos2 > pos1)
	{
		for (i = pos1, j = pos1 + count; j < pos2 + 1; i++, j++)
		{
			arr[i] = arr[j];
		}
		for (i = i - 1, j = 0; j < count; i++, j++)
		{
			arr[i] = plenty[j];
		}
	}
	else if (pos1 > pos2)
	{
		for (i, j = 0; j < count; i++, j++)
		{
			if (i >= count + pos1) break;
			temp = arr[i];
			arr[i] = plenty[j];
			plenty[j] = temp;
			if (j + 1 == count)	j = -1;
		}
	}
	free(plenty);
	free(pl);
	ofstream out(fileName, ios::out);
	out.close();
	for (int i = 0; i < counter; i++)
	{
		arr[i].writeBinFile(fileName);
	}
	delete[]arr;
}

void copy()
{
	int choise;
	while (1)
	{
		try
		{
			cout << "1)Copy in text file\n2)Copy in bin file\n3)Copy in textbin file\n";
			cin >> choise;
			if (cin.fail() || choise < 1 || choise>3)
			{
				system("cls");
				throw ExceptionClass("Incorrect value!!!Try again...\n");
			}
			break;
		}
		catch (ExceptionClass& ex)
		{
			cout << ex.what();
			ex.wrongValue();
		}
	}
	switch (choise)
	{
	case 1:
		copyTextFile("textFile.txt");
		break;
	case 2:
		copyBinFile("binFile.bin");
		break;
	case 3:
		copyBinFile("textBinFile.txt");
		break;
	}
}

void paramTextFile(const char* fileName, int diapason1, int diapason2)
{
	Student temp;
	string str;
	ifstream in(fileName, ios::in | ios::out);
	int counter = 0;
	while (in.peek() != EOF)
	{
		in >> temp;
		counter++;
		in.seekg(2, in.cur);
	}
	in.close();
	in.open(fileName, ios::in | ios::out);
	system("cls");
	while (in >> temp)
	{
		if (temp.course >= diapason1 && temp.course <= diapason2)
		{
			cout << "Name: " << temp.name << endl;
			cout << "Course: " << fixed << showpos << temp.course << endl;
			cout << "Mark: " << fixed << setprecision(1) << temp.mark << endl << endl;
		}
	}
	in.close();
}

void paramBinFile(const char* fileName, int diapason1, int diapason2)
{
	Student temp;
	string str;
	ifstream in(fileName, ios::in | ios::out);
	int i = 1;
	int counter = 0;
	while (in.read((char*)&temp, sizeof(Student)))
	{
		counter++;
	}
	in.close();
	in.open(fileName, ios::in | ios::out);
	system("cls");
	while (in.read((char*)&temp, sizeof(Student)))
	{
		if (temp.course >= diapason1 && temp.course <= diapason2)
		{
			cout << "Name: " << temp.name << endl;
			cout << "Course: " << fixed << showpos << temp.course << endl;
			cout << "Mark: " << fixed << setprecision(1) << temp.mark << endl << endl;
		}
	}
	in.close();
}

void paramPrint()
{
	int diapason1=0, diapason2=0;
	cout << "Enter minimum course: ";
	cin >> diapason1;
	cout << "Enter maximum course: ";
	cin >> diapason2;
	int choise;
	while (1)
	{
		try
		{
			cout << "1)Diapason print in text file\n2)Diapason print in bin file\n3)Diapason print in textbin file\n";
			cin >> choise;
			if (cin.fail() || choise < 1 || choise>3)
			{
				system("cls");
				throw ExceptionClass("Incorrect value!!!Try again...\n");
			}
			break;
		}
		catch (ExceptionClass& ex)
		{
			cout << ex.what();
			ex.wrongValue();
		}
	}
	switch (choise)
	{
	case 1:
		paramTextFile("textFile.txt", diapason1, diapason2);
		break;
	case 2:
		paramBinFile("binFile.bin", diapason1, diapason2);
		break;
	case 3:
		paramBinFile("textBinFile.txt", diapason1, diapason2);
		break;
	}
}

int main()
{
	while (1)
	{
		switch (menu())
		{
		case 1:
			add();
			break;
		case 2:
			print();
			break;
		case 3:
			sort();
			break;
		case 4:
			copy();
			break;
		case 5:
			paramPrint();
			break;
		case 6:
			del();
			break;
		case 0: 
			return 0;
		}
	}
	return 0;
}
//print
//add
//sort
//копирование множества по номеру позиции
//вывод по диапазону