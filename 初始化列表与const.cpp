#include<iostream>
using namespace std;
class Teacher
{
public:
	string t_name;
	Teacher()
	{
		t_name.clear();
		cout << "调用了Teacher()构造函数" << endl;
	}
	Teacher(string t)
	{
		t_name = t;
		cout << "调用了Teacher(string t)构造函数" << endl;
	}
	Teacher(const Teacher& n)
	{
		t_name = n.t_name;
		cout << "调用了Teacher(const Teacher& n)构造函数" << endl;
	}
};
class Student
{
public:
	string name;
	int age;
	Teacher m_teacher;//我的老师
	Student()//成员已经在初始化列表就不应该在构造函数中再次赋值
	{
		cout << "调用了构造函数" << endl;
	}
	//初始化列表中()可以是实参，形参，表达式
	Student(string n, int a, Teacher t_name) :name(n), age(a), m_teaher(t_name)
	{
		cout << "调用了传参的构造函数" << endl;
	}
	//成员函数不会修改成员变量就应该用const来修饰
	//mutable可以让成员函数在const中修改他的值
	//加了const的函数/对象 不能去调用没有加const的成员函数
	void show()const
	{
		cout << "名字:" << name << "年龄:" << age << "老师:" << m_teacher.t_name << endl;
	}

};
int main()
{
	Teacher js("王强");
	Student tx("张三", 18, js);
	tx.show();
}