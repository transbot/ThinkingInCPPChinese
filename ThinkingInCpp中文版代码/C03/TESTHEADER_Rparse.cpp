//: .\C03:TESTHEADER_Rparse.cpp
//: C03:Rparse.h
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
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
