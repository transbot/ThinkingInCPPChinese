//: C10:CollectingParameterDemo.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CollectingParameter : public vector<string> {};

class Filler {
public:
    void f(CollectingParameter& cp) {
        cp.push_back("我在");
    }
    void g(CollectingParameter& cp) {
        cp.push_back("不停地");
    }
    void h(CollectingParameter& cp) {
        cp.push_back("收集信息");
    }
};

int main() {
    Filler filler;
    CollectingParameter cp;
    filler.f(cp);
    filler.g(cp);
    filler.h(cp);
    vector<string>::iterator it;
    for (it = cp.begin(); it != cp.end(); ++it) {
        cout << *it;
    }
    cout << endl;
} ///:~
