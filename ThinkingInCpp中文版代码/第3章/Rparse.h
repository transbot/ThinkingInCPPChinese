//: C03:Rparse.h
// ���ԡ�C++���˼��, ��2��
// ���ߣ�Bruce Eckel & Chuck Allison��
// ���ߣ��ܾ�(bookzhou.com)
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

//: C03:Rparse.h
#ifndef RPARSE_H
#define RPARSE_H
#include <cstddef>
#include <string>
#include <vector>
#include "../TestSuite/Test.h"

using std::size_t;
using std::string;
using std::vector;

class RparseTest : public TestSuite::Test {
    // ���˽�г�Ա���ڴ洢�������
    vector<string> strings;

public:
    void parseForData() {
        // ';' �ַ����Ƕ����
        string s("now.;sense;make;to;going;is;This");
        // �ַ��������һ��Ԫ�أ�
        int last = s.size();
        // ��ǰ���ʵĿ�ʼλ�ã�
        size_t current = s.rfind(';');
        // ���ַ�����ĩβ���������
        while(current != string::npos) {
            // ��ÿ������ѹ��������
            // �ڿ���֮ǰ����current�Ա��⿽���������
            ++current;
            strings.push_back(s.substr(current, last - current));
            // �ص��ո��ҵ��Ķ����ǰ�棬����last��Ϊ��һ�����ʵ�ĩβ��
            current -= 2;
            last = current + 1;
            // Ѱ����һ���������
            current = s.rfind(';', current);
        }
        // ѹ���һ�����ʡ�����ǰ��û�ж������
        strings.push_back(s.substr(0, last));
    }
    
    void testData() {
        // ����˳��������ǣ�
        test_(strings[0] == "This");
        test_(strings[1] == "is");
        test_(strings[2] == "going");
        test_(strings[3] == "to");
        test_(strings[4] == "make");
        test_(strings[5] == "sense");
        test_(strings[6] == "now.");
        string sentence;
        for(size_t i = 0; i < strings.size() - 1; i++)
            sentence += strings[i] += " ";
        // �ֶ�������һ�������Ա������Ŀո�
        sentence += strings[strings.size() - 1];
        test_(sentence == "This is going to make sense now.");
    }
    
    void run() {
        parseForData();
        testData();
    }
};

#endif // RPARSE_H ///:~
