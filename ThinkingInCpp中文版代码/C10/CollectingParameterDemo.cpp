//: C10:CollectingParameterDemo.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CollectingParameter : public vector<string> {};

class Filler {
public:
    void f(CollectingParameter& cp) {
        cp.push_back("����");
    }
    void g(CollectingParameter& cp) {
        cp.push_back("��ͣ��");
    }
    void h(CollectingParameter& cp) {
        cp.push_back("�ռ���Ϣ");
    }
};

int main() {
    Filler filler;
    CollectingParameter cp;
    filler.f(cp);
    filler.g(cp);
    filler.h(cp);
    vector<string>::iterator it;
    for (it = cp.begin(); it != cp.end(); ++it) {
        cout << *it;
    }
    cout << endl;
} ///:~
