//: C05:CountedClass2.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
// ��ʾ���������һ�δ�����
#include <iostream>
using namespace std;

class Counted {
    static int count;
public:
    Counted() { ++count; }
    Counted(const Counted&) { ++count; }
    ~Counted() { --count; }
    static int getCount() { return count; }
};

int Counted::count = 0;

// �����඼��Counted�̳�
class CountedClass : public Counted {};
class CountedClass2 : public Counted {};

int main() {
    CountedClass a;
    cout << CountedClass::getCount() << endl; // 1
    CountedClass b;
    cout << CountedClass::getCount() << endl; // 2 
    CountedClass2 c;
    cout << CountedClass2::getCount() << endl; // 3������Ǵ�ģ�
} ///:~
