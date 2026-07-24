#include <iostream>
#include <vector>
#include<string>
using namespace std;
//vector容器构造
void printvector(vector <int>& v)
{
	for (vector <int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test1()
{
	vector <int> v;
	for (int i = 0; i < 5; i++)
	{
		v.push_back(i);
	}
	printvector(v);
	vector <int> v2(v.begin(), v.end());
	printvector(v2);
	vector <int> v3(10, 2);//传入10个2
	printvector(v3);
	vector<int>v4(v3);//拷贝构造
	printvector(v4);
	//赋值
	vector<int>v5;
	v5 = v4;
	printvector(v5);
	vector<int>v6;
	v6.assign(v.begin(), v.end());
	vector<int>v7;
	v7.assign(5, 2);//赋值5个2

}
//vector容器容量和大小
void test2()
{
	vector <int> v;
	for (int i = 0; i < 5; i++)
	{
		v.push_back(i);
	}
	printvector(v);
	//判断容器是否为空
	if (v.empty())//为真代表容器为空
	{
		cout << "v为空" << endl;
	}
	else
	{
		cout << "v不为空" << endl;
		cout << "v的容量" << v.capacity() << endl;
		cout << "v的大小" << v.size() << endl;
	}
	//重新指定大小
	v.resize(15);
	printvector(v);
	v.resize(15, 100);//可以利用重载版本来指定默认值为100
	printvector(v);
	//如果重新指定的比原来短会删除超出的部分
	v.resize(5);
	printvector(v);
}
//vector的插入和删除
void test3()
{
	vector <int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	printvector(v);
	v.pop_back();//尾删
	printvector(v);
	//插入
	v.insert(v.begin(), 5);
	v.insert(v.begin(), 2, 5);//重载在开头插入2个5
	v.erase(v.begin());
	v.erase(v.begin(), v.end());//从头到尾全删等同于clear
}
//vector数据存储
void test4()
{
	vector <int> v;
	for (int i = 0; i < 5; i++)
	{
		v.push_back(i);
	}
	cout << "获取第一个元素" << v.front() << endl;
	cout << "获取最后一个元素" << v.back() << endl;
}
//vector互换容器
//1.基本的使用
void test5()
{
	vector <int> v1;
	for (int i = 0; i < 7; i++)
	{
		v1.push_back(i);
	}
	printvector(v1);
	vector <int> v2;
	for (int i = 7; i > 0; i--)
	{
		v2.push_back(i);
	}
	printvector(v2);
	//交换后
	v1.swap(v2);
	printvector(v1);
	printvector(v2);
}
//2.实际的用途//巧用swap可以收缩内存空间
void test6()
{
	vector <int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	cout << "v的容量" << v1.capacity() << endl;
	cout << "v的大小" << v1.size() << endl;
	v1.resize(5);
	cout << "v的容量" << v1.capacity() << endl;
	cout << "v的大小" << v1.size() << endl;
	//重新指定大小后容量还是不变
	//利用swap收缩空间
	vector <int>(v1).swap(v1);//vector <int>(v1)//匿名对象代码执行完就会被释放
	cout << "v的容量" << v1.capacity() << endl;
	cout << "v的大小" << v1.size() << endl;
}
//vector预留空间
//reserve(int len)容器预留len个元素的长度，预留位置未初始化，元素不可访问
void test7()
{
	vector <int> v;
	int num = 0;
	int* p = NULL;
	//利用reserve预留空间
	v.reserve(10000);
	for (int i = 0; i < 10000; i++)
	{
		v.push_back(i);
	}
	if (p != &v[0])
	{
		p = &v[0];
		num++;
	}
	cout << num << endl;
}
int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	return 0;
}