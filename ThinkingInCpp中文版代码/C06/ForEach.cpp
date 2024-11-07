//: C06:ForEach.cpp {-mwcc}
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ʹ��STL for_each()�㷨
//{L} Counted
#include <algorithm>
#include <iostream>
#include "Counted.h"
using namespace std;

// ��������
template<class T>
class DeleteT {
public:
    void operator()(T* x) { delete x; }
};

// ģ�庯��
template<class T>
void wipe(T* x) { delete x; }

int main() {
    CountedVector B("��");
    for_each(B.begin(), B.end(), DeleteT<Counted>());
    CountedVector C("��");
    for_each(C.begin(), C.end(), wipe<Counted>);
} ///:~
