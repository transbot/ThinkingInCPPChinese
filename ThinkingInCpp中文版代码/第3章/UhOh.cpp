//: C03:UhOh.cpp
// ���ԡ�C++���˼��, ��2��
// ���ߣ�Bruce Eckel & Chuck Allison��
// ���ߣ��ܾ�(bookzhou.com)
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

#include <string>
#include <cassert>
using namespace std;

int main() {
    // ���󣺲����õ���char����ʼ��
    //! string nothingDoing1('a');

    // ���󣺲�������������ʼ��
    //! string nothingDoing2(0x37);

    // �����ºϷ���
    string okay(5, 'a');
    assert(okay == string("aaaaa"));    
} ///:~
