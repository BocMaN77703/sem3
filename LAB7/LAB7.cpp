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

int main()
{
	int arr[10];
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
	system("cls");
	cout << "Enter string: ";
	//char* str = new char[100];
	char str[100];
	rewind(stdin);
	cin.getline(str, 30);
	Sort(str, strlen(str));
	for (int i = 0; i < strlen(str); i++)
	{
		cout << str[i];
	}
	system("pause");
	system("cls");
	//delete[] str;
	return 0;
}