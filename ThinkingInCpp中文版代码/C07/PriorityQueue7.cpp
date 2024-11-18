//: C07:PriorityQueue7.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// һ�������ṩ��ʱ���������ȶ���
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
    // ����Ҫ����make_heap()����ʱ���ǿյģ�
    PQV(Compare cmp = Compare()) : comp(cmp) {}

    void push(const T& x) {
        v.push_back(x); // ��������ĩβ
        // ���µ����ѣ�
        push_heap(v.begin(), v.end(), comp);
    }

    void pop() {
        // ��topԪ���ƶ������һ��λ�ã�
        pop_heap(v.begin(), v.end(), comp);
        v.pop_back(); // �Ƴ���Ԫ��
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
        TVec r(v.begin(), v.end()); // ���Ѿ���һ����
        sort_heap(r.begin(), r.end(), comp); // ת��Ϊpriority_queue˳��
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
