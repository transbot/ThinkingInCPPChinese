//: C06:Generators.h
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ���岻ͬ���������������Բ�ͬ�ķ�ʽ�������
#ifndef GENERATORS_H
#define GENERATORS_H
#include <cstring>
#include <set>
#include <cstdlib>

// һ�������������ֵ���������
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

// ���ɴ�0��limit����������Χ�ڵĲ��ظ����������
// ���磬�ٶ�limitΪ10�����´��������0-9�Ĳ��ظ����������
// ������used�����У�
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

// ��������ַ���
class CharGen {
    static const char* source;
    static const int len;
public:
    char operator()() {
        return source[std::rand() % len];
    }
};
#endif // GENERATORS_H ///:~
