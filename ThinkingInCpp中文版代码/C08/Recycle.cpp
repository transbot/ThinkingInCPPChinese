//: C08:Recycle.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
//{L} Trash
// 垃圾回收站
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <typeinfo>
#include <vector>
#include "Trash.h"
#include "../purge.h"
using namespace std;

// 计算垃圾箱中垃圾的总价值
template<class Container>
void sumValue(Container& bin, ostream& os) {
    typename Container::iterator tally = bin.begin();
    float val = 0;
    while(tally != bin.end()) {
        val += (*tally)->weight() * (*tally)->value();
        os << typeid(**tally).name() << "的重量 = " 
           << (*tally)->weight() << endl;
        ++tally;
    }
    os << "总价值 = " << val << endl;
}

int main() {
    srand(time(0));     // 初始化随机数生成器

    // 随机填充垃圾箱
    vector<Trash*> bin; 
    for(int i = 0; i < 30; i++)
        switch(rand() % 3) {
            case 0 : bin.push_back(new Aluminum((rand() % 1000)/10.0));
                     break;
            case 1 : bin.push_back(new Paper((rand() % 1000)/10.0));
                     break;
            case 2 : bin.push_back(new Glass((rand() % 1000)/10.0));
                     break;
        }

    // 注意，垃圾箱容纳了对象的确切类型，而不是基类型：
    vector<Glass*> glassBin;
    vector<Paper*> paperBin;
    vector<Aluminum*> alumBin;
    vector<Trash*>::iterator sorter = bin.begin();

    // 对垃圾进行分类
    while(sorter != bin.end()) {
        Aluminum* ap = dynamic_cast<Aluminum*>(*sorter);
        Paper* pp = dynamic_cast<Paper*>(*sorter);
        Glass* gp = dynamic_cast<Glass*>(*sorter);
        if(ap) alumBin.push_back(ap);
        else if(pp) paperBin.push_back(pp);
        else if(gp) glassBin.push_back(gp);
        ++sorter;
    }

    // 打印分类后的每种垃圾的信息
    sumValue(alumBin, cout);
    sumValue(paperBin, cout);
    sumValue(glassBin, cout);

    // 打印未分类的所有垃圾的信息
    sumValue(bin, cout);

    // 清理垃圾箱
    purge(bin);
} ///:~
