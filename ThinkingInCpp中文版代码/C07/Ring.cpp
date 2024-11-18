//: C07:Ring.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 从STL创建“环”数据结构
#include <iostream>
#include <iterator>
#include <list>
#include <string>
using namespace std;

template<class T>
class Ring {
    list<T> lst;  // Ring类内部以list为基础容器

public:
    // 这个类声明是必要的，目的是使后面的friend语句看到的是这个iterator类，
    // 而不是 std::iterator。
    class iterator;
    friend class iterator; // 使自定义的iterator类成为Ring类的友元类

    // 自定义迭代器类，继承自标准库中的双向迭代器
    class iterator : public std::iterator<
        std::bidirectional_iterator_tag, T, ptrdiff_t> {
        typename list<T>::iterator it; // 内部使用的列表迭代器
        list<T>* r; // 指向Ring内部列表的指针

    public:
        // 构造函数，初始化内部迭代器和指向Ring内部列表的指针
        iterator(list<T>& lst, const typename list<T>::iterator& i)
            : it(i), r(&lst) {}

        // 比较两个迭代器是否相等
        bool operator==(const iterator& x) const {
            return it == x.it;
        }

        // 比较两个迭代器是否不相等
        bool operator!=(const iterator& x) const {
            return !(*this == x);
        }

        // 解引用操作符，返回当前迭代器所指向的实际元素的引用
        typename list<T>::reference operator*() const {
            return *it;
        }

        // 前缀递增操作符，移动到下一个元素，返回当前迭代器
        iterator& operator++() {
            ++it;
            if(it == r->end()) it = r->begin(); // 如果到达末尾，则跳转到开头
            return *this;
        }

        // 后缀递增操作符，移动到下一个元素并返回原来的迭代器
        iterator operator++(int) {
            iterator tmp = *this;
            ++*this;
            return tmp;
        }

        // 前缀递减操作符，移动到前一个元素，返回当前迭代器
        iterator& operator--() {
            if(it == r->begin()) it = r->end(); // 如果到达开头，则跳转到末尾
            --it;
            return *this;
        }

        // 后缀递减操作符，移动到前一个元素并返回原来的迭代器
        iterator operator--(int) {
            iterator tmp = *this;
            --*this;
            return tmp;
        }

        // 插入操作，插入一个新元素并返回新的迭代器
        iterator insert(const T& x) {
            // 使用新插入的元素x的迭代器创建一个新的Ring::iterator对象
            return iterator(*r, r->insert(it, x));
        }

        // 删除或擦除（erase）操作，删除当前元素并返回新的迭代器
        iterator erase() {
            // 使用删除操作返回的迭代器创建一个新的Ring::iterator对象
            // 注意，r->erase(it)返回指向被删除元素的下一个元素的迭代器
            // 如果删除的是最后一个元素，则返回end()
            return iterator(*r, r->erase(it));
        }
    };

    // 向环中添加一个元素
    void push_back(const T& x) {
        lst.push_back(x);
    }

    // 返回环的起始迭代器
    iterator begin() {
        return iterator(lst, lst.begin());
    }

    // 返回环的大小
    int size() {
        return lst.size();
    }
};

int main() {
    Ring<string> rs;
    rs.push_back("一");
    rs.push_back("二");
    rs.push_back("三");
    rs.push_back("四");
    rs.push_back("五");

    // 获取环的起始迭代器
    Ring<string>::iterator it = rs.begin();

    // 移动迭代器到第三个元素
    ++it;
    ++it;

    // 在当前位置插入一个新元素
    it.insert("六");

    // 重置迭代器到起始位置
    it = rs.begin();

    // 绕环两圈，输出所有元素
    for(int i = 0; i < rs.size() * 2; i++)
        cout << *it++ << endl;
} ///:~
