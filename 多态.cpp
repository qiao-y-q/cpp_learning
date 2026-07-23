#include <iostream>
#include <string>
using namespace std;

class Animal_NoVirtual {
public:
    void speak() {
        cout << "动物在叫（不知道是什么动物）" << endl;
    }
};

class Dog_NoVirtual : public Animal_NoVirtual {
public:
    void speak() {
        cout << "汪汪汪！" << endl;
    }
};

class Animal {
public:
    // 虚函数：告诉编译器，这个函数可能会被子类重写
    virtual void speak() {
        cout << "动物在叫..." << endl;
    }

    // 虚析构函数（重要！防止内存泄漏）
    virtual ~Animal() {
        cout << "Animal析构" << endl;
    }
};

class Dog : public Animal {
public:
    void speak() override {  // override 是C++11关键字，表示重写父类虚函数
        cout << "汪汪汪！" << endl;
    }

    ~Dog() {
        cout << "Dog析构" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() override {
        cout << "喵喵喵～" << endl;
    }

    ~Cat() {
        cout << "Cat析构" << endl;
    }
};

class Duck : public Animal {
public:
    void speak() override {
        cout << "嘎嘎嘎！" << endl;
    }
};
// 函数参数使用父类指针/引用，就能处理所有子类对象
void makeSound(Animal* animal) {
    animal->speak();  // 调用哪个版本？运行时决定！
}

void makeSoundRef(Animal& animal) {
    animal.speak();   // 引用也一样
}
// 含有纯虚函数的类叫抽象类，不能实例化
// 相当于"接口"，强制子类必须实现这个函数
class Shape {
public:
    virtual double getArea() = 0;  // 纯虚函数，没有实现
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    double getArea() override {
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double getArea() override {
        return width * height;
    }
};
// 虚函数表 (vtable) 演示
class Base {
public:
    virtual void func1() { cout << "Base::func1" << endl; }
    virtual void func2() { cout << "Base::func2" << endl; }
    void func3() { cout << "Base::func3（非虚函数）" << endl; }
};

class Derived : public Base {
public:
    void func1() override { cout << "Derived::func1（重写）" << endl; }
    // func2 没有重写，继承父类的
    void func3() { cout << "Derived::func3（同名隐藏）" << endl; }
};

int main()
{
    Dog_NoVirtual dog1;
    Animal_NoVirtual* p1 = &dog1;
    p1->speak();  // 输出：动物在叫...（不是汪汪！因为没有virtual）
    cout << endl;

    Animal* animals[3];
    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Duck();

    for (int i = 0; i < 3; i++) {
        animals[i]->speak();  // 同一个指针，调用不同行为！
    }
    cout << endl;

    Dog dog2;
    Cat cat2;
    makeSound(&dog2);   // 传指针
    makeSoundRef(cat2); // 传引用
    cout << endl;

    // Shape s;  //  错误！抽象类不能实例化
    Circle circle(5.0);
    Rectangle rect(4.0, 6.0);
    cout << "圆的面积：" << circle.getArea() << endl;
    cout << "矩形的面积：" << rect.getArea() << endl;
    cout << endl;

    Base* b = new Derived();
    b->func1();  // 调用 Derived::func1（重写）
    b->func2();  // 调用 Base::func2（未重写）
    b->func3();  // 调用 Base::func3（非虚函数，不参与多态）
    cout << endl;

    for (int i = 0; i < 3; i++) {
        delete animals[i];  // 会先调用子类析构，再调用父类析构
    }
    delete b;

    return 0;
}

