//: C06:PrintSequence.h
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ӡ�������е�����
#ifndef PRINTSEQUENCE_H
#define PRINTSEQUENCE_H
#include <algorithm>
#include <iostream>
#include <iterator>

// ����һ��ģ�庯�������ڴ�ӡ�������е�����
template<typename Iter>
void print(Iter first, Iter last, const char* nm = "",
           const char* sep = "\n",  // Ĭ�Ϸָ���
           std::ostream& os = std::cout) {
    // ����ṩ�����ƣ����ȴ�ӡ����
    // �ִ�C++���Խ�nm != 0�ĳ�nm != nullptr���������������Ͱ�ȫ
    if (nm != 0 && *nm != '\0') {
        os << nm << ": " << sep;
    }

    // ��ȡ��������ֵ����
    typedef typename std::iterator_traits<Iter>::value_type T;

    // ʹ��std::copy�������е�Ԫ�ؿ������������
    std::copy(first, last, std::ostream_iterator<T>(os, sep));

    // ��ӡ���з�
    os << std::endl;
}
#endif // PRINTSEQUENCE_H ///:~
