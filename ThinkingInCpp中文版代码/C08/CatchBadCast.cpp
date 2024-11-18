//: C08:CatchBadCast.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
#include <typeinfo>
#include "Security.h"
using namespace std;

int main() {
    Metal m;
    // ��Metal����m�󶨵�Security���͵�����s��
    // ����Metal�̳���Investment����Investment�̳���Security��������ǺϷ��ġ�
    Security& s = m;

    try {
        // ���Խ�Security����sת��ΪInvestment����
        // ����sʵ�������õ���Metal���󣬶�Metal��Investment�����࣬
        // ������ת�ͻ�ɹ���
        Investment& c = dynamic_cast<Investment&>(s);
        // ����ɹ�����ִ��������䣺
        cout << "s��һ��Investment" << endl;
    } catch(bad_cast&) {
        cout << "s����һ��Investment" << endl;
    }

    try {
        // ���Խ�Security����sת��ΪBond����
        // ����sʵ�������õ���Metal���󣬶�Metal������Bond�����࣬
        // ������ת�ͻ�ʧ�ܡ�
        Bond& b = dynamic_cast<Bond&>(s);
        cout << "s��һ��Bond" << endl;
    } catch(bad_cast&) {
        cout << "s����һ��Bond" << endl;
    }
} ///:~