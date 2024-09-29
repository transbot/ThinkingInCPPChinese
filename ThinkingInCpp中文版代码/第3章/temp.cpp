//: C03:Replace.cpp
// ���ԡ�C++���˼��, ��2��
// ���ߣ�Bruce Eckel & Chuck Allison��
// ���ߣ��ܾ�(bookzhou.com)
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
#include <cassert>
#include <cstddef> // Ϊ��ʹ��size_t
#include <string>
#include <iostream>
using namespace std;

void replaceChars(string& modifyMe,
    const string& findMe, const string& newChars) {

    // ��λ��0��ʼ����modifyMe�в���Ҫ�滻���ַ���findMe
    size_t i = modifyMe.find(findMe, 0);
    
    // �Ƿ��ҵ���Ҫ�滻���ַ�����
    if(i != string::npos)
        // ʹ��newChars�滻findMe
        modifyMe.replace(i, findMe.size(), newChars);
    cout << "δ�ҵ�Ŀ��";
}

int main() {
    string mirrorListening = "һ���Ķ��죬"
                             "��һȥ��ʮѽôʮ���ꡣ";
    string replacement("ʮ��"); // �����滻�ַ���
    string findMe("ʮһ");      // ����Ҫ���滻���ַ���
    
    // ��mirrorListening�в���"ʮ��"����"ʮ��"������
    replaceChars(mirrorListening, findMe, replacement);
    cout << mirrorListening;

    // ��֤�滻�ɹ�
    // assert(mirrorListening == "һ���Ķ��죬"                              "��һȥ��ʮѽôʮ���ꡣ");                     
} ///:~
