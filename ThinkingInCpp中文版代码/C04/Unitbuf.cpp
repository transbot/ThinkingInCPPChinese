//: C04:Unitbuf.cpp {RunByHand}
// 来自《C++编程思想, 第2卷》
// 作者：Bruce Eckel & Chuck Allison
// 译者：周靖(bookzhou.com)
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

#include <cstdlib>  // 为了使用abort()
#include <fstream>
using namespace std;

int main() {
  ofstream out("log.txt");
  // out.setf(ios::unitbuf);
  out << "one" << endl;
  out << "two" << endl;
  abort();
} ///:~
