//: C06:Counted.h
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// һ���ܹ���������Ķ���
#ifndef COUNTED_H
#define COUNTED_H
#include <vector>
#include <iostream>

class Counted {
    static int count;
    char* ident;

public:
    Counted(char* id) : ident(id) { ++count; }
    ~Counted() {
        std::cout << ident << " ���� = " << --count << std::endl;
    }
};

class CountedVector : public std::vector<Counted*> {
public:
    CountedVector(char* id) {
        for(int i = 0; i < 5; i++)
            push_back(new Counted(id));
    }
};

#endif // COUNTED_H
///:~
