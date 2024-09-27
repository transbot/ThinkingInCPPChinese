//: C05:StaticAssert1.cpp {-xo}
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// A simple, compile-time assertion facility

#define STATIC_ASSERT(x) \
  do { typedef int a[(x) ? 1 : -1]; } while(0)

int main() {
  STATIC_ASSERT(sizeof(int) <= sizeof(long)); // Passes
  STATIC_ASSERT(sizeof(double) <= sizeof(int)); // Fails
} ///:~
