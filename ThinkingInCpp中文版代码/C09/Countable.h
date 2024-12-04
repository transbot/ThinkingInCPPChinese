//: C09:Countable.h
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ���루mixin����
#ifndef COUNTABLE_H
#define COUNTABLE_H
#include <cassert>
class Countable {
    long count;
protected:
    Countable() { count = 0; }
    virtual ~Countable() { assert(count == 0); } // ���������������麯��
public:
    long attach() { return ++count; }
    long detach() {
        // ���ü�������㣬��ִ��delete this����
        return (--count > 0) ? count : (delete this, 0);
    }
    long refCount() const { return count; } // ���ü���
};
#endif // COUNTABLE_H ///:~
