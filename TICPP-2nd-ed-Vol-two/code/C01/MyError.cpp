//: C01:MyError.cpp {RunByHand}
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

class MyError {
  const char* const data;
public:
  MyError(const char* const msg = 0) : data(msg) {}
};

void f() {
  // Here we "throw" an exception object:
  throw MyError("something bad happened");
}

int main() {
  // As you'll see shortly, we'll want a "try block" here:
  f();
} ///:~
