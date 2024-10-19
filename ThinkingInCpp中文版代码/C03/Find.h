//: C03:Find.h
// ���ԡ�C++���˼��, ��2��
// ���ߣ�Bruce Eckel & Chuck Allison
// ���ߣ��ܾ�(bookzhou.com)
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
#ifndef FIND_H
#define FIND_H
#include <cctype>
#include <cstddef>
#include <string>
#include "../TestSuite/Test.h"
using std::size_t;
using std::string;
using std::tolower;
using std::toupper;

// ����s�Ĵ�д����
inline string upperCase(const string& s) {
    string upper(s);
    for(size_t i = 0; i < s.length(); ++i)
        upper[i] = toupper(upper[i]);
    return upper;
}

// ����s��Сд����
inline string lowerCase(const string& s) {
    string lower(s);
    for(size_t i = 0; i < s.length(); ++i)
        lower[i] = tolower(lower[i]);
    return lower;
}

class FindTest : public TestSuite::Test {
    string chooseOne;
public:
    FindTest() : chooseOne("Eenie, Meenie, Miney, Mo") {}
    
    void testUpper() {
        string upper = upperCase(chooseOne);
        const string LOWER = "abcdefghijklmnopqrstuvwxyz";
        test_(upper.find_first_of(LOWER) == string::npos);
    }
    
    void testLower() {
        string lower = lowerCase(chooseOne);
        const string UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        test_(lower.find_first_of(UPPER) == string::npos);
    }
    
    void testSearch() {
        // ���ִ�Сд�Ĳ���
        size_t i = chooseOne.find("een");
        test_(i == 8);
        
        // ����Сд
        string test = lowerCase(chooseOne);
        i = test.find("een");
        test_(i == 0);
        i = test.find("een", ++i);
        test_(i == 8);
        i = test.find("een", ++i);
        test_(i == string::npos);
        
        // ���Ҵ�д
        test = upperCase(chooseOne);
        i = test.find("EEN");
        test_(i == 0);
        i = test.find("EEN", ++i);
        test_(i == 8);
        i = test.find("EEN", ++i);
        test_(i == string::npos);
    }
    
    void run() {
        testUpper();
        testLower();
        testSearch();
    }
};

#endif // FIND_H ///:~
