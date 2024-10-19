//: C06:ComposeTry.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
// A first attempt at implementing function composition.
#include <cassert>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <string>
using namespace std;

template<typename R, typename E, typename F1, typename F2>
class unary_composer {
  F1 f1;
  F2 f2;
public:
  unary_composer(F1 fone, F2 ftwo) : f1(fone), f2(ftwo) {}
  R operator()(E x) { return f1(f2(x)); }
};

template<typename R, typename E, typename F1, typename F2>
unary_composer<R, E, F1, F2> compose(F1 f1, F2 f2) {
  return unary_composer<R, E, F1, F2>(f1, f2);
}

int main() {
  double x = compose<double, const string&>(
    atof, mem_fun_ref(&string::c_str))("12.34");
  assert(x == 12.34);
} ///:~
