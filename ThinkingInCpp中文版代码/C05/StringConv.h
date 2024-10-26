//: C05:StringConv.h
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 以下两个函数模板支持T与string两种类型之间的相互转换
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