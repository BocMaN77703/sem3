#include <iostream>
#include <string>

using namespace std;

template <typename T>
T* Sort(T* a, int size)
{
	T temp=0;
	int i, j, dp;
	for (dp = size / 2; dp > 0; dp /= 2)
	{
		for (i = dp; i < size; i++)
		{
			for (j = i - dp; j >= 0 && a[j] > a[j + dp]; j -= dp)
			{
				temp = a[j];
				a[j] = a[j + dp];
				a[j + dp] = temp;
			}
		}
	}
	return a;
}

void getnums(char* str, char* str1)
{
	int j = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			str1[j] = str[i];
			j++;
		}
	}
	str1[j] = '\0';
}

void getchars(char* str, char* str2)
{
	int j = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		if ((str[i] >= 'A' && str[i] <= 'Z')||(str[i] >= 'a' && str[i] <= 'z'))
		{
			str2[j] = str[i];
			j++;
		}
	}
	str2[j] = '\0';
}

void getspecialchars(char* str, char* str3)
{
	int j = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i]<'0'||(str[i]>'9' && str[i]<'A')||(str[i]>'Z'&&str[i]<'a')|| str[i]>'z')
		{
			str3[j] = str[i];
			j++;
		}
	}
	str3[j] = '\0';
}

int main()
{
	/*int arr[10];
	cout << "Enter array:\n";
	for (int i = 0; i < 10; i++)
	{
		cin >> arr[i];
	}
	Sort(arr, 10);
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i]<<" ";
	}
	system("pause");
	system("cls");*/
	cout << "Enter string: ";
	char str[100];
	char str1[100], str2[100], str3[100];
	rewind(stdin);
	cin.getline(str, 100);
	//Sort(str, strlen(str));
	getnums(str, str1);
	getchars(str, str2);
	getspecialchars(str, str3);
	Sort(str1, strlen(str1));
	Sort(str2, strlen(str2));
	Sort(str3, strlen(str3));
	system("cls");
	cout << "Your string is:\n";
	puts(str);
	cout << endl << endl;
	cout << "Sorted strings:\nYour sorted string:\n";
	Sort(str, strlen(str));
	puts(str);
	cout << endl << endl;
	cout << "Sorted string of ints:\n";
	puts(str1);
	cout << endl << endl;
	cout << "Sorted string of chars:\n";
	puts(str2);
	cout << endl << endl;
	cout << "Sorted string of special chars:\n";
	puts(str3);
	cout << endl << endl;
	system("pause");
	system("cls");
	return 0;
}
//функция для чара
//разбивать на 3 строки
//инты с числами
//буквы
//символы
//сразу сортить
