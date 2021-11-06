#include <iostream>

using namespace std;

class ExceptionClass : public exception
{
public:
	ExceptionClass(const char* message):exception(message){}
	~ExceptionClass(){}
	void wrongValue()
	{
		cin.clear();
		cin.ignore(100, '\n');
	}
};

class Array
{
	int arr[10];
public:
	Array()
	{
		for (int i = 0; i < 10; i++)
		{
			arr[i] = 0;
		}
	}
	Array(int* newArr)
	{
		for (int i = 0; i < 10; i++)
		{
			arr[i] = newArr[i];
		}
	}
	void init()
	{
		cout << "Enter array:\n";
		for (int i = 0; i < 10; i++)
		{
			cout << "arr[" << i << "]= ";
			cin >> arr[i];
			if (cin.fail() || arr[i] < 0)
			{
				system("cls");
				throw ExceptionClass("Incorrect value!!!Try again...\n");
			}
		}
	}
	void show()
	{
		cout << "Your array is: ";
		for (int i = 0; i < 10; i++)
		{
			cout << arr[i]<<" ";
		}
		cout << endl;
	}
	void search()
	{
		bool flag=false;
		int x;
		cout << "Enter number to search in the array: ";
		cin >> x;
		if (cin.fail() || x < 0)
		{
			system("cls");
			throw ExceptionClass("Incorrect value!!! Try again...\n");
		}
		for (int i = 0; i < 10; i++)
		{
			if (x == arr[i])
			{
				cout << "arr[" << i << "]= " << x<<endl;
				flag = true;
			}
		}
		if (!flag)	cout << x << " not found";
	}
	bool compare(const Array arr2)
	{
		int sum1 = 0, sum2 = 0;
		for (int i = 0; i < 10; i++)
		{
			sum1 += arr[i];
			sum2 += arr2.arr[i];
		}
		if (sum1 > sum2)	return true;
		else return false;
	}
	void getarr(const Array arr2)
	{
		for (int i = 0; i < 10; i++)
		{
			arr[i] = arr2.arr[i];
		}
	}
};

void myTerminate()
{
	cout << "That's my terminate() function!!!\n";
	exit(2003);
}

void myUnexpected()
{
	cout << "That's my unexpected() function!!!\n";
	throw;
}

int main()
{
	set_terminate(myTerminate);
	set_unexpected(myUnexpected);
	int array1[10] = {1,10,12,11,100,0,125,11,9,7};
	int array2[10] = { 1,2,3,4,5,6,7,8,9 };
	Array x(array2), z(array1), y;
	while (true)
	{
		try
		{
			y.init();
			break;
		}
		catch (ExceptionClass& ex)
		{
			cout << ex.what();
			ex.wrongValue();
		}
	}
	system("pause");
	system("cls");
	y.show();
	while (true)
	{
		try
		{
			y.search();
			break;
		}
		catch (ExceptionClass& ex)
		{
			cout << ex.what();
			ex.wrongValue();
		}
	}
	system("pause");
	system("cls");
	y.getarr(x);
	y.show();
	system("pause");
	system("cls");
	if (x.compare(z))	cout << "x > z"<<endl;
	else cout << "x < z"<<endl;
	//throw;
	return 0;
}