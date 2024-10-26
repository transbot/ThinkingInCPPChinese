//: C05:CountedClass.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
// ���þ�̬��Ա���ж�����������
#include <iostream>
using namespace std;

class CountedClass {
    static int count;
public:
    CountedClass() { ++count; }
    CountedClass(const CountedClass&) { ++count; }    
    ~CountedClass() { --count; }
    static int getCount() { return count; }
};

int CountedClass::count = 0;

int main() {
    CountedClass a;
    cout << CountedClass::getCount() << endl;     // 1
    CountedClass b;
    cout << CountedClass::getCount() << endl;     // 2
    { // ��㶨��һ��������
        CountedClass c(b);        
        cout << CountedClass::getCount() << endl; // 3
        a = c;
        cout << CountedClass::getCount() << endl; // 3
    }
    // �뿪����������ʵ�����Ķ�����Զ�������
    cout << CountedClass::getCount() << endl;     // 2
} ///:~
