//: C03:ReplaceAndGrow.cpp
// ���ԡ�C++���˼��, ��2��
// ���ߣ�Bruce Eckel & Chuck Allison
// ���ߣ��ܾ�(bookzhou.com)
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
#include <cassert>
#include <string>
using namespace std;

int main() {
    string mirrorListening("�����Ķ��ã�");
    string replacement("�õ�������Զ����µ���");

    // ��һ��ʵ���൱��˵�����Գ��������ַ���ĩβ���ַ������滻����
    mirrorListening.replace(mirrorListening.size() ,
                    replacement.size(), replacement);    
    assert(mirrorListening == "�����Ķ��ã�"
                      "�õ�������Զ����µ���");
} ///:~