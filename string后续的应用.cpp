#include <iostream>
#include <vector>
#include<string>
using namespace std;
//string的查找和替换
//1.查找
void test1()
{
	string str1 = "ascdefg";
	int pos = str1.find("de");
	cout << pos << endl;
	if (pos == -1)
	{
		cout << "未找到字符串" << endl;
	}
	else
	{
		cout << "找到字符串" << endl;
	}
	//rfind和find的区别
	//rfind从右往左查找   find从左往右查找
	pos = str1.rfind("de");
	cout << pos << endl;
}
//2.替换
void test2()
{
	string str2 = ("abcde");
	str2.replace(1, 3, "11111");//从下标为1的字符开始后3个字符被替换成11111
	cout << str2 << endl;
}
//字符串比较//利用ACSLL码值进行比较
//从第一个字符开始逐个对比
void test3()
{
	string str3 = ("hello");
	string str4 = ("hell");
	if (str3.compare(str4) == 0)
	{
		cout << "str3=str4" << endl;
	}
	else if (str3.compare(str4) > 0)
	{
		cout << "str3>str4" << endl;
	}
	else
	{
		cout << "str3<str4" << endl;
	}
}
//string字符存取
void test4()
{
	string str5 = "sssss";
	//1.通过[]来访问单个字符
	for (int i = 0; i < str5.size(); i++)
	{
		cout << str5[i] << " ";
	}
	//2.通过at方式访问单子字符
	for (int i = 0; i < str5.size(); i++)
	{
		cout << str5.at(i) << " ";
	}
	//修改字符
	str5[1] = 'x';
	str5.at(2) = 'a';
	cout << str5 << endl;
}
//string插入和删除
void test5()
{
	//插入
	string str6 = "aaaaa";
	str6.insert(1, "111");
	cout << str6 << endl;
	//删除
	str6.erase(1, 3);
	cout << str6 << endl;
}
//string子串
void test6()
{
	string str8 = "abcdef";
	string s = str8.substr(1, 3);
	cout << s << endl;
}
void test7()
{
	string str9 = "zhangsan@sina.com";
	int pos = str9.find("@");
	string s = str9.substr(0, pos);
	cout << s << endl;
}
int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	return 0;
}