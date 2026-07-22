//继承可以减少重复的代码
//语法：class 子类（派生类）：继承方式 父类(基类)
//父类的私有成员子类无法访问,不管那种继承方式都不行
//共有继承；父类的public和protected的成员在子类中原封不动
//保护继承:父类的public和protected的成员在子类中变成了protected成员
//私有继承:父类的public和protected的成员在子类中变成了private成员
#include <iostream>
#include <string>
using namespace std;

// ==================== 1. 基本继承 ====================
// 基类（父类）
class Animal
{
public:
    string name;
    int age;

    Animal() : name("无名"), age(0)
    {
        cout << "【Animal构造函数】" << endl;
    }

    Animal(string n, int a) : name(n), age(a)
    {
        cout << "【Animal带参构造函数】" << name << endl;
    }

    void eat()
    {
        cout << name << " 在吃东西" << endl;
    }

    void sleep()
    {
        cout << name << " 在睡觉" << endl;
    }

    virtual ~Animal()
    {
        cout << "【Animal析构函数】" << name << endl;
    }
};

// 派生类（子类）- 公有继承
class Dog : public Animal
{
public:
    string breed;  // 品种

    Dog() : breed("未知")
    {
        cout << "【Dog构造函数】" << endl;
    }

    Dog(string n, int a, string b) : Animal(n, a), breed(b)
    {
        cout << "【Dog带参构造函数】" << name << " 品种:" << breed << endl;
    }

    void bark()
    {
        cout << name << " 汪汪叫" << endl;
    }

    void fetch()
    {
        cout << name << " 接飞盘" << endl;
    }

    ~Dog()
    {
        cout << "【Dog析构函数】" << name << endl;
    }
};

// ==================== 2. 不同继承方式 ====================
class Base
{
public:
    int pub = 1;

protected:
    int prot = 2;

private:
    int priv = 3;
};

// 公有继承：public → public, protected → protected, private → 不可访问
class PubDerived : public Base
{
public:
    void test()
    {
        cout << "pub = " << pub << endl;    //  可访问
        cout << "prot = " << prot << endl;  //  可访问
        // cout << "priv = " << priv << endl; // 不可访问
    }
};

// 保护继承：public → protected, protected → protected, private → 不可访问
class ProtDerived : protected Base
{
public:
    void test()
    {
        cout << "pub = " << pub << endl;    // 可访问（但在类外部变成 protected）
        cout << "prot = " << prot << endl;  // 可访问
    }
};

// 私有继承：全部变成 private
class PrivDerived : private Base
{
public:
    void test()
    {
        cout << "pub = " << pub << endl;    // 可访问（但在类外部变成 private）
        cout << "prot = " << prot << endl;  // 可访问
    }
};

// ==================== 主函数 ====================
int main()
{
    cout << "========== 1. 基本继承 ==========" << endl;
    Dog dog("旺财", 3, "金毛");
    dog.eat();    // 调用父类方法
    dog.sleep();  // 调用父类方法
    dog.bark();   // 调用自己方法
    dog.fetch();  // 调用自己方法

    cout << "\n========== 2. 不同继承方式 ==========" << endl;
    PubDerived pubD;
    cout << "pubD.pub = " << pubD.pub << endl;  // public 可访问
    // pubD.prot // 不可访问（protected）
    // pubD.priv //  不可访问（private）
    return 0;
}