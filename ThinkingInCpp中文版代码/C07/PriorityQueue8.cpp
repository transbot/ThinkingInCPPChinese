//: C07:PriorityQueue8.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// �޸�PriorityQueue7.cpp����һ���򻯴���
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
        TVec r(this->c.begin(), this->c.end()); // ���Ѿ���һ����
        sort_heap(r.begin(), r.end(), this->comp); // ת��Ϊpriority_queue˳��
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
