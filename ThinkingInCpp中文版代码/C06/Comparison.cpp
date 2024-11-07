//: C06:Comparison.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// STL��Χ�Ƚ��㷨
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include "PrintSequence.h"
using namespace std;

int main() { 
    // string�ṩ��һ�ּ��ķ�ʽ�������ַ���Χ��
    // ��ͨ��Ӧ������ʹ��ԭ����string������
    string s1("This is a test"); 
    string s2("This is a Test"); 
    cout << "s1: " << s1 << endl << "s2: " << s2 << endl; 
    cout << "�Ƚ�s1 & s1: " 
         << equal(s1.begin(), s1.end(), s1.begin()) << endl; 
    cout << "�Ƚ�s1 & s2: " 
         << equal(s1.begin(), s1.end(), s2.begin()) << endl; 

    // ��һ���ֵ������
    // �Ƚ�������Χ���ֵ��򣬷���true��ʾs1�ֵ���С��s1����Ȼ���ᣩ
    cout << "�ֵ���Ƚ�s1 & s1: " 
         << lexicographical_compare(s1.begin(), s1.end(), s1.begin(), s1.end()) << endl; 

    // �ڶ����ֵ������
    cout << "�ֵ���Ƚ�s1 & s2: " 
         << lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end()) << endl; 

    // �������ֵ������
    cout << "�ֵ���Ƚ�s2 & s1: " 
         << lexicographical_compare(s2.begin(), s2.end(), s1.begin(), s1.end()) << endl; 

    // ���ĸ��ֵ������
    cout << "�ֵ���Ƚ������̰�� "
         "s1 & ��ȫ���ȵ�s2: " << endl;          
    string s3(s1); // ��s3��ʼ��Ϊs1�Ŀ���
    while(s3.length() != 0) {  // ѭ��ֱ��s3�ĳ���Ϊ0
        bool result = lexicographical_compare( 
            s3.begin(), s3.end(), s2.begin(), s2.end()); 
        
        // �����ǰ��s3��s2�Լ��ȽϽ��
        cout << s3 << endl << s2 << ", ��� = " 
             << result << endl;         
        
        // ���s3���ֵ���С�ڡ�s2��������ѭ��
        if(result == true) break; 

        // ����ɾ��s3�����һ���ַ�������
        s3 = s3.substr(0, s3.length() - 1); 
    } 
    
    // �ҵ�������Χ��ʼ��ƥ���λ�� 
    pair<string::iterator, string::iterator> p = 
        mismatch(s1.begin(), s1.end(), s2.begin()); 
    // Ȼ���ÿ����Χ��ƥ��ĵ�������ʼ��һֱ��ӡ����Χ��ĩβ
    print(p.first, s1.end(), "p.first", ""); 
    print(p.second, s2.end(), "p.second",""); 
} ///:~
