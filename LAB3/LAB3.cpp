#include <iostream>

using namespace std;

class Float
{
	double num;
public:
	Float(double val) : num(val)
	{	}
	Float() :num(0.0){}
	void print()
	{
		cout << num<<endl;
	}
	Float operator =(const Float);
	Float operator +(const Float);
	Float operator ++();
	Float operator ++(int);
	bool operator <(const Float);
	friend ostream& operator<<(ostream&, const Float&);
	friend Float operator --(Float&);
	friend Float operator --(Float&, int);
	friend Float operator -(Float&, double value);
	friend Float operator -(double value, Float&);
	friend bool operator==(Float&, double value);
	friend bool operator==(double value, Float&);
	operator double();
};

Float Float::operator =(const Float a)
{
	num = a.num;
	return *this;
}

Float Float::operator +(const Float a)
{
	Float temp;
	temp = num+a.num;
	return temp;
}

Float Float::operator ++()
{
	++num;
	return Float(num);
}

Float Float::operator ++(int a)
{
	return Float(num++);
}

bool Float::operator <(const Float a)
{
	return (num < a.num ) ? true : false;
}

ostream& operator<<(ostream& out, const Float& a)
{
	out << "Your number is: " << a.num << endl;
	return out;
}

Float operator --(Float &a)
{
	--a.num;
	return Float(a.num);
}

Float::operator double()
{
	double temp = num;
	return temp;
}

Float operator --(Float& a, int b)
{
	return Float(a.num--);
}

Float operator -(Float& a, double value)
{
	return(a.num - value);
}

Float operator -(double value, Float& a)
{
	return(value-a.num);
}

bool operator==(Float& a, double value)
{
	
	return (a.num==value) ? true : false;
}

bool operator==(double value, Float& a)
{

	return (value==a.num) ? true : false;
}

int main()
{
	Float a(5.3), b(9.7), c;
	cout << a + b << ++b << --a;
	c = a - 0.3;
	if(a<b)	cout << c;
	return 0;
}