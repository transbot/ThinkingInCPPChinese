//: C05:TempTemp4.cpp {-bor}{-msc}
// ���ԡ�C++���˼��, ��2��
// ���ߣ�Bruce Eckel & Chuck Allison
// ���ߣ��ܾ�(bookzhou.com)
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ����׼������Ϊģ��ʵ�δ���
#include <iostream>
#include <list>
#include <memory> // allocator<T>�����ͷ�ļ�������
#include <vector>
using namespace std;

// ע��>��>֮���C++11���ò���ո�
template<class T, template<class U, class = allocator<U>> class Seq>
class Container {
    Seq<T> seq; // ��ʽӦ��Ĭ�ϵ�allocator<T>������
public:
    void push_back(const T& t) { seq.push_back(t); }
    typename Seq<T>::iterator begin() { return seq.begin(); }
    typename Seq<T>::iterator end() { return seq.end(); }
};

int main() {
    // ʹ��vector
    Container<int, vector> vContainer;
    vContainer.push_back(1);
    vContainer.push_back(2);
    for(vector<int>::iterator p = vContainer.begin();
        p != vContainer.end(); ++p) {
        cout << *p << endl;
    }
    // ʹ��list
    Container<int, list> lContainer;
    lContainer.push_back(3);
    lContainer.push_back(4);
    for(list<int>::iterator p2 = lContainer.begin();
        p2 != lContainer.end(); ++p2) {
        cout << *p2 << endl;
    }
} ///:~
