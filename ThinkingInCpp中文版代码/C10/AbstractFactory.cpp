//: C10:AbstractFactory.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��Ϸ����
#include <iostream>
using namespace std;

// �����ϰ�����
class Obstacle {
public:
    virtual void action() = 0; // ���麯�����������ʵ��
};

// ���������
class Player {
public:
    virtual void interactWith(Obstacle*) = 0; // ���麯�����������ʵ��
};

// ��������ࣺKitty
class Kitty : public Player {
public:
    virtual void interactWith(Obstacle* ob) {
        cout << "Kitty������һ��"; // ���Kitty�����ϰ������Ϣ
        ob->action(); // �����ϰ����action����
    }
};

// ��������ࣺKungFuGuy
class KungFuGuy : public Player {
public:
    virtual void interactWith(Obstacle* ob) {
        cout << "KungFuGuy�������ڶԿ�һ��"; // ���KungFuGuy�Կ��ϰ������Ϣ
        ob->action(); // �����ϰ����action����
    }
};

// �����ϰ����ࣺPuzzle
class Puzzle : public Obstacle {
public:
    void action() {
        cout << "����" << endl; // ����������Ϣ
    }
};

// �����ϰ����ࣺNastyWeapon
class NastyWeapon : public Obstacle {
public:
    void action() {
        cout << "��������" << endl; // ���������������Ϣ
    }
};

// ���󹤳���
class GameElementFactory {
public:
    virtual Player* makePlayer() = 0; // ���麯�����������ʵ��
    virtual Obstacle* makeObstacle() = 0; // ���麯�����������ʵ��
};

// ���幤���ࣺKittiesAndPuzzles
class KittiesAndPuzzles : public GameElementFactory {
public:
    virtual Player* makePlayer() {
        return new Kitty; // �������Kitty
    }
    virtual Obstacle* makeObstacle() {
        return new Puzzle; // �����ϰ���Puzzle
    }
};

// ���幤���ࣺKillAndDismember
class KillAndDismember : public GameElementFactory {
public:
    virtual Player* makePlayer() {
        return new KungFuGuy; // �������KungFuGuy
    }
    virtual Obstacle* makeObstacle() {
        return new NastyWeapon; // �����ϰ���NastyWeapon
    }
};

// ��Ϸ������
class GameEnvironment {
    GameElementFactory* gef; // ��������
    Player* p; // ��Ҷ���
    Obstacle* ob; // �ϰ������
public:
    // ���캯������ʼ����������Һ��ϰ���
    GameEnvironment(GameElementFactory* factory)
        : gef(factory), p(factory->makePlayer()), ob(factory->makeObstacle()) {}
    
    // ��Ϸ�淨
    void play() {
        p->interactWith(ob); // ������ϰ��ﻥ��
    }
    
    // �����������ͷ���Դ
    ~GameEnvironment() {
        delete p;   // �ͷ���Ҷ���
        delete ob;  // �ͷ��ϰ������
        delete gef; // �ͷŹ�������
    }
};

int main() {
    // ����������Ϸ�������ֱ�ʹ�ò�ͬ�Ĺ���
    GameEnvironment g1(new KittiesAndPuzzles), g2(new KillAndDismember);
    
    // ��ʼ��Ϸ
    g1.play(); // Kitty��������
    g2.play(); // KungFuGuy�Կ���������
} /* �����
Kitty������һ������
KungFuGuy�������ڶԿ�һ����������
*/