//: C05:Sortable.h
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 模板特化
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
void Sortable<T>::sort() { // 简单排序
    for(size_t i = this->size(); i > 0; --i)
        for(size_t j = 1; j < i; ++j)
            if(this->at(j-1) > this->at(j)) {
                T t = this->at(j-1);
                this->at(j-1) = this->at(j);
                this->at(j) = t;
            }
}

// 指针偏（部分）特化：
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

// char*全特化
// （这里为了方便将其做成内联函数——正常情况下应该将函数体
//  放在单独的文件中，这里只写声明。）
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
