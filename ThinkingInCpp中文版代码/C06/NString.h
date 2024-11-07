//: C06:NString.h
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// һ�֡�����ַ����������ټ�¼���������ʵĳ��ִ���
#ifndef NSTRING_H
#define NSTRING_H
#include <algorithm>
#include <iostream>
#include <string>
#include <utility> // Ϊ��ʹ��std::pair
#include <vector>

// ����һ�����ͱ��������ڴ洢�ַ����ͳ��ִ�����pair
typedef std::pair<std::string, int> psi;

// �����ڵ�һ��Ԫ�أ��ַ��������бȽ�
bool operator==(const psi& l, const psi& r) { 
    return l.first == r.first; 
}

class NString {
    std::string s;      // �洢���ַ���
    int thisOccurrence; // ���ٳ��ִ���

    // ʹ��std::vector�洢�����ַ���������ִ���
    typedef std::vector<psi> vp;

    // ��vector�ĵ�����
    typedef vp::iterator vpit;

    // ��̬��Ա���������ڼ�¼�����ַ���������ִ���
    static vp words;

    // ���ַ�����ӵ���̬��¼��
    void addString(const std::string& x) {
        psi p(x, 0);
        vpit it = std::find(words.begin(), words.end(), p);
        if (it != words.end()) {
            // ����ַ����Ѵ����ڼ�¼�У��͵������ִ���
            thisOccurrence = ++it->second;
        } else {
            // ����ַ����������ڼ�¼�У��ͽ����ִ�����ʼ��Ϊ0����ӵ���¼��
            thisOccurrence = 0;
            words.push_back(p);
        }
    }

public:
    // Ĭ�Ϲ��캯��
    NString() : thisOccurrence(0) {}

    // ���캯��������һ��std::string
    NString(const std::string& x) : s(x) { 
        addString(x); 
    }

    // ���캯��������C����ַ���
    NString(const char* x) : s(x) { 
        addString(x); 
    }

    // ������������أ����ڴ�ӡNString����
    friend std::ostream& operator<<(std::ostream& os, const NString& ns) {
        return os << ns.s << " [" << ns.thisOccurrence << "]";
    }

    // �Ƚϲ��������أ��������򣬽��Ƚ��ַ������֣������Ƚϳ��ִ���
    friend bool operator<(const NString& l, const NString& r) { 
        return l.s < r.s; 
    }

    // �Ƚϲ��������أ���������Լ�飬���Ƚ��ַ�������
    friend bool operator==(const NString& l, const NString& r) { 
        return l.s == r.s; 
    }

    // �Ƚϲ��������أ�����greater<NString>���򣨲μ����ĵĽ��ͣ������Ƚ��ַ�������
    friend bool operator>(const NString& l, const NString& r) { 
        return l.s > r.s; 
    }

    // ��ʽת��Ϊconst std::string&��ֱ�ӻ�ȡ�ַ�������
    operator const std::string&() const { 
        return s; 
    }
};

// ��ʼ����̬��Ա������
// ����NString::vp��һ��ģ�壬��������ʹ�õ��ǰ���ģ�ͣ�
// ��˱��������ͷ�ļ��н��С�
NString::vp NString::words;
#endif // NSTRING_H ///:~