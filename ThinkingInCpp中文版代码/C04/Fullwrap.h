//: C04:Fullwrap.h
// ���ԡ�C++���˼��, ��2��
// ���ߣ�Bruce Eckel & Chuck Allison��
// ���ߣ��ܾ�(bookzhou.com)
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ������ȫ�������ļ�I/O
#ifndef FULLWRAP_H
#define FULLWRAP_H
#include <cstddef>
#include <cstdio>

// ȡ���Ա�׼������Щ��Ķ��壬
// ��Ϊ�˱������Զ����ͬ������������ͻ��
#undef getc 
#undef putc
#undef ungetc

using std::size_t;
using std::fpos_t;

class File {
    std::FILE* f;
    std::FILE* F(); // �ú������ؾ�������fָ��
public:
    File(); // �������󣬵������ļ�
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
    int seek(long offset, int whence); // whence����ƴд���󣬴�������￪ʼseek
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