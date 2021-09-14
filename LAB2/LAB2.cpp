#include <iostream>
#include <string>

using namespace std;

class Student
{
	string name;
	int rate;
	int ID;
public:
	static int id;
	Student(string newName, int rateValue): name(newName), rate(rateValue)
	{
		ID=++id;
	}
	Student() : name("Your Student"), rate(0)
	{
		ID=++id;
	}
	void Print()
	{
		cout <<"ID: "<< ID << "\n" <<"NAME: "<< name << "\n" <<"RATE: "<< rate << endl<<endl;
	}
	void Init()
	{
		cout << "Enter name and surname of student: ";
		rewind(stdin);
		getline(cin,name);
	}
	friend class Dekan;
	int Change(Student& student, int num)
	{
		if (num == student.ID)
		{
			student.Init();
			return 1;
		}
	}
	~Student()
	{}
};

class Dekan
{
public:
	void initRate(Student& student)
	{
		cout << "Enter rating of student: ";
		cin >> student.rate;
		cout << endl;
}
};

int Student:: id=0;

int menu()
{
	cout << "Choose an option:\n1)Operations with default students\n2)Operations with group\n3)Exit\n";
	int choise;
	cin >> choise;
	return choise;
}

void studentMenu(Student &firstStudent, Student &secondStudent, Dekan dekan)
{
	int choise;
	do {
		cout << "Choose:\n1)Change first student\n2)Change second student\n3)Show students\n4)Exit\n";
		cin >> choise;
		system("cls");
		switch (choise)
		{
		case 1:
			firstStudent.Init();
			dekan.initRate(firstStudent);
			system("cls");
			break;
		case 2:
			secondStudent.Init();
			dekan.initRate(secondStudent);
			system("cls");
			break;
		case 3:
			firstStudent.Print();
			secondStudent.Print();
			system("pause");
			system("cls");
			break;
		case 4:
			return;
		}
	} while (1);
}

Student* groupMenu(Student *groupOfStudents, Dekan dekan)
{
	int choise, size;
	do
	{
		if (groupOfStudents == NULL)
			size = 0;
		else
			size = groupOfStudents->id - 2;
		cout << "Choose:\n1)Add\n2)Change\n3)Print\n4)Exit\n";
		cin >> choise;
		system("cls");
		switch (choise)
		{
		case 1:
			if (size != 0)
			{
				cout << "The group has been alredy created!!!\n";
				system("pause");
				system("cls");
				break;
			}
			cout << "Enter size of group: ";
			cin >> size;
			system("cls");
			groupOfStudents = new Student[size];
			for (int i = 0; i < size; i++)
			{
				groupOfStudents[i].Init();
				dekan.initRate(groupOfStudents[i]);
			}
			system("cls");
			break;
		case 2:
			if (size == 0) break;
			for (int i = 0; i < size; i++)
				groupOfStudents[i].Print();
			cout << "Enter ID of student you want to change: ";
			int num;
			cin >> num;
			for (int i = 0; i < size; i++)
			{
				if(groupOfStudents[i].Change(groupOfStudents[i], num)==1)
					dekan.initRate(groupOfStudents[i]);
			}
			system("cls");
			break;
		case 3:
			if (size == 0) break;
			for (int i = 0; i < size; i++)
				groupOfStudents[i].Print();
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			return groupOfStudents;
		}
	} while (1);
}

int main()
{
	Dekan dekan;
	Student firstStudent;
	Student secondStudent("Alexander Shipko", 0);
	Student* groupOfStudents=NULL;
	while (1)
	{
		switch (menu())
		{
		case 1:
			system("cls");
			studentMenu(firstStudent, secondStudent, dekan);
			break;
		case 2:
			system("cls");
			groupOfStudents=groupMenu(groupOfStudents, dekan);
			break;
		case 3:
			delete[] groupOfStudents;
			system("cls");
			return 0;
		}
	}
}
//проверки