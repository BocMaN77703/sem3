#include <iostream>
#include <string.h>
int main()
{
    char* str;
    str = (char*)calloc(80, sizeof(char));
    std::cout<<"Enter string:"<<std::endl;
    std::cin.get(str, 80);
    std::cout << "Hello World! ";
    int num=0;
    for (int i = strlen(str); i >= 0; i--)
    {
        if (str[i] >= '9' || str[i] <= '0')
            std::cout << str[i];
        else
            num += str[i] - '0';
    }
    std::cout << num << std::endl;
    free(str);
    return 0;
}
