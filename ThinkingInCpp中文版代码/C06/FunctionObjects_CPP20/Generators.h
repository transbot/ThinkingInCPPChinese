//: C06:Generators.h
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 定义不同的生成器，它们以不同的方式填充序列
#ifndef GENERATORS_H
#define GENERATORS_H
#include <cstring>
#include <set>
#include <cstdlib>

// 一个可以跳过数字的生成器：
class SkipGen {
    int i;
    int skp;
public:
    SkipGen(int start = 0, int skip = 1) : i(start), skp(skip) {}
    int operator()() {
        int r = i;
        i += skp;
        return r;
    }
};

// 生成从0到limit（不含）范围内的不重复的随机数。
// 例如，假定limit为10，以下代码会生成0-9的不重复的随机数，
// 并插入used集合中：
class URandGen {
    std::set<int> used;
    int limit;
public:
    URandGen(int lim) : limit(lim) {}
    int operator()() {
        while(true) {
            int i = int(std::rand()) % limit;
            if(used.find(i) == used.end()) {
                used.insert(i);
                return i;
            }
        }
    }
};

// 生成随机字符：
class CharGen {
    static const char* source;
    static const int len;
public:
    char operator()() {
        return source[std::rand() % len];
    }
};
#endif // GENERATORS_H ///:~
