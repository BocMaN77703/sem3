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
	void show(int i)
	{
		cout << "Your array #"<<i<<" is:\n";
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
		if (!flag)	cout << x << " not found\n";
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
	void plenty()
	{
		int tmp[10];
		int* plenty;
		int counter = 0;
		for (int i = 0; i < 10; i++)
		{
			cout << "Enter element of plenty: ";
			cin >> tmp[i];
			if (cin.fail() || arr[i] < 0)
			{
				system("cls");
				throw ExceptionClass("Incorrect value!!!Try again...\n");
			}
			counter++;
			cout << "Do you want to continue(y/n): ";
			rewind(stdin);
			if (getchar() == 'n') break;
		}
		plenty = (int*)calloc(counter, sizeof(int));
		for (int i = 0; i < counter; i++)
		{
			plenty[i] = tmp[i];
		}
		bool flag1=false;
		int pos1, pos2, i=0, j=0;
		for (i = 0; i < 10-counter+1; i++)
		{
			if (arr[i] == plenty[0])
			{
				pos1 = i;
				for ( j = 0, i; j<counter; i++, j++)
				{
					if (arr[i] == plenty[j]) flag1 = true;
					else
					{
						flag1 = false;
						break;
					}
				}
			}
		}
		if (flag1)
		{
			while (1)
			{
				cout << "Enter number of position on which you want to put your plenty: ";
				cin >> pos2;
				if (cin.fail() || pos2 < 0 || pos2>(10 - counter+1))
				{
					cin.clear();
					cin.ignore(100, '\n');
					cout << "Incorrect value!\n";
				}
				break;
			}
			int temp;
			for (i = pos2,j=0; j < counter; i++, j++)
			{
				temp = arr[i];
				arr[i] = plenty[j];
				plenty[j] = temp;
			}
			if (pos2>pos1)
			{
				for (i = pos1, j=pos1+counter; j < pos2+1; i++, j++)
				{
					arr[i] = arr[j];
				}
				for (i=i-1, j=0; j < counter; i++, j++)
				{
					arr[i] = plenty[j];
				}
			}
			else if (pos1>pos2)
			{
				for (i, j = 0; j < counter; i++, j++)
				{
					if (i >= counter + pos1) break;
					temp = arr[i];
					arr[i] = plenty[j];
					plenty[j] = temp;
					if (j+1 == counter)	j = -1;
				}
			}
		}
		free(plenty);
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

int menu()
{
	int choise;
	while (true)
	{
		try
		{
			cout << "Choose:\n1)Add\n2)Show\n3)Delete\n4)Search\n5)Compare\n6)Assignment\n7)Extra\n0)Exit\n";
			cin >> choise;
			if (cin.fail() || choise < 0 || choise>7)
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

Array* add(Array* array, int& size)
{
	size++;
	array = (Array*)realloc(array, sizeof(Array) * size);
	while (true)
	{
		try
		{
			array[size-1].init();
			break;
		}
		catch (ExceptionClass& ex)
		{
			cout << ex.what();
			ex.wrongValue();
		}
	}
	return array;
}

void show(Array* array, int size)
{
	system("cls");
	if (size == 0)
	{
		system("cls");
		throw ExceptionClass("Error! Array is empty...\n");
	}
	for (int i = 0; i < size; i++)
	{
		array[i].show(i);
		cout << endl;
	}
}

void search(Array* array, int size)
{
	system("cls");
	if (size == 0)
	{
		system("cls");
		throw ExceptionClass("Error! Array is empty...\n");
	}
	for (int i = 0; i < size; i++)
	{
		cout << "Search int the array #" << i << endl;
		array[i].search();
	}
}

Array* del(Array* array, int& size)
{
	system("cls");
	if (size == 0)
	{
		system("cls");
		throw ExceptionClass("Error! Array is empty...\n");
	}
	show(array, size);
	int choise;
	while (1)
	{
		try
		{
			cout << "Enter number of array you want to delete: ";
			cin >> choise;
			if (cin.fail() || choise < 0 || choise >= size)
			{
				throw ExceptionClass("Incorrect value! Try again!\n");
				system("cls");
			}
			break;
		}
		catch (ExceptionClass& ex)
		{
			ex.what();
			ex.wrongValue();
		}
	}
	for (int i = choise; i < size; i++)
	{
		array[i] = array[i + 1];
	}
	size--;
	array = (Array*)realloc(array, sizeof(Array) * size);
	return array;
}

void compare(Array* array, int size)
{
	system("cls");
	if (size <2)
	{
		system("cls");
		throw ExceptionClass("Error! Not enough elements in the array!\n");
	}
	int x1=0, x2=0;
	while (1)
	{
		try
		{
			cout << "Enter first number of array you want to compare: ";
			cin >> x1;
			if (cin.fail() || x1 < 0 || x1 >= size)
			{
				throw ExceptionClass("Error! There is no such array!\n");
				system("cls");
			}
			cout << "Enter second number of array you want to compare: ";
			cin >> x2;
			if (cin.fail() || x2 < 0 || x2 >= size)
			{
				throw ExceptionClass("Error! There is no such array!\n");
				system("cls");
			}
			break;
		}
		catch (ExceptionClass& ex)
		{
			ex.what();
			ex.wrongValue();
		}
	}
	if (array[x1].compare(array[x2]))	cout << "array["<<x1<<"] > array["<<x2<<"]" << endl;
	else cout << "array[" << x1 << "] < array[" << x2 << "]" << endl;
}

Array* assignment(Array* array, int size)
{
	system("cls");
	if (size < 2)
	{
		system("cls");
		throw ExceptionClass("Error! Not enough elements in the array!\n");
	}
	int x1 = 0, x2 = 0;
	while (1)
	{
		try
		{
			cout << "Enter first number of array: ";
			cin >> x1;
			if (cin.fail() || x1 < 0 || x1 >= size)
			{
				throw ExceptionClass("Error! There is no such array!\n");
				system("cls");
			}
			cout << "Enter second number of array: ";
			cin >> x2;
			if (cin.fail() || x2 < 0 || x2 >= size)
			{
				throw ExceptionClass("Error! There is no such array!\n");
				system("cls");
			}
			break;
		}
		catch (ExceptionClass& ex)
		{
			ex.what();
			ex.wrongValue();
		}
	}
	array[x1].getarr(array[x2]);
	return array;
}

void plentychange(Array* array, int size)
{
	system("cls");
	if (size == 0)
	{
		system("cls");
		throw ExceptionClass("Error! Array is empty...\n");
	}
	show(array, size);
	int choise;
	while (1)
	{
		try
		{
			cout << "Enter number of array you want to change: ";
			cin >> choise;
			if (cin.fail() || choise < 0 || choise >= size)
			{
				throw ExceptionClass("Incorrect value! Try again!\n");
				system("cls");
			}
			break;
		}
		catch (ExceptionClass& ex)
		{
			ex.what();
			ex.wrongValue();
		}
	}
	array[choise].plenty();
}

int main()
{
	/*set_terminate(myTerminate);
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
	throw;*/
	Array* array=NULL;
	int size = 0;
	while (1)
	{
		switch (menu())
		{
		case 1:
			array=add(array, size);
			break;
		case 2:
			try
			{
				show(array, size);
			}
			catch(ExceptionClass& ex)
			{
				cout << ex.what();
			}
			break;
		case 3:
			try
			{
				array=del(array, size);
			}
			catch (ExceptionClass& ex)
			{
				cout << ex.what();
			}
			break;
		case 4:
			try
			{
				search(array, size);
			}
			catch (ExceptionClass& ex)
			{
				cout << ex.what();
			}
			break;
		case 5:
			try
			{
				compare(array, size);
			}
			catch (ExceptionClass& ex)
			{
				cout << ex.what();
			}
			break;
		case 6:
			try
			{
				array=assignment(array, size);
			}
			catch (ExceptionClass& ex)
			{
				cout << ex.what();
			}
			break;
		case 7:
			try
			{
				plentychange(array, size);
			}
			catch (ExceptionClass& ex)
			{
				cout << ex.what();
			}
			break;
		case 0:
			free(array);
			return 0;
		}
	}
}
//Меню
//Исключение несуществующих элементов
//функция пермещения множества