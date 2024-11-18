//: C08:Recycle.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
//{L} Trash
// ��������վ
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <typeinfo>
#include <vector>
#include "Trash.h"
#include "../purge.h"
using namespace std;

// �������������������ܼ�ֵ
template<class Container>
void sumValue(Container& bin, ostream& os) {
    typename Container::iterator tally = bin.begin();
    float val = 0;
    while(tally != bin.end()) {
        val += (*tally)->weight() * (*tally)->value();
        os << typeid(**tally).name() << "������ = " 
           << (*tally)->weight() << endl;
        ++tally;
    }
    os << "�ܼ�ֵ = " << val << endl;
}

int main() {
    srand(time(0));     // ��ʼ�������������

    // ������������
    vector<Trash*> bin; 
    for(int i = 0; i < 30; i++)
        switch(rand() % 3) {
            case 0 : bin.push_back(new Aluminum((rand() % 1000)/10.0));
                     break;
            case 1 : bin.push_back(new Paper((rand() % 1000)/10.0));
                     break;
            case 2 : bin.push_back(new Glass((rand() % 1000)/10.0));
                     break;
        }

    // ע�⣬�����������˶����ȷ�����ͣ������ǻ����ͣ�
    vector<Glass*> glassBin;
    vector<Paper*> paperBin;
    vector<Aluminum*> alumBin;
    vector<Trash*>::iterator sorter = bin.begin();

    // ���������з���
    while(sorter != bin.end()) {
        Aluminum* ap = dynamic_cast<Aluminum*>(*sorter);
        Paper* pp = dynamic_cast<Paper*>(*sorter);
        Glass* gp = dynamic_cast<Glass*>(*sorter);
        if(ap) alumBin.push_back(ap);
        else if(pp) paperBin.push_back(pp);
        else if(gp) glassBin.push_back(gp);
        ++sorter;
    }

    // ��ӡ������ÿ����������Ϣ
    sumValue(alumBin, cout);
    sumValue(paperBin, cout);
    sumValue(glassBin, cout);

    // ��ӡδ�����������������Ϣ
    sumValue(bin, cout);

    // ����������
    purge(bin);
} ///:~
