//: C03:AddStrings.cpp
// ���ԡ�C++���˼��, ��2��
// ���ߣ�Bruce Eckel & Chuck Allison��
// ���ߣ��ܾ�(bookzhou.com)
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
#include <string>
#include <cassert>
#include <iostream>
using namespace std;

int main() {  
    string s1("˭����");
    string s2("�����");
    string s3("���±����Ĺ���.");
    string s4("������͵͵��Ū���µ�ָ��");

    // �ҵ������ŵ�����λ�ã�rfind()������μ���һ��
    size_t peroidPos = s3.rfind('.');    

    // ʹ��operator+ƴ���ַ���
    s1 = s1 + s2;
    assert(s1 == "˭���Ǵ����");    

    // ��һ��ƴ���ַ����ķ���
    s1 += s3;
    assert(s1 == "˭���Ǵ�������±����Ĺ���.");   

    // ��ȷ��������Ч��ǰ���£����Ҳ���ַ�����������
    if (peroidPos < s3.size()) {    
        s1 += s4 + s3[peroidPos]; // ��������һ�����
        assert(s1 == "˭���Ǵ�������±����Ĺ���.������͵͵��Ū���µ�ָ��.");        
    } else {
        cout << "������Ч" << endl;
    }
} ///:~
