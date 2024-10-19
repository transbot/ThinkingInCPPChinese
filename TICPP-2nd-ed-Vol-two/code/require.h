//: :require.h
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
// Test for error conditions in programs.
#ifndef REQUIRE_H
#define REQUIRE_H
#include <cstdio>
#include <cstdlib>
#include <fstream>

inline void require(bool requirement,
  const char* msg = "Requirement failed") {
  // Local "using namespace std" for old compilers:
  using namespace std;
  if(!requirement) {
    fputs(msg, stderr);
    fputs("\n", stderr);
    exit(EXIT_FAILURE);
  }
}

inline void requireArgs(int argc, int args,
  const char* msg = "Must use %d arguments") {
  using namespace std;
  if(argc != args + 1) {
    fprintf(stderr, msg, args);
    fputs("\n", stderr);
    exit(EXIT_FAILURE);
  }
}

inline void requireMinArgs(int argc, int minArgs,
  const char* msg = "Must use at least %d arguments") {
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
    fprintf(stderr, "Could not open file %s\n", filename);
    exit(EXIT_FAILURE);
  }
}

inline void assure(std::ofstream& in,
  const char* filename = "") {
  using namespace std;
  if(!in) {
    fprintf(stderr, "Could not open file %s\n", filename);
    exit(EXIT_FAILURE);
  }
}

inline void assure(std::fstream& in,
  const char* filename = "") {
  using namespace std;
  if(!in) {
    fprintf(stderr, "Could not open file %s\n", filename);
    exit(EXIT_FAILURE);
  }
}
#endif // REQUIRE_H ///:~
