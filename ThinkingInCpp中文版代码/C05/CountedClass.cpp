//: C05:CountedClass.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
// 利用静态成员进行对象数量计数
#include <iostream>
using namespace std;

class CountedClass {
    static int count;
public:
    CountedClass() { ++count; }
    CountedClass(const CountedClass&) { ++count; }    
    ~CountedClass() { --count; }
    static int getCount() { return count; }
};

int CountedClass::count = 0;

int main() {
    CountedClass a;
    cout << CountedClass::getCount() << endl;     // 1
    CountedClass b;
    cout << CountedClass::getCount() << endl;     // 2
    { // 随便定义一个作用域：
        CountedClass c(b);        
        cout << CountedClass::getCount() << endl; // 3
        a = c;
        cout << CountedClass::getCount() << endl; // 3
    }
    // 离开作用域，其中实例化的对象就自动销毁了
    cout << CountedClass::getCount() << endl;     // 2
} ///:~
