//: C07:PriorityQueue6.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <queue>
using namespace std;

template<class T, class Compare>
class PQV : public vector<T> {
  Compare comp;
  bool sorted;
  void assureHeap() {
    if(sorted) {
      // Turn it back into a heap:
      make_heap(this->begin(),this->end(), comp);
      sorted = false;
    }
  }
public:
  PQV(Compare cmp = Compare()) : comp(cmp) {
    make_heap(this->begin(),this->end(), comp);
    sorted = false;
  }
  const T& top() {
    assureHeap();
    return this->front();
  }
  void push(const T& x) {
    assureHeap();
    this->push_back(x); // Put it at the end
    // Re-adjust the heap:
    push_heap(this->begin(),this->end(), comp);
  }
  void pop() {
    assureHeap();
    // Move the top element to the last position:
    pop_heap(this->begin(),this->end(), comp);
    this->pop_back();// Remove that element
  }
  void sort() {
    if(!sorted) {
      sort_heap(this->begin(),this->end(), comp);
      reverse(this->begin(),this->end());
      sorted = true;
    }
  }
};

int main() {
  PQV< int, less<int> > pqi;
  srand(time(0));
  for(int i = 0; i < 100; i++) {
    pqi.push(rand() % 25);
    copy(pqi.begin(), pqi.end(),
      ostream_iterator<int>(cout, " "));
    cout << "\n-----" << endl;
  }
  pqi.sort();
  copy(pqi.begin(), pqi.end(),
    ostream_iterator<int>(cout, " "));
  cout << "\n-----" << endl;
  while(!pqi.empty()) {
    cout << pqi.top() << ' ';
    pqi.pop();
  }
} ///:~
