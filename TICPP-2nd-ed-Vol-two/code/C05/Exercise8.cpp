//: C05:Exercise8.cpp {-xo}
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
template<class T> double pythag(T a, T b, T c) {
  return (-b + sqrt(double(b*b - 4*a*c))) / 2*a;
}

int main() {
  pythag(1, 2, 3);
  pythag(1.0, 2.0, 3.0);
  pythag(1, 2.0, 3.0);
  pythag<double>(1, 2.0, 3.0);
} ///:~
