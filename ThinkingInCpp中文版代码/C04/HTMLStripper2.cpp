//: C04:HTMLStripper2.cpp {RunByHand}
// ���ԡ�C++���˼��, ��2��
// ���ߣ�Bruce Eckel & Chuck Allison
// ���ߣ��ܾ�(bookzhou.com)
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
//{L} ../C03/ReplaceAll
// �ù����������Ƴ�HTML��ǩ�ͱ��
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include "../C03/ReplaceAll.h"
#include "../require.h"
using namespace std;

string& stripHTMLTags(string& s) throw(runtime_error) {
    size_t leftPos;
    while ((leftPos = s.find('<')) != string::npos) {
        size_t rightPos = s.find('>', leftPos + 1);
        if (rightPos == string::npos) {
            ostringstream msg;
            msg << "��������HTML��ǩ��ʼ��λ�ã�"
                << leftPos;
            throw runtime_error(msg.str());
        }
        s.erase(leftPos, rightPos - leftPos + 1);
    }
    // �Ƴ���������HTML�ַ�
  replaceAll(s, "&lt;", "<");
  replaceAll(s, "&gt;", ">");
  replaceAll(s, "&amp;", "&");
  replaceAll(s, "&nbsp;", " ");
  // Etc...
  return s;
}

int main(int argc, char* argv[]) {
    requireArgs(argc, 1, "�÷�: HTMLStripper2 ��Ĳ���.html�ļ�");
    ifstream in(argv[1]);
    assure(in, argv[1]);
    // �������ļ������ַ�����Ȼ���Ƴ������ַ�
    ostringstream ss;
    ss << in.rdbuf();
    try {
        string s = ss.str();
        cout << stripHTMLTags(s) << endl;
        return EXIT_SUCCESS;
    } catch (runtime_error& x) {
        cout << x.what() << endl;
        return EXIT_FAILURE;
    }
} ///:~
