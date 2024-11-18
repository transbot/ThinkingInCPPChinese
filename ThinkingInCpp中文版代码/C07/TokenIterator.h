//: C07:TokenIterator.h
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
#ifndef TOKENITERATOR_H
#define TOKENITERATOR_H
#include <algorithm>
#include <cctype>
#include <functional>
#include <iterator>
#include <string>

// �������������������ִ�C++�ж�Ӧ���滻Ϊlambda���ʽ
// ����һ��һԪ�������������ж��ַ��Ƿ�Ϊ��ĸ
struct Isalpha : std::unary_function<char, bool> {
    bool operator()(char c) { return std::isalpha(c); }
};

// ����һ��һԪ�������������ж��ַ��Ƿ����ų��б���
class Delimiters : public std::unary_function<char, bool> {
    std::string exclude; // �ų��б�
public:
    Delimiters() {} // Ĭ�Ϲ��캯��
    // ���¹��캯������һ���ų��б�
    Delimiters(const std::string& excl) : exclude(excl) {} 
    bool operator()(char c) {
        // ����ַ������ų��б��У���ô����true
        return exclude.find(c) == std::string::npos; 
    }
};

// �������ڷִʵ�ģ����TokenIterator
template<class InputIter, class Pred = Isalpha>
class TokenIterator : public std::iterator<std::input_iterator_tag,
    std::string, std::ptrdiff_t> {
    InputIter first;  // �����������ָ��ǰ����λ��
    InputIter last;   // �����������ָ�����λ��
    std::string word; // ��ǰ�ִʽ��
    Pred predicate;   // ν�ʺ������������ж��ַ��Ƿ�Ӧ�����ڵ�����

public:
    // ���캯������ʼ����������Χ��ν�ʺ�������
    TokenIterator(InputIter begin, InputIter end, Pred pred = Pred())
        : first(begin), last(end), predicate(pred) {
        ++*this; // ��ʼ��ʱ������ʼ�ķǵ��ʲ���
    }

    // Ĭ�Ϲ��캯�������ڴ��������ڱ�
    TokenIterator() {}

    // ǰ׺�������������ҵ���һ�����ʣ�Ȼ�󷵻�*this��ָ��ǰ���ʵĵ�������
    TokenIterator& operator++() {
        word.resize(0); // ��յ�ǰ����
        // �ҵ���һ������ν�ʺ������ַ�
        first = std::find_if(first, last, predicate); 
        while(first != last && predicate(*first))
            word += *first++; // ������ν�ʺ������ַ���ӵ�������
        return *this;
    }

    // ��׺�����������ȷ��ص�ǰ���ʵĿ�����Ȼ���ҵ���һ������
    class CaptureState {
        std::string word; // �洢��ǰ����
    public:
        CaptureState(const std::string& w) : word(w) {} // ���캯������ʼ������
        std::string operator*() { return word; } // ���ص�ǰ����
    };
    CaptureState operator++(int) {
        CaptureState d(word); // ����һ������ǰ״̬�Ķ���
        ++*this;  // ǰ׺����
        return d; // ���ز����״̬
    }

    // ����ʵ��ֵ
    std::string operator*() const { return word; }
    const std::string* operator->() const { return &word; }

    // �Ƚϵ�����
    bool operator==(const TokenIterator& other) {
        // �����ǰ����Ϊ���ҵ������������λ�ã���ô����true
        return word.size() == 0 && first == last;
    }

    bool operator!=(const TokenIterator& other) {
        return !(*this == other); // �����ڲ���
    }
};
#endif // TOKENITERATOR_H ///:~
