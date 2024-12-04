//: C10:ChainOfReponsibility.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ģ��5��С����Ҫ����
// �����ʾ�������У����мҳ�������һ������������
#include <iostream>
#include <vector>
#include "../purge.h"
using namespace std;

// ��ҳ���һ�����������Ҫôͬ�⣬Ҫô�Ǿܾ�
enum Answer { NO, YES }; 

class GimmeStrategy { // �ֶ����Ĳ���
public:
    virtual Answer canIHave() = 0; // ���麯����������������Ϊ
    virtual ~GimmeStrategy() {}    // ������������ȷ�������������ȷ����
};

class AskMom : public GimmeStrategy { // ���������
public:
    Answer canIHave() {
        cout << "�裬�ҿ���Ҫ�����" << endl;
        return NO; // ����ܾ�
    }
};

class AskDad : public GimmeStrategy { // ����ǰְ�
public:
    Answer canIHave() {
        cout << "�֣���Ҫ�����" << endl;
        return NO; // �ְ־ܾ�
    }
};

class AskGrandpa : public GimmeStrategy { // �����үү
public:
    Answer canIHave() {
        cout << "үү���Ҷ�Ҫ�������ˣ�" << endl;
        return NO; // үү�ܾ�
    }
};

class AskGrandma : public GimmeStrategy { // ���������
public:
    Answer canIHave() {
        cout << "���̣��Һð���ร�" << endl;
        return YES; // Ŷ������ͬ���ˣ�
    }
};

class Gimme : public GimmeStrategy {
    vector<GimmeStrategy*> chain; // ������

public:
    Gimme() {
        // ��ʼ������������˳����Ӹ�������
        chain.push_back(new AskMom());     // ����Ҫ
        chain.push_back(new AskDad());     // �ʰ�Ҫ
        chain.push_back(new AskGrandpa()); // ��үүҪ 
        chain.push_back(new AskGrandma()); // ������Ҫ
    }

    Answer canIHave() { // ��Ҫ�����Ľ����YES��NO��
        // ����������������ÿ������
        vector<GimmeStrategy*>::iterator it = chain.begin();
        while(it != chain.end())
            if((*it++)->canIHave() == YES)
                return YES; // ���ĳ�����Գɹ�������YES
        // ����ĩβ��δ�ɹ�...
        cout << "����!" << endl; // ���ʧ��
        return NO; // ����NO�����ջ��Ǳ��ܾ���
    }

    ~Gimme() {        
        purge(chain); // ����������е����ж���
    }
};

int main() {
    Gimme chain; // ����������
    chain.canIHave(); // �������󣬿���˭���Ӧ
} ///:~
