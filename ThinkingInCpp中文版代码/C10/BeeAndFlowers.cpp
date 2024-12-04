//: C10:BeeAndFlowers.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

//: C10:BeeAndFlowers.cpp
// ��ʾ������ģʽ
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "../purge.h"
using namespace std;

class Gladiolus;     // ����
class Renuculus;     // ëݢ
class Chrysanthemum; // �ջ�

// �����߻���
class Visitor {
public:
    virtual void visit(Gladiolus* f) = 0;     // ���ʽ�������
    virtual void visit(Renuculus* f) = 0;     // ����ëݢ����
    virtual void visit(Chrysanthemum* f) = 0; // ���ʾջ�����
    virtual ~Visitor() {}
};

// ���Ļ���
class Flower {
public:
    virtual void accept(Visitor&) = 0; // ���ܷ�����
    virtual ~Flower() {}
};

// ������
class Gladiolus : public Flower {
public:
    virtual void accept(Visitor& v) { v.visit(this); } // ���ܷ�����
};

// ëݢ��
class Renuculus : public Flower {
public:
    virtual void accept(Visitor& v) { v.visit(this); } // ���ܷ�����
};

// �ջ���
class Chrysanthemum : public Flower {
public:
    virtual void accept(Visitor& v) { v.visit(this); } // ���ܷ�����
};

// ��������ַ���������
class StringVal : public Visitor {
    string s;
public:
    operator const string&() { return s; }
    virtual void visit(Gladiolus*) {
        s = "����";
    }
    virtual void visit(Renuculus*) {
        s = "ëݢ";
    }
    virtual void visit(Chrysanthemum*) {
        s = "�ջ�";
    }
};

// ���۷����ַ�����������۷�ִ�еĲ���
class Bee : public Visitor {
public:
    virtual void visit(Gladiolus*) {
        cout << "�۷�ͽ���" << endl;
    }
    virtual void visit(Renuculus*) {
        cout << "�۷��ëݢ" << endl;
    }
    virtual void visit(Chrysanthemum*) {
        cout << "�۷�;ջ�" << endl;
    }
};

// �������Flower����
struct FlowerGen {
    Flower* operator()() {
        switch(rand() % 3) {
            default:
            case 0: return new Gladiolus;      // ���ɽ�������
            case 1: return new Renuculus;      // ����ëݢ����
            case 2: return new Chrysanthemum;  // ���ɾջ�����
        }
    }
};

int main() {
    srand(time(0)); // ��ʼ�������������
    vector<Flower*> v(10);
    generate(v.begin(), v.end(), FlowerGen());
    vector<Flower*>::iterator it;
    
    // ������ΪFlower����������ַ�����ʾ���麯��
    StringVal sval;
    for(it = v.begin(); it != v.end(); it++) {
        (*it)->accept(sval);
        cout << string(sval) << endl;
    }
    
    // ������Flowerִ�С��۷䡱�Ĳ���
    Bee bee;
    for(it = v.begin(); it != v.end(); it++)
        (*it)->accept(bee);
    purge(v);
} ///:~
