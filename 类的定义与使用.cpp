#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int age;

    // 构造函数：对象创建时自动调用
    Student(string n, int a) {
        name = n;
        age = a;
    }

    void show() {
        cout << "姓名: " << name << ", 年龄: " << age << endl;
    }
};

int main() {
    Student s1("张三", 20);
    Student s2("李四", 21);

    s1.show();
    s2.show();

    return 0;
}