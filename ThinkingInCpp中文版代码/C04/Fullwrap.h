//: C04:Fullwrap.h
// 来自《C++编程思想, 第2卷》
// 作者：Bruce Eckel & Chuck Allison。
// 译者：周靖(bookzhou.com)
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 本例完全隐藏了文件I/O
#ifndef FULLWRAP_H
#define FULLWRAP_H
#include <cstddef>
#include <cstdio>

// 取消对标准库中这些宏的定义，
// 是为了避免与自定义的同名函数产生冲突。
#undef getc 
#undef putc
#undef ungetc

using std::size_t;
using std::fpos_t;

class File {
    std::FILE* f;
    std::FILE* F(); // 该函数返回经过检查的f指针
public:
    File(); // 创建对象，但不打开文件
    File(const char* path, const char* mode = "r");
    ~File();
    int open(const char* path, const char* mode = "r");
    int reopen(const char* path, const char* mode);
    int getc();
    int ungetc(int c);
    int putc(int c);
    int puts(const char* s);
    char* gets(char* s, int n);
    int printf(const char* format, ...);
    size_t read(void* ptr, size_t size, size_t n);
    size_t write(const void* ptr, size_t size, size_t n);
    int eof();
    int close();
    int flush();
    int seek(long offset, int whence); // whence不是拼写错误，代表从哪里开始seek
    int getpos(fpos_t* pos);
    int setpos(const fpos_t* pos);
    long tell();
    void rewind();
    void setbuf(char* buf);
    int setvbuf(char* buf, int type, size_t sz);
    int error();
    void clearErr();
};
#endif // FULLWRAP_H ///:~