//: C09:Offset.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ʾ���ؼ̳�ʱ�Ӷ���Ĳ���
#include <iostream>
using namespace std;

// ���������������һ��int��Ա���ٶ�int��С4��
// ��ôA��B�Ĵ�С��Ϊ4����C�Ĵ�СΪ12��
class A { int x; };
class B { int y; };
class C : public A, public B { int z; };

int main() {
    // ���������Ĵ�С
    cout << "sizeof(A) == " << sizeof(A) << endl;
    cout << "sizeof(B) == " << sizeof(B) << endl;
    cout << "sizeof(C) == " << sizeof(C) << endl;

    C c;
    cout << "&c == " << &c << endl; // �������c�ĵ�ַ
    A* ap = &c; // ������c�ĵ�ַת��ΪA���͵�ָ��
    B* bp = &c; // ������c�ĵ�ַת��ΪB���͵�ָ��

    // ����ղ�����ָ��ĵ�ַ
    cout << "ap == " << static_cast<void*>(ap) << endl; 
    cout << "bp == " << static_cast<void*>(bp) << endl;

    C* cp = static_cast<C*>(bp); // ��B���͵�ָ��bpת����C���͵�ָ��cp
    cout << "cp == " << static_cast<void*>(cp) << endl; // ���ָ��cp�ĵ�ַ
    // �ж�B����ָ��bp�Ƿ����C����ָ��cp
    cout << "bp == cp? " << boolalpha << (bp == cp) << endl;
    cp = 0;  // �ִ�C++Ӧ��0��Ϊnulptr
    bp = cp; // ��C����ָ��cpת��ΪB����ָ��bp
    cout << bp << endl; // ���ָ��bp�ĵ�ַ
} /* ��������MSVC��������:
sizeof(A) == 4
sizeof(B) == 4
sizeof(C) == 12
&c == 00AFF800
ap == 00AFF800
bp == 00AFF804
cp == 00AFF800
bp == cp? true
00000000
*/ ///:~
