//: C07:TokenIterator.h
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
#ifndef TOKENITERATOR_H
#define TOKENITERATOR_H
#include <algorithm>
#include <cctype>
#include <functional>
#include <iterator>
#include <string>

// 以下两个函数对象在现代C++中都应该替换为lambda表达式
// 定义一个一元函数对象，用于判断字符是否为字母
struct Isalpha : std::unary_function<char, bool> {
    bool operator()(char c) { return std::isalpha(c); }
};

// 定义一个一元函数对象，用于判断字符是否不在排除列表中
class Delimiters : public std::unary_function<char, bool> {
    std::string exclude; // 排除列表
public:
    Delimiters() {} // 默认构造函数
    // 以下构造函数接受一个排除列表
    Delimiters(const std::string& excl) : exclude(excl) {} 
    bool operator()(char c) {
        // 如果字符不在排除列表中，那么返回true
        return exclude.find(c) == std::string::npos; 
    }
};

// 定义用于分词的模板类TokenIterator
template<class InputIter, class Pred = Isalpha>
class TokenIterator : public std::iterator<std::input_iterator_tag,
    std::string, std::ptrdiff_t> {
    InputIter first;  // 输入迭代器，指向当前处理位置
    InputIter last;   // 输入迭代器，指向结束位置
    std::string word; // 当前分词结果
    Pred predicate;   // 谓词函数对象，用于判断字符是否应包含在单词中

public:
    // 构造函数，初始化迭代器范围和谓词函数对象
    TokenIterator(InputIter begin, InputIter end, Pred pred = Pred())
        : first(begin), last(end), predicate(pred) {
        ++*this; // 初始化时跳过初始的非单词部分
    }

    // 默认构造函数，用于创建结束哨兵
    TokenIterator() {}

    // 前缀递增操作：先找到下一个单词，然后返回*this（指向当前单词的迭代器）
    TokenIterator& operator++() {
        word.resize(0); // 清空当前单词
        // 找到下一个满足谓词函数的字符
        first = std::find_if(first, last, predicate); 
        while(first != last && predicate(*first))
            word += *first++; // 将满足谓词函数的字符添加到单词中
        return *this;
    }

    // 后缀递增操作：先返回当前单词的拷贝，然后找到下一个单词
    class CaptureState {
        std::string word; // 存储当前单词
    public:
        CaptureState(const std::string& w) : word(w) {} // 构造函数，初始化单词
        std::string operator*() { return word; } // 返回当前单词
    };
    CaptureState operator++(int) {
        CaptureState d(word); // 创建一个捕获当前状态的对象
        ++*this;  // 前缀递增
        return d; // 返回捕获的状态
    }

    // 生成实际值
    std::string operator*() const { return word; }
    const std::string* operator->() const { return &word; }

    // 比较迭代器
    bool operator==(const TokenIterator& other) {
        // 如果当前单词为空且迭代器到达结束位置，那么返回true
        return word.size() == 0 && first == last;
    }

    bool operator!=(const TokenIterator& other) {
        return !(*this == other); // 不等于操作
    }
};
#endif // TOKENITERATOR_H ///:~
