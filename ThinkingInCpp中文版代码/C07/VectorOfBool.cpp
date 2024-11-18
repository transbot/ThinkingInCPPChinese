//: C07:VectorOfBool.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 演示vector<bool>特化 
#include <bitset>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    vector<bool> vb(10, true);
    vector<bool>::iterator it;
    for(it = vb.begin(); it != vb.end(); it++)
        cout << *it;
    cout << endl;

    vb.push_back(false);
    ostream_iterator<bool> out(cout, "");
    copy(vb.begin(), vb.end(), out);
    cout << endl;

    bool ab[] = { true, false, false, true, true,
                  true, true, false, false, true };

    // 存在一个类似的构造函数    
    vb.assign(ab, ab + sizeof(ab)/sizeof(bool));
    copy(vb.begin(), vb.end(), out);
    cout << endl;

    vb.flip(); // 翻转所有位
    copy(vb.begin(), vb.end(), out);
    cout << endl;

    for(size_t i = 0; i < vb.size(); i++)
        vb[i] = 0; // （相当于"false"）
    vb[4] = true;
    vb[5] = 1;
    vb[7].flip(); // 翻转一个位
    copy(vb.begin(), vb.end(), out);
    cout << endl;

    // 转换为bitset
    ostringstream os;
    copy(vb.begin(), vb.end(),
         ostream_iterator<bool>(os, ""));
    bitset<10> bs(os.str());
    cout << "Bitset: " << endl << bs << endl;
} ///:~
