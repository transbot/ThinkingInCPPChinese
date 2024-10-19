//: C05:StaticAssert1.cpp {-xo}
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
// A simple, compile-time assertion facility

#define STATIC_ASSERT(x) \
  do { typedef int a[(x) ? 1 : -1]; } while(0)

int main() {
  STATIC_ASSERT(sizeof(int) <= sizeof(long)); // Passes
  STATIC_ASSERT(sizeof(double) <= sizeof(int)); // Fails
} ///:~
