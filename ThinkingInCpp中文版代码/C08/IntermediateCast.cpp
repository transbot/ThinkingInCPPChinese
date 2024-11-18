//: C08:IntermediateCast.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
#include <cassert>
#include <typeinfo>
using namespace std;

class B1 { public: virtual ~B1() {} };
class B2 { public: virtual ~B2() {} };
class MI : public B1, public B2 {}; // MI�̳���B1��B2������Ƕ��ؼ̳е�һ������
class Mi2 : public MI {}; // Mi2�̳���MI���������Ӽ̳���B1��B2 

int main() {
    // Mi2��������ת��ΪB2*������Mi2��B2�������࣬�������ת���ǰ�ȫ��
    B2* b2 = new Mi2; 

    // b2����ת�ͻ�Mi2*������b2ʵ����ָ��һ��Mi2�����������ת���ǰ�ȫ��
    Mi2* mi2 = dynamic_cast<Mi2*>(b2); 

    // ͬ���أ�Mi2��MI�������࣬�������ת��Ҳ��ɹ�
    MI* mi = dynamic_cast<MI*>(b2);

    // ��ʾ��̳���ת��
    B1* b1 = dynamic_cast<B1*>(b2);

    assert(typeid(b2) != typeid(Mi2*));
    assert(typeid(b2) == typeid(B2*));
    delete b2;
} ///:~
