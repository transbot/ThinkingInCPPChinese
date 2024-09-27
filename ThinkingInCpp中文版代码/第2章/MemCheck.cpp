//: C02:MemCheck.cpp {O}
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstddef>
using namespace std;
#undef new

// ͨ��MemCheck.h�еĺ�����ȫ�ֱ�־
bool traceFlag = true;
bool activeFlag = false;

namespace {
    // �ڴ�ӳ���¼�memory map entry�������ͣ�һ���ṹ��
    struct Info {
        void* ptr;
        const char* file;
        long line;
    };

    // �ڴ�ӳ������
    const size_t MAXPTRS = 10000u;
    Info memMap[MAXPTRS];
    size_t nptrs = 0;

    // ��ӳ����������ַ
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
        // ��ӳ�����Ƴ���
        for (size_t i = pos; i < nptrs - 1; ++i) {
            memMap[i] = memMap[i + 1];
        }
        --nptrs;
    }

    // ���dummy���٣�����Ψһ�����þ����ṩһ����̬��������
    struct Sentinel {
        ~Sentinel() {
            if (nptrs > 0) {
                printf("������λ�÷����ڴ�й©:\n");
                for (size_t i = 0; i < nptrs; ++i) {
                    printf("\t%p (�ļ�: %s, �к�: %ld)\n",
                        memMap[i].ptr, memMap[i].file, memMap[i].line);
                }
            } else {
                printf("δ�����û��ڴ�й©!\n");
            }
        }
    };

    // ʵ����һ����̬��dummy���٣�����
    Sentinel s;
} // �������������ռ�

// ���ر����汾��new
void* operator new(size_t siz, const char* file, long line) {
    void* p = malloc(siz);
    if (activeFlag) {
        if (nptrs == MAXPTRS) {
            printf("�ڴ�ӳ��̫С(������MAXPTRS)\n");
            exit(1);
        }
        memMap[nptrs].ptr = p;
        memMap[nptrs].file = file;
        memMap[nptrs].line = line;
        ++nptrs;
    }
    if (traceFlag) {
        printf("�ڵ�ַ %p �������� %u �ֽ�", p, siz);
        printf("(�ļ�: %s, �к�: %ld)\n", file, line);
    }
    return p;
}

// ��������汾��new
void* operator new[](size_t siz, const char* file, long line) {
    return operator new(siz, file, line);
}

// ���ر����汾��delete
void operator delete(void* p) {
    if (findPtr(p) >= 0) {
        free(p);
        assert(nptrs > 0);
        delPtr(p);
        if (traceFlag) {
            printf("���ͷŵ�ַ%p�����ڴ�\n", p);
        }
    } else if (!p && activeFlag) {
        printf("��ͼdeleteδָ֪��: %p\n", p);
    }
}

// ��������汾��delete��Ϊ�˼򻯱�̣������в�����ת�����˱����汾
void operator delete[](void* p) {
    operator delete(p);
}
///:~
