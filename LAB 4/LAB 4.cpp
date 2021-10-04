#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class String
{
    int len;
    char* str;
public:
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
    friend istream& operator>> (istream&, String&);
    friend ostream& operator<< (ostream&, const String&);
    void* operator new(size_t);
    void* operator new[](size_t);
    void operator delete(void* ptr);
    void operator delete[](void* ptr);
};

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

int main()
{
    String* str1 = new String;
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
    delete[] str;
    return 0;
}
//меню
//добавление
//показать все
// сорт по сумме чаров
//сумма/колво