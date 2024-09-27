//: :require.h
// 来自《C++编程思想, 第2版》
// 作者：Bruce Eckel & Chuck Allison。
// 译者：周靖(bookzhou.com)
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页https://bookzhou.com下载。

// 测试程序中的错误情况（error conditions）
#ifndef REQUIRE_H
#define REQUIRE_H
#include <cstdio>
#include <cstdlib>
#include <fstream>

inline void require(bool requirement,
  const char* msg = "未满足需求") {
  // 旧编译器要求局部的"using namespace std":
  using namespace std;
  if(!requirement) {
    fputs(msg, stderr);
    fputs("\n", stderr);
    exit(EXIT_FAILURE);
  }
}

inline void requireArgs(int argc, int args,
  const char* msg = "必须提供%d个实参") {
  using namespace std;
  if(argc != args + 1) {
    fprintf(stderr, msg, args);
    fputs("\n", stderr);
    exit(EXIT_FAILURE);
  }
}

inline void requireMinArgs(int argc, int minArgs,
  const char* msg = "至少需要提供%d个实参") {
  using namespace std;
  if(argc < minArgs + 1) {
    fprintf(stderr, msg, minArgs);
    fputs("\n", stderr);
    exit(EXIT_FAILURE);
  }
}

inline void assure(std::ifstream& in,
  const char* filename = "") {
  using namespace std;
  if(!in) {
    fprintf(stderr, "无法打开文件%s\n", filename);
    exit(EXIT_FAILURE);
  }
}

inline void assure(std::ofstream& in,
  const char* filename = "") {
  using namespace std;
  if(!in) {
    fprintf(stderr, "无法打开文件%s\n", filename);
    exit(EXIT_FAILURE);
  }
}

inline void assure(std::fstream& in,
  const char* filename = "") {
  using namespace std;
  if(!in) {
    fprintf(stderr, "无法打开文件%s\n", filename);
    exit(EXIT_FAILURE);
  }
}
#endif // REQUIRE_H ///:~
