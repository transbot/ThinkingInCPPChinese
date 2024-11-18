//: C07:BasicSequenceOperations_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ʾ���л�������������֧�ֵĲ���
// �������ԭ�����������޸ģ�ʹ֮�����ִ�C++��׼
// ��Ҫ�Ķ�������
/* 
1. ʹ��const��auto��
   ��print�����У�ʹ��const���������������Է�ֹ����Ҫ���޸ġ�
   ʹ��auto�ؼ������򻯵�������������
2. ���ڷ�Χ��for��
   ʹ��for(const auto& item : c)�����������������ִ� C++ �и��Ӽ��Ͱ�ȫ��
3. ���ͱ�����
   ʹ��using�ؼ��ֶ������ͱ�����ʹ�����������
*/

#include <deque>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

// ��ӡ�������ݵ�ģ�庯��
template<typename Container>
void print(const Container& c, const char* title = "") {
    cout << title << ':' << endl;
    if(c.empty()) {
        cout << "(empty)" << endl;
        return;
    }
    for(const auto& item : c) {
        cout << item << " ";
    }
    cout << endl;
    cout << "size() " << c.size() << " max_size() " << c.max_size() 
         << " front() " << c.front() << " back() " << c.back() << endl;
}

// ��ʾ����������ģ�庯��
template<typename ContainerOfInt>
void basicOps(const char* s) {
    cout << "------- " << s << " -------" << endl;
    using Ci = ContainerOfInt;
    Ci c;
    print(c, "ִ��Ĭ�Ϲ��캯�����c");
    Ci c2(10, 1); // 10��Ԫ�أ�ֵȫΪ1
    print(c2, "ִ�й��캯��(10,1)���c2");

    int ia[] = { 1, 3, 5, 7, 9 };
    const size_t IASZ = sizeof(ia) / sizeof(*ia);
    // ʹ��begin��end����������ʼ��
    Ci c3(ia, ia + IASZ);
    print(c3, "ִ�й��캯��(iter,iter)���c3");
    Ci c4(c2); // �������캯��
    print(c4, "ִ�п������캯��(c2)���c4");
    c = c2;    // ��ֵ������
    print(c, "ִ��operator=c2���c");
    c.assign(10, 2); // 10��Ԫ�أ�ֵȫΪ2
    print(c, "ִ��assign(10, 2)���c");
    // ʹ��begin��end����������ֵ
    c.assign(ia, ia + IASZ);
    print(c, "ִ��assign(iter, iter)���c");
    cout << "ʹ�������������c��" << endl;
    for(auto rit = c.rbegin(); rit != c.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;
    c.resize(4);
    print(c, "ִ��resize(4)���c");
    c.push_back(47);
    print(c, "ִ��push_back(47)���c");
    c.pop_back();
    print(c, "ִ��pop_back()���c");
    auto it = c.begin();
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
    auto it2 = it = c.begin();
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