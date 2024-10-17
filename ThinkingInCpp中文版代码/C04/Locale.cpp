//: C04:Locale.cpp {-bor} {-g++} {-edg} {RunByHand}
// ���ԡ�C++���˼��, ��2��
// ���ߣ�Bruce Eckel & Chuck Allison��
// ���ߣ��ܾ�(bookzhou.com)
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ʾ���ػ���locale�����õ�Ч��
#include <iostream>
#include <locale>
using namespace std;

int main() {
    locale def;

    // ������ǰlocaleʲô
    cout << def.name() << endl;
    locale current = cout.getloc();
    cout << current.name() << endl;
    float val = 12.34;
    cout << val << endl;

    // ��locale����Ϊ����/����
    cout.imbue(locale("fr-FR")); 
    current = cout.getloc();
    cout << current.name() << endl;
    cout << val << endl;

    cout << "����������ֵ123,45: " ;
    cin.imbue(cout.getloc());
    cin >> val;
    cout << val << endl;
    cout.imbue(def);
    cout << val << endl;
} ///:~
