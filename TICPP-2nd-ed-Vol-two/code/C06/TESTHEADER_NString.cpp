//: .\C06:TESTHEADER_NString.cpp
//: C06:NString.h
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// A "numbered string" that keeps track of the
// number of occurrences of the word it contains.
// Only compare on the first element
// Keep track of the number of occurrences:
// Implicit operator= and copy-constructor are OK here.
// Need this for sorting. Notice it only
// compares strings, not occurrences:
// For sorting with greater<NString>:
// To get at the string directly:
// Because NString::vp is a template and we are using the
// inclusion model, it must be defined in this header file:
// NSTRING_H ///:~
#include"NString.h"
int main() {}
