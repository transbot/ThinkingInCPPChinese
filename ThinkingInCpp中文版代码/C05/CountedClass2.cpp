//: C05:CountedClass2.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
// 演示对象计数的一次错误尝试
#include <iostream>
using namespace std;

class Counted {
    static int count;
public:
    Counted() { ++count; }
    Counted(const Counted&) { ++count; }
    ~Counted() { --count; }
    static int getCount() { return count; }
};

int Counted::count = 0;

// 两个类都从Counted继承
class CountedClass : public Counted {};
class CountedClass2 : public Counted {};

int main() {
    CountedClass a;
    cout << CountedClass::getCount() << endl; // 1
    CountedClass b;
    cout << CountedClass::getCount() << endl; // 2 
    CountedClass2 c;
    cout << CountedClass2::getCount() << endl; // 3（这个是错的）
} ///:~
