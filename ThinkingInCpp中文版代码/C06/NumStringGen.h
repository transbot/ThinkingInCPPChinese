//: C06:NumStringGen.h
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// һ����������������������ɴ����������ַ���
#ifndef NUMSTRINGGEN_H
#define NUMSTRINGGEN_H
#include <cstdlib>
#include <string>

class NumStringGen {
    const int sz; // Ҫ���ɵ����ֵ�λ�������а���һ��С���㣩
public:
    NumStringGen(int ssz = 5) : sz(ssz) {} // ���캯����Ĭ���ַ�������Ϊ5
    std::string operator()() {
        std::string digits("0123456789");  // ֻ�ܴ���Щ��λ��ѡ��
        const int ndigits = digits.size(); // ��ʹ�õ���λ�����������ǳ���ֵ10
        std::string r(sz, ' '); // ��������Ϊsz���ַ�����ÿ���ַ�����ʼ��Ϊ�ո�

        // ����ַ�����������λΪ0
        // �޶���λ��1-9����������������һ��0-8֮����������
        // �ټ���1���Ӷ�ȷ����Χ��1-9֮�䡣
        r[0] = digits[std::rand() % (ndigits - 1)] + 1; 

        // ���������λ
        for(int i = 1; i < sz; ++i) 
            // ���λ�����ڵ���3�ҵ�ǰ�������м�λ�ã������С����
            if(sz >= 3 && i == sz/2) r[i] = '.';
            // �������������λ
            else r[i] = digits[std::rand() % ndigits];
        return r;
    }
};
#endif // NUMSTRINGGEN_H ///:~
