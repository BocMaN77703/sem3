#include <iostream>
#include <string.h>

using namespace std;

class Student
{
	string name;
	int rate;
public:
	static int id;
	Student(string newName, int rateValue): name(newName), rate(rateValue)
	{
		id++;
	}
	Student() : name("Your Student"), rate(0)
	{
		id++;
	}
	void Print()
	{
		cout <<"ID: "<< id << "\n" <<"NAME: "<< name << "\n" <<"RATE: "<< rate << endl<<endl;
	}
	friend class Dekan;
	~Student()
	{}
};

class Dekan
{
public:
	void initRate(Student &student)
	{
		cout << "Enter rating of student: ";
		cin>>student.rate;
		cout << endl;
	}
};

int Student:: id=0;

int main()
{
	Dekan dekan;
	Student firstStudent;
	firstStudent.Print();
	dekan.initRate(firstStudent);
	firstStudent.Print();
	Student secondStudent("Alexander Shipko", 0);
	secondStudent.Print();
	dekan.initRate(secondStudent);
	secondStudent.Print(); 
	system("pause");
	system("cls");
	Student groupOfStudents[3];
	Student::id = 0;
	for (int i = 0; i < 3; i++)
	{
		Student::id++;
		groupOfStudents[i].Print();
		dekan.initRate(groupOfStudents[i]);
		groupOfStudents[i].Print();
	}
	return 0;
}
//в массиве динамический все с клавы
//проверки
//редактирование