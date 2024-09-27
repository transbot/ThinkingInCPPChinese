//: C05:ImplicitCast.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.

template<typename R, typename P>
R implicit_cast(const P& p) {
  return p;
}

int main() {
  int i = 1;
  float x = implicit_cast<float>(i);
  int j = implicit_cast<int>(x);
  //! char* p = implicit_cast<char*>(i);
} ///:~
