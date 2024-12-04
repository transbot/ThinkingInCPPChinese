//: C10:Bicycle.h
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// �������ڹ������г��ĸ�����
// ��ʾ�������ߡ����ģʽ
#ifndef BICYCLE_H
#define BICYCLE_H
#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include "../purge.h"
using std::size_t;

// �������г�������
class BicyclePart {
public:
    // �������г�������ö������
    enum BPart { 
    FRAME,       // ����
    WHEEL,       // ����
    SEAT,        // ����
    DERAILLEUR,  // ������
    HANDLEBAR,   // ����
    SPROCKET,    // ����
    RACK,        // ����
    SHOCK,       // ������
    NPARTS       // ��������
};
private:
    BPart id; // ������ʶ��
    static std::string names[NPARTS]; // ������������
public:
    // ���캯�������ò����ı�ʶ��
    BicyclePart(BPart bp) { id = bp; }
    // ��Ԫ�����������������������
    friend std::ostream& operator<<(std::ostream& os, const BicyclePart& bp) {
        return os << bp.names[bp.id];
    }
};

// �������г���
class Bicycle {
    std::vector<BicyclePart*> parts; // �������洢�����г�����
public:
    // �����������ͷ����в������ڴ�
    ~Bicycle() { purge(parts); }
    // ��һ���µĲ�����ӵ����г���
    void addPart(BicyclePart* bp) { parts.push_back(bp); }
    // ��Ԫ�����������������������������г������в���
    friend std::ostream& operator<<(std::ostream& os, const Bicycle& b) {
        os << "{ ";
        for(size_t i = 0; i < b.parts.size(); ++i)
            os << *b.parts[i] << ' ';
        return os << '}';
    }
};

// �������г������߳�����
class BicycleBuilder {
protected:
    Bicycle* product; // ��ǰ���ڹ��������г�
public:    
    BicycleBuilder() { product = 0; } // Ĭ�Ϲ��캯��������Ʒ��ʼ��Ϊnullptr    
    void createProduct() { product = new Bicycle; } // �����µ����г���Ʒ    
    virtual void buildFrame() = 0; // �������ܵ��麯��    
    virtual void buildWheel() = 0; // �������ֵ��麯��    
    virtual void buildSeat() = 0;  // �������ε��麯��    
    virtual void buildDerailleur() = 0; // �������������麯��    
    virtual void buildHandlebar() = 0;  // �������ѵ��麯��    
    virtual void buildSprocket() = 0;   // �������ֵ��麯��    
    virtual void buildRack() = 0;       // �������ܵ��麯��    
    virtual void buildShock() = 0;      // �������������麯��    
    virtual std::string getBikeName() const = 0; // ��ȡ���г����Ƶ��麯��

    Bicycle* getProduct() { // ��ȡ�����Ĳ�Ʒ
        Bicycle* temp = product; // ���浱ǰ��Ʒ
        product = 0; // ������Ʒ
        return temp;
    }
};

// ����ɽ�����г���������
class MountainBikeBuilder : public BicycleBuilder {
public:    
    void buildFrame(); // �������ܵľ���ʵ��    
    void buildWheel(); // �������ӵľ���ʵ��    
    void buildSeat();  // �������εľ���ʵ��    
    void buildDerailleur(); // �����������ľ���ʵ��    
    void buildHandlebar();  // �������ѵľ���ʵ��    
    void buildSprocket();   // �������ֵľ���ʵ��    
    void buildRack();       // �������ܵľ���ʵ��    
    void buildShock();      // �����������ľ���ʵ��
    
    // ��ȡɽ�����г�������
    std::string getBikeName() const { return "ɽ�س�";}
};

// �������г���������
class TouringBikeBuilder : public BicycleBuilder {
public:    
    void buildFrame();  // �������ܵľ���ʵ��    
    void buildWheel();  // �������ӵľ���ʵ��    
    void buildSeat();   // �������εľ���ʵ��    
    void buildDerailleur(); // �����������ľ���ʵ��    
    void buildHandlebar();  // �������ѵľ���ʵ��    
    void buildSprocket();   // �������ֵľ���ʵ��    
    void buildRack();       // �������ܵľ���ʵ��    
    void buildShock();      // �����������ľ���ʵ��
    
    // ��ȡ���г�������
    std::string getBikeName() const { return "���г�"; }
};

// ����������������
class RacingBikeBuilder : public BicycleBuilder {
public:    
    void buildFrame();  // �������ܵľ���ʵ��    
    void buildWheel();  // �������ӵľ���ʵ��    
    void buildSeat();   // �������εľ���ʵ��    
    void buildDerailleur(); // �����������ľ���ʵ��    
    void buildHandlebar();  // �������ѵľ���ʵ��    
    void buildSprocket();   // �������ֵľ���ʵ��    
    void buildRack();       // �������ܵľ���ʵ��    
    void buildShock();      // �����������ľ���ʵ��
    
    // ��ȡ����������
    std::string getBikeName() const { return "����"; }
};

// �������г�������
class BicycleTechnician {
    BicycleBuilder* builder; // ��ǰʹ�õĽ�����
public:
    // Ĭ�Ϲ��캯�����������߳�ʼ��Ϊnullptr
    BicycleTechnician() { builder = 0; }
    // ���õ�ǰʹ�õĽ�����
    void setBuilder(BicycleBuilder* b) { builder = b; }
    // �������г�
    void construct();
};
#endif // BICYCLE_H ///:~
