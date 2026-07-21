#include <iostream>
using namespace std;

class Weapon {
private:
    string name;
    int damage;

public:
    // 1. 默认构造函数（无参）
    Weapon() {
        name = "未知武器";
        damage = 10;
        cout << "【默认构造函数】" << name << " 被创建" << endl;
    }

    // 2. 带参构造函数（重载）
    Weapon(string n, int d) {
        name = n;
        damage = d;
        cout << "【带参构造函数】" << name << " 被创建，攻击力=" << damage << endl;
    }

    // 3. 析构函数：对象销毁时自动调用
    ~Weapon() {
        cout << "【析构函数】" << name << " 被销毁" << endl;
    }

    void show() {
        cout << "武器: " << name << ", 攻击力: " << damage << endl;
    }
};

int main() {
    cout << "=== 1. 创建栈对象 ===" << endl;
    Weapon w1;                    // 调用默认构造函数
    Weapon w2("长剑", 25);        // 调用带参构造函数

    w1.show();
    w2.show();

    cout << "\n=== 2. 创建堆对象（new） ===" << endl;
    Weapon* w3 = new Weapon("魔法杖", 40);   // 调用带参构造函数
    w3->show();

    // 用 new 创建的对象不会自动销毁，需要手动 delete
    delete w3;                     // 手动调用析构函数

    cout << "\n=== 3. 多个对象的构造和析构顺序 ===" << endl;
    Weapon w4("短弓", 18);
    Weapon w5("匕首", 12);

    cout << "\n=== main函数结束，栈对象自动析构 ===" << endl;
    // 注意：w5 先析构，w4 后析构（后创建的先析构）
    return 0;
}