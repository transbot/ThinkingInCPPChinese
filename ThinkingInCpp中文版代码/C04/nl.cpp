//: C04:nl.cpp
// ���ԡ�C++���˼��, ��2��
// ���ߣ�Bruce Eckel & Chuck Allison��
// ���ߣ��ܾ�(bookzhou.com)
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
// �Զ���һ������Ԫ
#include <iostream>

using namespace std;

// nl����new line
ostream& nl(ostream& os) {
    return os << '\n';
}

int main() {
    cout << "��" << nl << "ÿ" << nl << "��" << nl
         << "��" << nl << "֮" << nl << "��" << nl
         << "��" << nl << "��" << nl << "��" << nl
         << "��" << nl << "��" << nl;
} ///:~
