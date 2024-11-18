//: C08:CheckedCast2.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ʹ��RTTI��dynamic_cast
#include <vector>
#include "../purge.h"
#include "Security.h"

using namespace std;

int main() {
    vector<Security*> portfolio;
    portfolio.push_back(new Metal);
    portfolio.push_back(new Investment);
    portfolio.push_back(new Bond);
    portfolio.push_back(new Stock);

    for(vector<Security*>::iterator it = portfolio.begin();
        it != portfolio.end(); ++it) {
        Investment* cm = dynamic_cast<Investment*>(*it);
        if(cm)
            cm->special();
        else
            cout << "����һ��Investment" << endl;
    }

    cout << "���м�ָ��ǿ��ת�ͣ�" << endl;
    Security* sp = new Metal;
    Investment* cp = dynamic_cast<Investment*>(sp);
    if(cp)
        cout << "����һ��Investment" << endl;
    Metal* mp = dynamic_cast<Metal*>(sp);
    if(mp)
        cout << "��Ҳ��һ��Metal!" << endl;

    purge(portfolio);
} ///:~
