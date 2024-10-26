//: C05:Sortable.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
//{-bor} (因为Urand.h中使用了bitset)

// 测试模板规范
#include <cstddef>
#include <iostream>
#include "Sortable.h"
#include "Urand.h"
using namespace std;

// 计算数组a的元素个数
// asz是“数组大小”（array size）的意思
#define asz(a) (sizeof a / sizeof a[0])

char* words[] = { "is", "running", "big", "dog", "a", };
char* words2[] = { "this", "that", "theother", };

int main() {
  Sortable<int> is;
  Urand<47> rnd;
  for(size_t i = 0; i < 15; ++i)
    is.push_back(rnd());
  for(size_t i = 0; i < is.size(); ++i)
    cout << is[i] << ' ';
  cout << endl;
  is.sort();
  for(size_t i = 0; i < is.size(); ++i)
    cout << is[i] << ' ';
  cout << endl;

  // 使用模板偏特化（部分特化）：
  Sortable<string*> ss;
  for(size_t i = 0; i < asz(words); ++i)
    ss.push_back(new string(words[i]));
  for(size_t i = 0; i < ss.size(); ++i)
    cout << *ss[i] << ' ';
  cout << endl;
  ss.sort();
  for(size_t i = 0; i < ss.size(); ++i) {
    cout << *ss[i] << ' ';
    delete ss[i];
  }
  cout << endl;

  // 使用针对char*的全特化
  Sortable<char*> scp;
  for(size_t i = 0; i < asz(words2); ++i)
    scp.push_back(words2[i]);
  for(size_t i = 0; i < scp.size(); ++i)
    cout << scp[i] << ' ';
  cout << endl;
  scp.sort();
  for(size_t i = 0; i < scp.size(); ++i)
    cout << scp[i] << ' ';
  cout << endl;
} ///:~
