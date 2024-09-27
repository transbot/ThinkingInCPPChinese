//: C02:MemCheck.cpp {O}
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstddef>
using namespace std;
#undef new

// 通过MemCheck.h中的宏设置全局标志
bool traceFlag = true;
bool activeFlag = false;

namespace {
    // 内存映射记录项（memory map entry）的类型，一个结构体
    struct Info {
        void* ptr;
        const char* file;
        long line;
    };

    // 内存映射数据
    const size_t MAXPTRS = 10000u;
    Info memMap[MAXPTRS];
    size_t nptrs = 0;

    // 在映射中搜索地址
    int findPtr(void* p) {
        for (size_t i = 0; i < nptrs; ++i) {
            if (memMap[i].ptr == p) {
                return i;
            }
        }
        return -1;
    }

    void delPtr(void* p) {
        int pos = findPtr(p);
        assert(pos >= 0);
        // 从映射中移除针
        for (size_t i = pos; i < nptrs - 1; ++i) {
            memMap[i] = memMap[i + 1];
        }
        --nptrs;
    }

    // 这个dummy（假）类型唯一的作用就是提供一个静态析构函数
    struct Sentinel {
        ~Sentinel() {
            if (nptrs > 0) {
                printf("在以下位置发生内存泄漏:\n");
                for (size_t i = 0; i < nptrs; ++i) {
                    printf("\t%p (文件: %s, 行号: %ld)\n",
                        memMap[i].ptr, memMap[i].file, memMap[i].line);
                }
            } else {
                printf("未发生用户内存泄漏!\n");
            }
        }
    };

    // 实例化一个静态的dummy（假）对象
    Sentinel s;
} // 结束匿名命名空间

// 重载标量版本的new
void* operator new(size_t siz, const char* file, long line) {
    void* p = malloc(siz);
    if (activeFlag) {
        if (nptrs == MAXPTRS) {
            printf("内存映射太小(请增大MAXPTRS)\n");
            exit(1);
        }
        memMap[nptrs].ptr = p;
        memMap[nptrs].file = file;
        memMap[nptrs].line = line;
        ++nptrs;
    }
    if (traceFlag) {
        printf("在地址 %p 处分配了 %u 字节", p, siz);
        printf("(文件: %s, 行号: %ld)\n", file, line);
    }
    return p;
}

// 重载数组版本的new
void* operator new[](size_t siz, const char* file, long line) {
    return operator new(siz, file, line);
}

// 重载标量版本的delete
void operator delete(void* p) {
    if (findPtr(p) >= 0) {
        free(p);
        assert(nptrs > 0);
        delPtr(p);
        if (traceFlag) {
            printf("已释放地址%p处的内存\n", p);
        }
    } else if (!p && activeFlag) {
        printf("试图delete未知指针: %p\n", p);
    }
}

// 重载数组版本的delete。为了简化编程，把所有操作都转发给了标量版本
void operator delete[](void* p) {
    operator delete(p);
}
///:~
