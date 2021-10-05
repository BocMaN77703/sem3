#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class String
{
    int len;
    char* str;
public:
    static int size;
    String(const char* newString):len(strlen(newString)), str(new char[len+1])
    {
        strcpy(str, newString);
    }
    String()
    {
        len = 0;
        str = NULL;
    }
    String(const String& temp) : len(strlen(temp.str)), str(new char[len + 1])
    {
        strcpy(str, temp.str);
    }
    ~String()
    {
        delete[] str;
    }
    int Length()
    {
        return len;
    }
    void reverse()
    {
        char temp;
        for (int i = 0, j = strlen(str)-1; i < j; i++, j--)
        {
            temp = str[i];
            str[i] = str[j];
            str[j] = temp;
        }
    }
    String operator =(const String);
    friend istream& operator>> (istream&, String&);
    friend ostream& operator<< (ostream&, const String&);
    void* operator new(size_t);
    void* operator new[](size_t);
    void operator delete(void* ptr);
    void operator delete[](void* ptr);
    friend int sumChar(String);
    friend String* extra(String*);
};

int sumChar(String a)
{
    int sum=0;
    for (int i = 0; i < a.len; i++)
    {
        sum += a.str[i];
    }
    return sum;
}

String String::operator =(const String a)
{
    len = a.len;
    str = new char[len + 1];
    strcpy(str, a.str);
    return *this;
}

int String:: size = 0;

istream& operator>> (istream& in, String& str)
{
    char temp[1000];
    cout << "Enter string: ";
    rewind(stdin);
    cin.getline(temp, 1000);
    str.len = strlen(temp);
    str.str=new char[str.len + 1];
    strcpy(str.str, temp);
    return in;
}

ostream& operator<< (ostream& out, const String& str)
{
    for(int i=0; i<str.len; i++)
        out << str.str[i];
    out << endl;
    return out;
}

void* String::operator new(size_t size) 
{
    return ::operator new(size);
}

void* String::operator new[](size_t size)
{
    return ::operator new[](size);
}

void String::operator delete(void* ptr)
{
    ::operator delete(ptr);
}

void String::operator delete[](void* ptr)
{
    ::operator delete[](ptr);
}

int getInt(int right = 100, int left=0)
{
    int num;
    while (1)
    {
        cin >> num;
        cin.ignore(32767, '\n');
        if (cin.fail() || num < left || num>right)
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Incorrect value... Try again!" << endl;
        }
        else
        {
            system("cls");
            return num;
        }
    }
}

String* add(String *str)
{
    int size = str->size;
    cout << "Enter number of strings you want to add: ";
    int numToAdd = getInt();
    if (size == 0)
    {
        str = new String[numToAdd];
    }
    else
    {
        String* temp = new String[numToAdd+size];
        for (int i = 0; i < size; i++)
        {
            temp[i] = str[i];
        }
        delete[] str;
        str = temp;
    }
    for (int i = size; i < numToAdd+size; i++)
    {
        cin >> str[i];
    }
    str->size += numToAdd;
    system("pause");
    system("cls");
    return str;
}

void show(String* str)
{
    for (int i = 0; i < str->size; i++)
    {
        cout << "String[" << i + 1 << "]: " << str[i];
    }
    system("pause");
    system("cls");
}

String* sort(String* str)
{
    int* sum=new int[str->size];
    for (int i = 0; i < str->size; i++)
    {
        sum[i] = sumChar(str[i]);
    }
    String temp;
    int tmp;
    for (int i = 0; i < str->size-1; i++)
    {
        for (int j = 0; j < str->size-1-i; j++)
        {
            if (sum[j] < sum[j + 1])
            {
                temp = str[j];
                tmp = sum[j];
                str[j] = str[j + 1];
                sum[j] = sum[j + 1];
                str[j + 1] = temp;
                sum[j + 1] = tmp;
            }
        }
    }
    delete[]sum;
    show(str);
    return str;
}

String* extra(String* str)
{
    String* temp = new String[str->size+1];
    for (int i = 0; i < str->size; i++)
    {
        temp[i] = str[i];
    }
    delete[] str;
    str = temp;
    int maxlen=str[0].len;
    for (int i = 0; i < str->size-1; i++)
    {
        if (str[i].len < str[i + 1].len)
            maxlen = str[i + 1].len;
    }
    str[str->size].len = maxlen;
    str[str->size].str = new char[maxlen + 1];
    for (int i = 0; i < maxlen; i++)
    {
        int sum = 0;
        for (int j = 0; j < str->size; j++)
        {
            if (i < str[j].len)
            {
                sum += str[j].str[i];
            }
        }
        sum /= str->size;
        str[str->size].str[i] = sum;
    }
    str->size++;
    show(str);
    return str;
}

int main()
{
    /*String* str1 = new String;
    cin >> *str1;
    String* str2 = new String(*str1);
    str1->reverse();
    cout << *str1 << *str2;
    system("pause");
    system("cls");
    String* str = new String[3];
    for (int i = 0; i < 3; i++)
        cin >> str[i];
    system("pause");
    system("cls");
    for (int i = 0; i < 3; i++)
    {
        cout << "String[" << i + 1 << "]: " << str[i];
        cout << "Length: " << str[i].Length() << endl;
    }
    system("pause");
    system("cls");
    delete str1;
    delete str2;
    delete[] str;*/
    String* str=NULL;
    while (1)
    {
        cout << "1)Add\n2)Show\n3)Sort\n4)Extra string\n5)Exit" << endl;
        switch (getInt(5))
        {
        case 1:
            str=add(str);
            break;
        case 2:
            show(str);
            break;
        case 3:
            str=sort(str);
            break;
        case 4:
            str=extra(str);
            break;
        case 5:
            return 0;
        }
    }
}
//меню
//добавление
//показать все
// сорт по сумме чаров
//сумма/колво