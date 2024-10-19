//: .\C03:TESTHEADER_Rparse.cpp
//: C03:Rparse.h
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
// To store the words:
// The ';' characters will be delimiters
// The last element of the string:
// The beginning of the current word:
// Walk backward through the string:
// Push each word into the vector.
// Current is incremented before copying
// to avoid copying the delimiter:
// Back over the delimiter we just found,
// and set last to the end of the next word:
// Find the next delimiter:
// Pick up the first word -- it's not
// preceded by a delimiter:
// Test them in the new order:
// Manually put last word in to avoid an extra space:
// RPARSE_H ///:~
#include"Rparse.h"
int main() {}
