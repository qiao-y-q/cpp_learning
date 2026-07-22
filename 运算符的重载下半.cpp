#include<iostream>
#include<string>
using namespace std;
class MyPrint
{
public:
	//重载一个函数调用运算符
	void operator()(string test)
	{
		cout << test << endl;
	}
};
//仿函数非常灵活，没有固定的写法
class MyAdd
{
public:
	int operator()(int num1, int num2)
	{
		return num1 + num2;
	}
};
void MyPrint2(string test2)
{
	cout << test2 << endl;
}

void test1()
{
	MyPrint mp;
	mp("hello world");
	MyPrint2("hello world");
}
void test2()
{
	MyAdd add;
	int ret = add(100, 200);
	cout << ret << endl;
}
int main()
{
	test1();
	test2();
	system("pause");
	return 0;
}