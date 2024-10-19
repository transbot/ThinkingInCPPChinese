//: C04:StringSeeking.cpp {-bor}{-dmc}
// ���ԡ�C++���˼��, ��2��
// ���ߣ�Bruce Eckel & Chuck Allison
// ���ߣ��ܾ�(bookzhou.com)
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ���ַ��������ж�ȡ��д��
#include <cassert>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string text = "We will hook no fish";
    stringstream ss(text);
    ss.seekp(0, ios::end);
    ss << " before its time.";
    assert(ss.str() == "We will hook no fish before its time.");
    // �� "hook" ��Ϊ "ship"
    ss.seekg(8, ios::beg);
    string word;
    ss >> word;
    assert(word == "hook");
    ss.seekp(8, ios::beg);
    ss << "ship";
    // ��"fish"��Ϊ"code"
    ss.seekg(16, ios::beg);
    ss >> word;
    assert(word == "fish");
    ss.seekp(16, ios::beg);
    ss << "code";
    assert(ss.str() == "We will ship no code before its time.");
    ss.str("A horse of a different color."); // ��ʾstr()�����ذ汾
    assert(ss.str() == "A horse of a different color.");
} ///:~
