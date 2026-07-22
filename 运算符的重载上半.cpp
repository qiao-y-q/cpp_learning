#include<iostream>
using namespace std;
class MyInteger
{
	friend ostream& operator<<(ostream& cout, const MyInteger myint);
public:
	MyInteger()//构造函数赋初值
	{
		m_num = 0;
	}
	MyInteger& operator++()//重载＋＋运算符
	{
		m_num++;
		return *this;
	}
	MyInteger operator++(int)
	{
		MyInteger temp = *this;//先记录
		m_num++;//后++
		return temp;//返回先前记录的值
	}
	MyInteger& operator--()
	{
		m_num--;
		return *this;
	}
private:
	int m_num;
};
ostream& operator<<(ostream& cout, const MyInteger myint)
{
	cout << myint.m_num;
	return cout;
}
void test1()//前置先＋＋在返回
{
	MyInteger myint;
	cout << ++myint << endl;
	cout << myint << endl;
}
void test2()
{
	MyInteger myint;
	cout << myint++ << endl;
	cout << myint << endl;
}
void test3()
{
	MyInteger myint;
	cout << --myint << endl;
	cout << myint << endl;
}
int main()
{
	test1();
	test2();
	test3();
	system("pause");
	return 0;
}
