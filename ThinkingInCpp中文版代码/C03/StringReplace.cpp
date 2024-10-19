//: C03:StringReplace.cpp
// ���ԡ�C++���˼��, ��2��
// ���ߣ�Bruce Eckel & Chuck Allison
// ���ߣ��ܾ�(bookzhou.com)
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ���ַ�����ʵ�ּ򵥵Ĳ��Һ��滻����
#include <cassert>
#include <string>
using namespace std;

int main() {
    string s("A piece of text");
    string tag("$tag$");    
    s.insert(8, tag + ' ');    
    assert(s == "A piece $tag$ of text");    
    int start = s.find(tag);    
    assert(start == 8);    
    assert(tag.size() == 5);    
    s.replace(start, tag.size(), "hello there");  // ����ַ��ͱ�ɾ�����ַ��������ϲ�ͬ  
    assert(s == "A piece hello there of text");
} ///:~
