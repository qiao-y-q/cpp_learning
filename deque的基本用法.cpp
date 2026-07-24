#include <iostream>
#include <deque>
#include<string>
#include<algorithm>//标准算法头文件
using namespace std;
void print(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		//*it = 10;改为const就不能在这里面更改，变成只读状态
		cout << *it << " ";
	}
}
//deque构造
void test1()
{
	deque<int>d;
	for (int i = 0; i < 10; i++)
	{
		d.push_back(i);
	}
	cout << endl;
	print(d);
	deque<int>d2(d.begin(), d.end());
	deque<int>d3(3, 2);
	deque<int>d4(d3);

}
//deque的赋值
void test2()
{
	deque<int>d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	deque<int>d2;
	d2 = d1;
	deque<int>d3;
	d3.assign(d1.begin(), d2.end());
	deque<int>d4;
	d4.assign(4, 5);
}
//deque的大小操作
//没有容量只有大小
void test3()
{
	deque<int>d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	if (d1.empty())
	{
		cout << "d1为空" << endl;
	}
	else
	{
		cout << "d1不为空" << endl;
		cout << "d1的大小" << d1.size() << endl;
	}
	d1.resize(3);
	d1.resize(5, 3);
}
//deque插入和删除
void test4()
{
	deque<int>d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	d1.push_front(5);
	d1.pop_back();//头删
	d1.pop_front();//尾删
	print(d1);
	deque<int>d2;
	d2.insert(d2.begin(), 10);
	d2.insert(d2.begin(), 2, 10);
	print(d2);
	d1.insert(d1.begin(), d2.begin(), d2.end());
	print(d1);
	deque<int>::iterator it = d1.begin();
	it++;
	d1.erase(it);//将第一个元素后一个元素删除
	d1.clear();//d1.erase(d1.begin(),d1.end())区间删除
}
//deque数据存取
void test5()
{
	deque<int>d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	//通过[]的方式访问
	for (int i = 0; i < d1.size(); i++)
	{
		cout << d1[i] << " ";
	}
	//通过at的方式访问
	for (int i = 0; i < d1.size(); i++)
	{
		cout << d1.at(i) << " ";
	}
	cout << "第一个元素" << d1.front() << endl;
	cout << "最后一个元素" << d1.back() << endl;
}
//deque的排序算法
void test6()
{
	deque<int>d1;
	d1.push_back(2);
	d1.push_back(5);
	d1.push_back(6);
	d1.push_front(7);
	d1.push_front(1);
	d1.push_front(4);
	print(d1);
	//对于支持随机访问的迭代器的容器，都可以用sort进行排序
	sort(d1.begin(), d1.end());//升序
	print(d1);
}
int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	return 0;
}

