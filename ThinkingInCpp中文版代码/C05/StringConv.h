//: C05:StringConv.h
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ������������ģ��֧��T��string��������֮����໥ת��
#ifndef STRINGCONV_H
#define STRINGCONV_H
#include <string>
#include <sstream>

template<typename T>
T fromString(const std::string& s) { 
    std::istringstream is(s); 
    T t; 
    is >> t; 
    return t; 
}

template<typename T>
std::string toString(const T& t) { 
    std::ostringstream s; 
    s << t; 
    return s.str(); 
}
#endif // STRINGCONV_H ///:~