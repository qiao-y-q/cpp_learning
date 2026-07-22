#include <iostream>
#include <string>
using namespace std;
// 1. 继承中的构造函数调用顺序
class GrandParent
{
public:
    GrandParent()
    {
        cout << "爷爷类构造" << endl;
    }
    ~GrandParent()
    {
        cout << "爷爷类析构" << endl;
    }
};

class Parent : public GrandParent
{
public:
    Parent()
    {
        cout << "父类构造" << endl;
    }
    ~Parent()
    {
        cout << "父类析构" << endl;
    }
};

class Child : public Parent
{
public:
    Child()
    {
        cout << "子类构造" << endl;
    }
    ~Child()
    {
        cout << "子类析构" << endl;
    }
};

//2. 多继承
class Flyable
{
public:
    void fly()
    {
        cout << "飞行中..." << endl;
    }
};

class Swimmable
{
public:
    void swim()
    {
        cout << "游泳中..." << endl;
    }
};

// 多继承：一个类继承多个父类
class Duck : public Flyable, public Swimmable
{
public:
    void quack()
    {
        cout << "嘎嘎叫" << endl;
    }
};

// 3. 菱形继承与虚继承
// 菱形继承：一个类被多个路径继承，会导致数据冗余和二义性
class Person
{
public:
    string id = "123456";
};

class Student : virtual public Person
{
};

class Teacher : virtual public Person
{
};

// 虚继承解决菱形继承问题
class TeachingAssistant : public Student, public Teacher
{
public:
    void show()
    {
        cout << "id = " << id << endl;  // 虚继承后，id 只有一份
    }
};

int main()
{
    cout << "\n3. 构造/析构调用顺序" << endl;
    {
        Child c;
        // 构造顺序：爷爷 → 父 → 子
        // 析构顺序：子 → 父 → 爷爷
    }

    cout << "\n4. 多继承" << endl;
    Duck duck;
    duck.fly();   // 从 Flyable 继承
    duck.swim();  // 从 Swimmable 继承
    duck.quack(); // 自己的方法

    cout << "\n5. 菱形继承（虚继承）" << endl;
    TeachingAssistant ta;
    ta.show();  // 虚继承保证 id 只有一份

    return 0;
}
