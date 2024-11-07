//: C06:copy_if.h
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// �Զ���STL�����㷨
#ifndef COPY_IF_H
#define COPY_IF_H

template<typename ForwardIter, typename OutputIter,
    typename UnaryPred>
OutputIter copy_if(ForwardIter begin, ForwardIter end,
    OutputIter dest, UnaryPred f) {
    while (begin != end) {
        if (f(*begin)) *dest++ = *begin;
        ++begin;
    }
    return dest;
}
#endif // COPY_IF_H ///:~
