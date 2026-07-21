#include <iostream>
#include <cstring>
using namespace std;

// ==================== 浅拷贝 ====================
// 问题：两个对象共享同一块堆内存，析构时重复释放 → 程序崩溃
// 解决方案：需要自己实现深拷贝
class Shallow {
private:
    char* name;  // 堆上分配的内存

public:
    // 构造函数
    Shallow(const char* n) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        cout << "【构造】" << name << endl;
    }

    // 不写拷贝构造 → 编译器自动生成浅拷贝
    // 浅拷贝 = 只复制指针的值（地址），不复制指向的内容

    void show() const {
        cout << "name = " << name << " (地址: " << (void*)name << ")" << endl;
    }

    // 修改名字
    void change(const char* n) {
        strcpy(name, n);
    }

    // 析构函数
    ~Shallow() {
        cout << "【析构】" << name << " (地址: " << (void*)name << ")" << endl;
        delete[] name;  // 释放堆内存
    }
};


// ==================== 深拷贝 ====================
// 正确做法：每个对象拥有独立的内存副本
class Deep {
private:
    char* name;

public:
    // 构造函数
    Deep(const char* n) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        cout << "【构造】" << name << endl;
    }

    // 【深拷贝构造函数】—— 关键！
    Deep(const Deep& other) {
        // 分配新内存，复制数据
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        cout << "【深拷贝构造】复制了 " << other.name << " 的独立副本 (新地址: " << (void*)name << ")" << endl;
    }

    // 【深拷贝赋值运算符】—— 关键！
    Deep& operator=(const Deep& other) {
        if (this != &other) {  // 防止自己赋值给自己
            delete[] name;     // 释放旧内存

            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
            cout << "【深拷贝赋值】赋值为 " << other.name << " (新地址: " << (void*)name << ")" << endl;
        }
        return *this;
    }

    void show() const {
        cout << "name = " << name << " (地址: " << (void*)name << ")" << endl;
    }

    void change(const char* n) {
        strcpy(name, n);
    }

    ~Deep() {
        cout << "【析构】" << name << " (地址: " << (void*)name << ")" << endl;
        delete[] name;
    }
};


// ==================== 主程序 ====================
int main() {
    cout << "==================== 浅拷贝的陷阱 ====================" << endl;
    {
        cout << "\n--- 创建两个对象 ---" << endl;
        Shallow s1("张三");
        Shallow s2 = s1;  // 调用默认拷贝构造（浅拷贝）

        cout << "\n--- s1 和 s2 指向同一块内存 ---" << endl;
        cout << "s1: "; s1.show();
        cout << "s2: "; s2.show();

        cout << "\n--- 修改 s1 的名字 ---" << endl;
        s1.change("张老大");
        cout << "s1: "; s1.show();
        cout << "s2: "; s2.show();  // s2 也被改了！因为指向同一块内存

        cout << "\n--- 程序结束，s1 和 s2 析构时会重复释放同一块内存 → 程序崩溃 ---" << endl;
        // 实际运行到这里会报错：free(): double free detected
    }

    cout << "\n\n==================== 深拷贝的正确做法 ====================" << endl;
    {
        cout << "\n--- 创建两个对象 ---" << endl;
        Deep d1("李四");
        Deep d2 = d1;  // 调用深拷贝构造函数

        cout << "\n--- d1 和 d2 拥有独立的内存 ---" << endl;
        cout << "d1: "; d1.show();
        cout << "d2: "; d2.show();

        cout << "\n--- 修改 d1 的名字 ---" << endl;
        d1.change("李老大");
        cout << "d1: "; d1.show();
        cout << "d2: "; d2.show();  // d2 不受影响 

        cout << "\n--- 深拷贝赋值测试 ---" << endl;
        Deep d3("王五");
        cout << "d3 初始: "; d3.show();

        d3 = d1;  // 调用深拷贝赋值运算符
        cout << "d3 赋值后: "; d3.show();

        cout << "\n--- 修改 d1 的名字 ---" << endl;
        d1.change("李大帅");
        cout << "d1: "; d1.show();
        cout << "d3: "; d3.show();  // d3 不受影响 

        cout << "\n--- 程序结束，每个对象独立释放自己的内存，安全 ---" << endl;
    }

    return 0;
}