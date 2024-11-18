//: C07:BasicSequenceOperations.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ʾ���л�������������֧�ֵĲ���
#include <deque>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

template<typename Container>
void print(Container& c, char* title = "") {
    cout << title << ':' << endl;
    if(c.empty()) {
        cout << "(empty)" << endl;
        return;
    }
    typename Container::iterator it;
    for(it = c.begin(); it != c.end(); it++)
        cout << *it << " ";
    cout << endl;
    cout << "size() " << c.size() << " max_size() " 
         << c.max_size() << " front() " << c.front()
         << " back() " << c.back() << endl;
}

template<typename ContainerOfInt>
void basicOps(char* s) {
    cout << "------- " << s << " -------" << endl;
    typedef ContainerOfInt Ci;
    Ci c;
    print(c, "ִ��Ĭ�Ϲ��캯�����c");
    Ci c2(10, 1); // 10��Ԫ�أ�ֵȫΪ1
    print(c2, "ִ�й��캯��(10,1)���c2");
    
    int ia[] = { 1, 3, 5, 7, 9 };
    const int IASZ = sizeof(ia)/sizeof(*ia);
    // ʹ��begin��end����������ʼ��
    Ci c3(ia, ia + IASZ);
    print(c3, "ִ�й��캯��(iter,iter)���c3");
    Ci c4(c2); // �������캯��
    print(c4, "ִ�п������캯��(c2)���c4");
    c = c2;    // ��ֵ������
    print(c, "ִ��operator=c2���c");
    c.assign(10, 2); // 10��Ԫ�أ�ֵȫΪ2
    print(c, "ִ��assign(10, 2)���c");
    // ʹ�ÿ�ʼ�ͽ�����������ֵ
    c.assign(ia, ia + IASZ);
    print(c, "ִ��assign(iter, iter)���c");
    cout << "ʹ�������������c��" << endl;
    typename Ci::reverse_iterator rit = c.rbegin();
    while(rit != c.rend())
        cout << *rit++ << " ";
    cout << endl;
    c.resize(4);
    print(c, "ִ��resize(4)���c");
    c.push_back(47);
    print(c, "ִ��push_back(47)���c");
    c.pop_back();
    print(c, "ִ��pop_back()���c");
    typename Ci::iterator it = c.begin();
    ++it; ++it;
    c.insert(it, 74);
    print(c, "ִ��insert(it, 74)���c");
    it = c.begin();
    ++it;
    c.insert(it, 3, 96);
    print(c, "ִ��insert(it, 3, 96)���c");
    it = c.begin();
    ++it;
    c.insert(it, c3.begin(), c3.end());
    print(c, "ִ��insert(it, c3.begin(), c3.end())���c");
    it = c.begin();
    ++it;
    c.erase(it);
    print(c, "ִ��erase(it)���c");
    typename Ci::iterator it2 = it = c.begin();
    ++it;
    ++it2; ++it2; ++it2; ++it2; ++it2;
    c.erase(it, it2);
    print(c, "ִ��erase(it, it2)���c");
    c.swap(c2);
    print(c, "ִ��swap(c2)���c");
    c.clear();
    print(c, "ִ��clear()���c");
}

int main() {
    basicOps<vector<int>>("vector");
    basicOps<deque<int>>("deque");
    basicOps<list<int>>("list");
} ///:~
