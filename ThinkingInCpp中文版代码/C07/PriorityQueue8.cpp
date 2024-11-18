//: C07:PriorityQueue8.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 修改PriorityQueue7.cpp，进一步简化代码
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <queue>
using namespace std;

template<class T>
class PQV : public priority_queue<T> {

public:
    typedef vector<T> TVec;
    TVec getVector() {
        TVec r(this->c.begin(), this->c.end()); // 它已经是一个堆
        sort_heap(r.begin(), r.end(), this->comp); // 转换为priority_queue顺序
        reverse(r.begin(), r.end());
        return r;
    }
};

int main() {
    PQV<int> pqi;
    srand(time(0));
    for(int i = 0; i < 100; i++)
        pqi.push(rand() % 25);

    const vector<int>& v = pqi.getVector();
    copy(v.begin(), v.end(),
         ostream_iterator<int>(cout, " "));
    cout << "\n-----------" << endl;

    while(!pqi.empty()) {
        cout << pqi.top() << ' ';
        pqi.pop();
    }
} ///:~
