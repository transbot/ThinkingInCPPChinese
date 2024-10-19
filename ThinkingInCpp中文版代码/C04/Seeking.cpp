//: C04:Seeking.cpp
// 来自《C++编程思想, 第2卷》
// 作者：Bruce Eckel & Chuck Allison
// 译者：周靖(bookzhou.com)
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 在iostream中定位
#include <cassert>
#include <cstddef>
#include <cstring>
#include <fstream>
#include "../require.h"
using namespace std;

int main() {
  const int STR_NUM = 5, STR_LEN = 50; // 定义字符串数量和每个字符串的长度
  char origData[STR_NUM][STR_LEN] = {
    "我只能在没有哀愁的梦境里回来。",
    "我怕你亲吻我脸庞发现我满眼悲悔，",
    "我怕你追问离去的父亲。",
    "你年迈的孩子。",
    "我怕我见到你我会愧对原来的自己！"
  };
  char readData[STR_NUM][STR_LEN] = {{ 0 }};
  ofstream out("虞美人·故乡.bin", ios::out | ios::binary);
  assure(out, "虞美人·故乡.bin");
  for(int i = 0; i < STR_NUM; i++)
    out.write(origData[i], STR_LEN);
  out.close();
  ifstream in("虞美人·故乡.bin", ios::in | ios::binary);
  assure(in, "虞美人·故乡.bin");

  // 读取文件中存储的第一行文本
  in.read(readData[0], STR_LEN);
  assert(strcmp(readData[0], "我只能在没有哀愁的梦境里回来。")
      == 0);  
  
  // 从文件尾向前移动 -STR_LEN 个字节
  in.seekg(-STR_LEN, ios::end); // 定位到了文件中存储的最后一行开头
  in.read(readData[1], STR_LEN);
  assert(strcmp(readData[1], "我怕我见到你我会愧对原来的自己！")
      == 0);
  
  // 绝对定位（类似于对文件使用operator[]）  
  in.seekg(3 * STR_LEN); // 定位到文件中存储的第4行文本开头
  in.read(readData[2], STR_LEN); // 读取第4行文本
  assert(strcmp(readData[2], "你年迈的孩子。") == 0);  

  // 从当前位置向后（反向）移动
  in.seekg(-STR_LEN * 2, ios::cur); // 从第4行末尾定位到了第3行开头
  in.read(readData[3], STR_LEN);
  assert(strcmp(readData[3], "我怕你追问离去的父亲。") == 0);

  // 从文件的开头定位
  in.seekg(1 * STR_LEN, ios::beg);
  in.read(readData[4], STR_LEN); // 定位到了第2行开头
  assert(strcmp(readData[4], "我怕你亲吻我脸庞发现我满眼悲悔，")
    == 0);
} ///:~
