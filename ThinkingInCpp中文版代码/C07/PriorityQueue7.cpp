//: C07:PriorityQueue7.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 一个可以提供临时向量的优先队列
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <queue>
#include <vector>
using namespace std;

template<class T, class Compare>
class PQV {
    vector<T> v;
    Compare comp;

public:
    // 不需要调用make_heap()；此时它是空的：
    PQV(Compare cmp = Compare()) : comp(cmp) {}

    void push(const T& x) {
        v.push_back(x); // 将其置于末尾
        // 重新调整堆：
        push_heap(v.begin(), v.end(), comp);
    }

    void pop() {
        // 将top元素移动到最后一个位置：
        pop_heap(v.begin(), v.end(), comp);
        v.pop_back(); // 移除该元素
    }

    const T& top() {
        return v.front();
    }

    bool empty() const {
        return v.empty();
    }

    int size() const {
        return v.size();
    }

    typedef vector<T> TVec;
    TVec getVector() {
        TVec r(v.begin(), v.end()); // 它已经是一个堆
        sort_heap(r.begin(), r.end(), comp); // 转换为priority_queue顺序
        reverse(r.begin(), r.end());
        return r;
    }
};

int main() {
    PQV<int, less<int>> pqi;
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
