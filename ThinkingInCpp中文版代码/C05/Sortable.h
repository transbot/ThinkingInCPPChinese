//: C05:Sortable.h
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ģ���ػ�
#ifndef SORTABLE_H
#define SORTABLE_H
#include <cstring>
#include <cstddef>
#include <string>
#include <vector>
using std::size_t;

template<class T>
class Sortable : public std::vector<T> {
public:
    void sort();
};

template<class T>
void Sortable<T>::sort() { // ������
    for(size_t i = this->size(); i > 0; --i)
        for(size_t j = 1; j < i; ++j)
            if(this->at(j-1) > this->at(j)) {
                T t = this->at(j-1);
                this->at(j-1) = this->at(j);
                this->at(j) = t;
            }
}

// ָ��ƫ�����֣��ػ���
template<class T>
class Sortable<T*> : public std::vector<T*> {
public:
    void sort();
};

template<class T> void Sortable<T*>::sort() {
    for(size_t i = this->size(); i > 0; --i)
        for(size_t j = 1; j < i; ++j)
            if(*this->at(j-1) > *this->at(j)) {
                T* t = this->at(j-1);
                this->at(j-1) = this->at(j);
                this->at(j) = t;
            }
}

// char*ȫ�ػ�
// ������Ϊ�˷��㽫���������������������������Ӧ�ý�������
//  ���ڵ������ļ��У�����ֻд��������
template<> inline void Sortable<char*>::sort() {
    for(size_t i = this->size(); i > 0; --i)
        for(size_t j = 1; j < i; ++j)
            if(std::strcmp(this->at(j-1), this->at(j)) > 0) {
                char* t = this->at(j-1);
                this->at(j-1) = this->at(j);
                this->at(j) = t;
            }
}
#endif // SORTABLE_H ///:~
