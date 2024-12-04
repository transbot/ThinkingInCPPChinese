//: C10:PaperScissorsRock_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// �á�ʯͷ-����-������Ϸ����ʾ���ص��ȣ������ǡ�˫�ص��ȡ������ߡ�˫���ɡ�
/* ����ʹ���ִ�C++�����˸Ľ���
����ָ�룺
    ʹ�� std::unique_ptr������̬������ڴ棬�����ڴ�й©��
    std::make_unique���ڴ���std::unique_ptr����

�ִ�C++���ԣ�
    ʹ��enum class������ö�����ͣ����������ռ���Ⱦ��
    ʹ��override�ؼ�������ȷָ����д���麯����

��������ɣ�
    ʹ��static_cast<unsigned>��ȷ��time(0)�ķ���ֵ���޷���������

�Զ������ڴ棺
    ʹ��std::unique_ptr�Զ������ڴ棬����Ҫ�ֶ������ڴ棨����Ҫԭ��һֱ��ʹ�õ�purge.h�ˣ���
*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <memory>
#include <random>
using namespace std;

class Paper;
class Scissors;
class Rock;

// ������Ϸ���ö������
enum class Outcome { WIN, LOSE, DRAW };

// ��������������������������Ϸ���
ostream& operator<<(ostream& os, const Outcome out) {
    switch(out) {
        default:
        case Outcome::WIN: return os << "Ӯ��";
        case Outcome::LOSE: return os << "����";
        case Outcome::DRAW: return os << "ƽ��";
    }
}

// ����Item��ʾ��Ϸ�е�һ����Ʒ����ʵ��һ�����ƣ�
class Item {
public:
    // ���麯�������ڱȽ�������Ʒ
    virtual Outcome compete(const Item*) const = 0;
    // ���麯����������ֵ��������Ʒ�Ĺ�ϵ
    virtual Outcome eval(const Paper*) const = 0;
    virtual Outcome eval(const Scissors*) const = 0;
    virtual Outcome eval(const Rock*) const = 0;
    // ���麯�������������Ʒ����
    virtual ostream& print(ostream& os) const = 0;
    // ����������
    virtual ~Item() {}
    // ��Ԫ���������������Ʒ
    friend ostream& operator<<(ostream& os, const Item* it) {
        return it->print(os);
    }
};

// ������Paper����ʾ������
class Paper : public Item {
public:
    // �Ƚ�������Ʒ
    Outcome compete(const Item* it) const override { return it->eval(this);}
    // ��ֵ��������Ʒ�Ĺ�ϵ
    Outcome eval(const Paper*) const override { return Outcome::DRAW; }
    Outcome eval(const Scissors*) const override { return Outcome::WIN; }
    Outcome eval(const Rock*) const override { return Outcome::LOSE; }
    // �����Ʒ����
    ostream& print(ostream& os) const override {
        return os << "��";
    }
};

// ������Scissors����ʾ�����ӡ�
class Scissors : public Item {
public:
    // �Ƚ�������Ʒ
    Outcome compete(const Item* it) const override { return it->eval(this);}
    // ��ֵ��������Ʒ�Ĺ�ϵ
    Outcome eval(const Paper*) const override { return Outcome::LOSE; }
    Outcome eval(const Scissors*) const override { return Outcome::DRAW; }
    Outcome eval(const Rock*) const override { return Outcome::WIN; }
    // �����Ʒ����
    ostream& print(ostream& os) const override {
        return os << "����";
    }
};

// ������Rock����ʾ��ʯͷ��
class Rock : public Item {
public:
    // �Ƚ�������Ʒ
    Outcome compete(const Item* it) const override { return it->eval(this);}
    // ��ֵ��������Ʒ�Ĺ�ϵ
    Outcome eval(const Paper*) const override { return Outcome::WIN; }
    Outcome eval(const Scissors*) const override { return Outcome::LOSE; }
    Outcome eval(const Rock*) const override { return Outcome::DRAW; }
    // �����Ʒ����
    ostream& print(ostream& os) const override {
        return os << "ʯͷ";
    }
};

// �ṹ��ItemGen�������������Ʒ
struct ItemGen {
    std::unique_ptr<Item> operator()() {
        switch(rand() % 3) {
            default:
            case 0: return std::make_unique<Scissors>();
            case 1: return std::make_unique<Paper>();
            case 2: return std::make_unique<Rock>();
        }
    }
};

// �ṹ��Compete���ڱȽ�������Ʒ
struct Compete {
    Outcome operator()(const std::unique_ptr<Item>& a, const std::unique_ptr<Item>& b) {
        cout << a.get() << "\t" << b.get() << "\t";
        return a->compete(b.get()); // ��ʼ˫�ص���
    }
};

int main() {
    srand(static_cast<unsigned>(time(0))); // ��ʼ�������������
    const int sz = 20;
    vector<std::unique_ptr<Item>> v(sz * 2);
    generate(v.begin(), v.end(), ItemGen()); // ���������Ʒ�����ƣ�
    transform(v.begin(), v.begin() + sz,
              v.begin() + sz,
              ostream_iterator<Outcome>(cout, "\n"),
              Compete()); // �Ƚ���Ʒ�����ƣ���������
} ///:~
