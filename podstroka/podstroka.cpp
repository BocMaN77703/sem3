#include <iostream>
using namespace std;

void print(char* str, int start, int end)
{
    for (int i = start; i < end; i++)
    {
        cout << str[i];
    }
}


int main()
{
    char str[80], str2[20];
    cout << "Enter string:" << endl;
    rewind(stdin); 
    cin.get(str, 80);
    cout << "Enter podstring:" << endl;
    rewind(stdin);
    cin.get(str2, 20);
    int start = 0, end, flag = 0, spaceflag = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == ' ' && str[i + 1] == ' ')
        {
            for (int j=i; j < strlen(str); j++)
                str[j] = str[j + 1];
            i--;
        }
    }
    for (int i = 0; i < strlen(str)+1; i++)
    {
        if (str[i] == ' '|| str[i] == '\n'|| str[i] == '\0')
        {
            if (spaceflag == 0)
            {
                spaceflag = 1;
                end = i;
            }
            else
            {
                start = end;
                end = i;
            }
            if (flag == 2)
            {
                flag = 0;
                print(str, start, end);
            }
        }
        if (str[i] == str2[0])
        {
            for (int j = 0; j < strlen(str2); j++)
            {
                if (str[i + j] != str2[j])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1) flag = 0;
            else flag = 2;
        }
    }
    return 0;
}