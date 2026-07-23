#include <iostream>
#include <vector>
#include<string>
using namespace std;
//string本质是一个类，里面有很多构造函数，利用函数重载调用不同函数
void test1()
{
	string s1;//默认构造
	//string（const char* s）//使字符s初始化
	const char* str = "hello";
	string s2(str);
	cout << s2 << endl;
	//string（const string& str）//拷贝构造函数
	string s3(s2);
	cout << s3 << endl;
	//string（int n，char c）//使n个字符c初始化
	string s4(3, 'a');
	cout << s4 << endl;
}
//string赋值操作
//=和.assign指赋值
void test2()
{
	string s1;
	s1 = "hello";
	cout << s1 << endl;

	string s2;
	s2 = s1;
	cout << s2 << endl;

	string s3;
	s3 = 'a';
	cout << s3 << endl;

	string s4;
	s4.assign("hello world");
	cout << s4 << endl;

	string s5;
	s5.assign("hello world", 5);//表示吧字符串前5个赋值给s5
	cout << s5 << endl;

	string s6;
	s6.assign(s5);
	cout << s6 << endl;

	string s7;
	s7.assign(3, 'w');
	cout << s7 << endl;
}
//string字符串拼接
//string中+=和.append指拼接到字符串末尾
void test3()
{
	string s1;
	s1 = "我";
	s1 += "爱玩游戏";
	cout << s1 << endl;

	s1 += ':';
	cout << s1 << endl;

	string s2;
	s2 = "LOL DNF";
	s1 += s2;
	cout << s1 << endl;

	string s3;
	s3 = 'I';
	s3.append("love");
	cout << s3 << endl;

	s3.append("game 1111", 4);//从头开始截取4个拼接到尾部
	cout << s3 << endl;

	s3.append(s2, 0, 3);//从s2中第0个开始截取3个结束，拼接到尾部
	cout << s3 << endl;
}
int main()
{
	test1();
	test2();
	test3();
	return 0;
}