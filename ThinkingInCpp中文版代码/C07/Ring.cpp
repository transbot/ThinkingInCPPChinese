//: C07:Ring.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��STL�������������ݽṹ
#include <iostream>
#include <iterator>
#include <list>
#include <string>
using namespace std;

template<class T>
class Ring {
    list<T> lst;  // Ring���ڲ���listΪ��������

public:
    // ����������Ǳ�Ҫ�ģ�Ŀ����ʹ�����friend��俴���������iterator�࣬
    // ������ std::iterator��
    class iterator;
    friend class iterator; // ʹ�Զ����iterator���ΪRing�����Ԫ��

    // �Զ���������࣬�̳��Ա�׼���е�˫�������
    class iterator : public std::iterator<
        std::bidirectional_iterator_tag, T, ptrdiff_t> {
        typename list<T>::iterator it; // �ڲ�ʹ�õ��б������
        list<T>* r; // ָ��Ring�ڲ��б��ָ��

    public:
        // ���캯������ʼ���ڲ���������ָ��Ring�ڲ��б��ָ��
        iterator(list<T>& lst, const typename list<T>::iterator& i)
            : it(i), r(&lst) {}

        // �Ƚ������������Ƿ����
        bool operator==(const iterator& x) const {
            return it == x.it;
        }

        // �Ƚ������������Ƿ����
        bool operator!=(const iterator& x) const {
            return !(*this == x);
        }

        // �����ò����������ص�ǰ��������ָ���ʵ��Ԫ�ص�����
        typename list<T>::reference operator*() const {
            return *it;
        }

        // ǰ׺�������������ƶ�����һ��Ԫ�أ����ص�ǰ������
        iterator& operator++() {
            ++it;
            if(it == r->end()) it = r->begin(); // �������ĩβ������ת����ͷ
            return *this;
        }

        // ��׺�������������ƶ�����һ��Ԫ�ز�����ԭ���ĵ�����
        iterator operator++(int) {
            iterator tmp = *this;
            ++*this;
            return tmp;
        }

        // ǰ׺�ݼ����������ƶ���ǰһ��Ԫ�أ����ص�ǰ������
        iterator& operator--() {
            if(it == r->begin()) it = r->end(); // ������￪ͷ������ת��ĩβ
            --it;
            return *this;
        }

        // ��׺�ݼ����������ƶ���ǰһ��Ԫ�ز�����ԭ���ĵ�����
        iterator operator--(int) {
            iterator tmp = *this;
            --*this;
            return tmp;
        }

        // �������������һ����Ԫ�ز������µĵ�����
        iterator insert(const T& x) {
            // ʹ���²����Ԫ��x�ĵ���������һ���µ�Ring::iterator����
            return iterator(*r, r->insert(it, x));
        }

        // ɾ���������erase��������ɾ����ǰԪ�ز������µĵ�����
        iterator erase() {
            // ʹ��ɾ���������صĵ���������һ���µ�Ring::iterator����
            // ע�⣬r->erase(it)����ָ��ɾ��Ԫ�ص���һ��Ԫ�صĵ�����
            // ���ɾ���������һ��Ԫ�أ��򷵻�end()
            return iterator(*r, r->erase(it));
        }
    };

    // �������һ��Ԫ��
    void push_back(const T& x) {
        lst.push_back(x);
    }

    // ���ػ�����ʼ������
    iterator begin() {
        return iterator(lst, lst.begin());
    }

    // ���ػ��Ĵ�С
    int size() {
        return lst.size();
    }
};

int main() {
    Ring<string> rs;
    rs.push_back("һ");
    rs.push_back("��");
    rs.push_back("��");
    rs.push_back("��");
    rs.push_back("��");

    // ��ȡ������ʼ������
    Ring<string>::iterator it = rs.begin();

    // �ƶ���������������Ԫ��
    ++it;
    ++it;

    // �ڵ�ǰλ�ò���һ����Ԫ��
    it.insert("��");

    // ���õ���������ʼλ��
    it = rs.begin();

    // �ƻ���Ȧ���������Ԫ��
    for(int i = 0; i < rs.size() * 2; i++)
        cout << *it++ << endl;
} ///:~
