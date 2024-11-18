//: C08:TypeInfo.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ʾtypeid������
#include <iostream>
#include <typeinfo>
using namespace std;

struct PolyBase { virtual ~PolyBase() {} }; // ��̬����
struct PolyDer : PolyBase { PolyDer() {} }; // ��̬������
struct NonPolyBase {}; // �Ƕ�̬����
struct NonPolyDer : NonPolyBase { NonPolyDer(int) {} }; // �Ƕ�̬������

int main() {
    // ���Զ�̬����
    const PolyDer pd;
    const PolyBase* ppb = &pd;
    // ��ȡָ���������Ϣ
    cout << typeid(ppb).name() << endl;
    // ��ȡָ����ָ�����Ķ�̬������Ϣ
    cout << typeid(*ppb).name() << endl;
    // �Ƚ�ָ����ָ�����Ķ�̬���ͺ�pd������
    cout << boolalpha << (typeid(*ppb) == typeid(pd)) << endl;
    // �Ƚ�PolyDer��const PolyDer������
    cout << (typeid(PolyDer) == typeid(const PolyDer)) << endl;

    // ���ԷǶ�̬����
    const NonPolyDer npd(1);
    const NonPolyBase* nppb = &npd;
    // ��ȡָ���������Ϣ
    cout << typeid(nppb).name() << endl;
    // ��ȡָ����ָ�����ľ�̬������Ϣ
    cout << typeid(*nppb).name() << endl;
    // �Ƚ�ָ����ָ�����ľ�̬���ͺ�npd������
    cout << (typeid(*nppb) == typeid(npd)) << endl;

    // ������������
    int i;
    // ��ȡ��������int��������Ϣ
    cout << typeid(i).name() << endl;
} ///:~
