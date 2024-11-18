//: C07:Apply.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ʹ�ü򵥵ĵ���
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

template<class Cont, class PtrMemFun>
void apply(Cont& c, PtrMemFun f) {
    typename Cont::iterator 
        it = c.begin();       // ��ȡ��������ʼ������
    while(it != c.end()) {    // ���������е�����Ԫ��
        ((*it).*f)();         // ����Ϊ��ǰԪ�ص��ó�Ա������������ʽ֮һ
        ++it;                 // �ƶ�����һ��Ԫ��
    }
}


// �������һ��������Ա��һ����Ա����g
class Z {
    int i;
public:
    Z(int ii) : i(ii) {}
    void g() { ++i; }
    
    // ����<<���������������Z����
    friend ostream& operator<<(ostream& os, const Z& z) {
        return os << z.i;
    }
};

int main() {
    ostream_iterator<Z> out(cout, " ");
    vector<Z> vz;
    for(int i = 0; i < 10; i++)
        // ��vector���10��Z����ÿ�������iֵ��0��9
        vz.push_back(Z(i)); 
    
    // ʹ��copy������vector�е�����Z�������������̨
    copy(vz.begin(), vz.end(), out);
    cout << endl;

    // ����apply������Ϊvector�е�ÿ��Z������ó�Ա����g
    // g�������ǵ���i
    apply(vz, &Z::g);

    // �ٴ����������̨
    copy(vz.begin(), vz.end(), out);
} ///:~
