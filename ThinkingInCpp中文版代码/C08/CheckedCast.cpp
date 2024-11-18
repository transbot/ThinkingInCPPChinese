//: C08:CheckedCast.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ������ʱִ�о�����֤��ǿ������ת����checked cast��
#include <iostream>
#include <vector>
#include "../purge.h"
using namespace std;

class Security { // ֤ȯ
protected:
    enum { BASEID = 0 };
public:
    virtual ~Security() {} // ����������
    
    // ���麯�����ڼ���������ͣ����������඼Ҫ��д��
    // ���ڼ������Ƿ����ڵ�ǰ����������ࡣ
    virtual bool isA(int id) { return (id == BASEID); }
};

class Stock : public Security { // ��Ʊ
    typedef Security Super;
protected:
    enum { OFFSET = 1, TYPEID = BASEID + OFFSET };
public:
    bool isA(int id) {
        return id == TYPEID || Super::isA(id);
    }
    static Stock* dynacast(Security* s) {
        return (s->isA(TYPEID)) ? static_cast<Stock*>(s) : 0;
    }
};

class Bond : public Security { // ծȯ
    typedef Security Super;
protected:
    enum { OFFSET = 2, TYPEID = BASEID + OFFSET };
public:
    bool isA(int id) {
        return id == TYPEID || Super::isA(id);
    }
    static Bond* dynacast(Security* s) {
        return (s->isA(TYPEID)) ? static_cast<Bond*>(s) : 0;
    }
};

class Investment : public Security { // Ͷ��
    typedef Security Super;
protected:
    enum { OFFSET = 3, TYPEID = BASEID + OFFSET };
public:
    bool isA(int id) {
        return id == TYPEID || Super::isA(id);
    }
    static Investment* dynacast(Security* s) {
        return (s->isA(TYPEID)) ? static_cast<Investment*>(s) : 0;
    }
    void special() {
        cout << "Investment�����⺯��" << endl;
    }
};

class Metal : public Investment { // ����
    typedef Investment Super;
protected:
    enum { OFFSET = 4, TYPEID = BASEID + OFFSET };
public:
    bool isA(int id) {
        return id == TYPEID || Super::isA(id);
    }
    static Metal* dynacast(Security* s) {
        return (s->isA(TYPEID)) ? static_cast<Metal*>(s) : 0;
    }
};

int main() {
    vector<Security*> portfolio; // ����һ���洢��ͬ����֤ȯ�ġ��ʲ���ϡ�����
    portfolio.push_back(new Metal); // ���һ����������
    portfolio.push_back(new Investment); // ���һ��Ͷ�ʶ���
    portfolio.push_back(new Bond); // ���һ��ծȯ����
    portfolio.push_back(new Stock); // ���һ����Ʊ����

    // ����portfolio���������ÿ�������ǲ���Investment����
    for(vector<Security*>::iterator it = portfolio.begin();
        it != portfolio.end(); ++it) {
        Investment* cm = Investment::dynacast(*it); // ���Խ�Securityָ��ת��ΪInvestmentָ��
        if(cm) // ���ת�ͳɹ�
            cm->special(); // ��ô����Investment�����⺯��
        else
            cout << "����һ��Investment" << endl; // ���ת��ʧ�ܣ������ʾ��Ϣ
    }

    cout << "��̳в�νṹ���м䣨����ָ���ǿ��ת����" << endl;
    Security* sp = new Metal; // ����һ��ָ��Metal�����Securityָ��
    Investment* cp = Investment::dynacast(sp); // ���Խ�Securityָ��ת��ΪInvestmentָ��
    if(cp)
        cout << "����һ��Investment" << endl; // ���ת�ͳɹ��������ʾ��Ϣ
    Metal* mp = Metal::dynacast(sp); // ���Խ�Securityָ��ת��ΪMetalָ��
    if(mp)
        cout << "��Ҳ��һ��Metal!" << endl; // ���ת�ͳɹ��������ʾ��Ϣ

    purge(portfolio); // ����portfolio�е����ж���
} ///:~