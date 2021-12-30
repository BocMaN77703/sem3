#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class ExceptionClass : public exception
{
public:
    ExceptionClass(const char* message) :exception(message) {}
    ~ExceptionClass() {}
    void wrongValue()
    {
        cin.clear();
        cin.ignore(100, '\n');
    }
};

int menu()
{
    int choise;
    while (true)
    {
        try
        {
            cout << "Choose:\n1)Add string to file\n2)Show file\n3)Count element\n4)Count chars(a-z)\n0)Exit\n";
            cin >> choise;
            if (cin.fail() || choise < 0 || choise>4)
            {
                system("cls");
                throw ExceptionClass("Incorrect value!!! Try again...\n");
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

void add()
{
    system("cls");
    vector<string> addArr;
    int num;
    while (true)
    {
        try
        {
            cout << "How many strings you want to add: ";
            cin >> num;
            if (cin.fail() || num < 0)
            {
                system("cls");
                throw ExceptionClass("Incorrect value!!! Try again...\n");
            }
            break;
        }
        catch (ExceptionClass& ex)
        {
            ex.what();
            ex.wrongValue();
        }
    }
    for (int i = 0; i < num; i++)
    {
        string str;
        cout << "Enter string: ";
        rewind(stdin);
        getline(cin, str);
        addArr.push_back(str);
    }
    ofstream out("origin.txt", ios::in | ios::out | ios::app);
    try
    {
       cout << "Opening origin file...";
       if (!out)	throw ExceptionClass("Can't open the file!");
    }
    catch (ExceptionClass& ex)
    {
        ex.what();
    }
    cout << "Origin file opened!!!"<<endl;
    for (int i = 0; i < addArr.size(); i++)
    {
       out << addArr[i]<<endl;
    }
    out.close();
    cout << "File closed!" << endl;
}

void print()
{
    system("cls");
    ifstream in("origin.txt", ios::in | ios::out);
    try
    {
        cout << "Opening origin file..."<<endl;
        if (!in)	throw ExceptionClass("Can't open the file!");
    }
    catch (ExceptionClass& ex)
    {
        ex.what();
    }
    cout << "Origin file opened!" << endl;
    string temp;
    vector<string> fromFile;
    while (getline(in, temp))
    {
        fromFile.push_back(temp);
    }
    for (int i = 0; i < fromFile.size(); i++)
    {
        cout << fromFile[i] << endl;
    }
    in.close();
    cout << "File closed!" << endl;
}

void count()
{
    system("cls");
    ifstream in("origin.txt", ios::in | ios::out);
    try
    {
        cout << "Opening origin file..." << endl;
        if (!in)	throw ExceptionClass("Can't open the file!");
    }
    catch (ExceptionClass& ex)
    {
        ex.what();
    }
    cout << "Origin file opened!" << endl;
    string temp;
    vector<int> counter;
    int i = 0;
    while (getline(in, temp))
    {
        cout << "String #" << i <<" " << temp << endl;
        char c;
        cout << "Enter symbol to count: ";
        int count = 0;
        rewind(stdin);
        c = getchar();
        for (int i = 0; i < temp.length(); i++)
        {
            if (temp[i] == c)  count++;
        }
        counter.push_back(count);
        cout <<"In string "<<i<<" symbol '"<<c<<"' is located " << counter[i] <<" times" << endl<<endl;
        i++;
    }
    in.close();
    cout << "Origin file closed!" << endl;
    ofstream out("result.txt", ios::in | ios::out);
    try
    {
        cout << "Opening result file...";
        if (!out)	throw ExceptionClass("Can't open the file!");
    }
    catch (ExceptionClass& ex)
    {
        ex.what();
    }
    cout << "Result file opened!!!" << endl;
    for (int i = 0; i < counter.size(); i++)
    {
        out << counter[i] << endl;
    }
    out.close();
    cout << "Result file closed!" << endl;
}
    
void countLetters()
{
    system("cls");
    ifstream in("origin.txt", ios::in | ios::out);
    try
    {
        cout << "Opening origin file..." << endl;
        if (!in)	throw ExceptionClass("Can't open the file!");
    }
    catch (ExceptionClass& ex)
    {
        ex.what();
    }
    cout << "Origin file opened!" << endl;
    string temp;
    vector<string> origin;
    while (getline(in, temp))
    {
        origin.push_back(temp);
    }
    in.close();
    cout << "Origin file closed!" << endl;
    ofstream out("coutchars.txt", ios::in | ios::out|ios::app);
    try
    {
        cout << "Opening result file...";
        if (!out)	throw ExceptionClass("Can't open the file!");
    }
    catch (ExceptionClass& ex)
    {
        ex.what();
    }
    cout << "Result file opened!!!" << endl;
    for (int i = 0; i < origin.size(); i++)
    {
        vector<int> result;
        for (int x = 0; x < 26; x++)
        {
            char compare = 'a' + x;
            int counter = 0;
            for (int j = 0; j < origin[i].size(); j++)
            {
                if (origin[i][j] == compare)   counter++;
            }
            result.push_back(counter);
            //result.insert(pair<char, int>(compare, counter));
        }
        char c = 96;
        out <<endl<< "String: " << origin[i] << endl;
        for (int z = 0; z < result.size(); z++)
        {
            c ++;
            out << c << " - ";
            out << result[z] << endl;
        }
        out <<endl<< "----------------------------";
    }
    out.close();
    cout << "Result file closed!" << endl;
}

int main()
{
    while (1)
    {
        switch (menu())
        {
        case 1:
            add();
            break;
        case 2:
            print();
            break;
        case 3:
            count();
            break;
        case 4:
            countLetters();
            break;
        case 0:
            return 0;
        }
    }
}
//a-z сколько раз встречается каждый символ