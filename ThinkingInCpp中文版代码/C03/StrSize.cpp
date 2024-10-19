//: C03:StrSize.cpp
// ���ԡ�C++���˼��, ��2��
// ���ߣ�Bruce Eckel & Chuck Allison
// ���ߣ��ܾ�(bookzhou.com)
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
#include <string>
#include <iostream>
using namespace std;

int main() {
    string mirrorListening("�����ڴ���ѻ��ֻ��Ƭ�");
    cout << mirrorListening << endl;

    // �ַ�����ǰʵ�ʰ����������ݣ�size��ָ��ǰ��С
    cout << "��С = " << mirrorListening.size() << endl;

    // �����·����ڴ��������ܹ����Դ洢���٣�capacity��ָ�������
    cout << "���� = " << mirrorListening.capacity() << endl;

    // ��mirrorListening[4]֮ǰ������������֮ǰ������ָ�����ַ�����
    mirrorListening.insert(4, "�غ��ڳ�Ϧ");
    cout << mirrorListening << endl;

    // ��ʾ�ַ����ĵ�ǰ��С������
    cout << "��С = " << mirrorListening.size() << endl;
    cout << "���� = " << mirrorListening.capacity() << endl;

    // ȷ�����㹻�Ŀռ�
    mirrorListening.reserve(500);

    // ��ָ�����ַ���׷�ӵ��ַ���ĩβ
    mirrorListening.append("����غ��������û���ټ��������Ѿ��ھ��и���δ���Զ��塣");
    cout << mirrorListening << endl;

    // ��ʾ�ַ����ĵ�ǰ��С������
    cout << "��С = " << mirrorListening.size() << endl;
    cout << "���� = " << mirrorListening.capacity() << endl;
} ///:~
