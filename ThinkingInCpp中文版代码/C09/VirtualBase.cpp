//: C09:VirtualBase.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ͨ�������ʵ�ֶ�ͬһ���Ӷ���Ĺ���
#include <iostream>
using namespace std;

class Top { // �����
protected:
    int x;  // ��Ա����x
public:
    Top(int n) { x = n; }  // ���캯������ʼ��x
    virtual ~Top() {}  // ������������ȷ���������������������ȷ����
    friend ostream& operator<<(ostream& os, const Top& t) {
        return os << t.x;  // ����<<�����������x
    }
};

// ����������Left����̳���Top
class Left : virtual public Top {
protected:
    int y;  // ��Ա����y
public:
    Left(int m, int n) : Top(m) { y = n; }  // ���캯������ʼ������Top�ͳ�Ա����y
};

// ����������Right����̳���Top
class Right : virtual public Top {
protected:
    int z;  // ��Ա���� z
public:
    Right(int m, int n) : Top(m) { z = n; }  // ���캯������ʼ������Top �ͳ�Ա����z
};

// ���������� Bottom�����ؼ̳���Left��Right
class Bottom : public Left, public Right {
    int w;  // ��Ա����w
public:
    // ���캯������ʼ������Top��Left�� Right���Լ���Ա����w
    Bottom(int i, int j, int k, int m) : Top(i), Left(0, j), Right(0, k) { w = m; }    

    // ����<<��������������г�Ա����
    friend ostream& operator<<(ostream& os, const Bottom& b) {
        return os << b.x << ',' << b.y << ',' << b.z << ',' << b.w;
    }
};

int main() {
    Bottom b(1, 2, 3, 4);  // ���� Bottom��Ķ���b����ʼ����Ա����
    cout << "sizeof(b) == " << sizeof(b) << endl;  // �������b�Ĵ�С
    cout << "b == " << b << endl;  // �������b�����г�Ա����
    cout << "&b == " << static_cast<void*>(&b) << endl;  // �������b�ĵ�ַ
    Top* p = static_cast<Top*>(&b);  // ������b�ĵ�ַת��ΪTop���͵�ָ��
    cout << "*p == " << *p << endl;  // ���ͨ��ָ��p���ʵ�Top���ֵ�xֵ
    cout << "p == " << static_cast<void*>(p) << endl;  // ���ָ��p�ĵ�ַ
    // ʹ��dynamic_castת��ָ��p�ĵ�ַ
    cout << "dynamic_cast<void*>(p) == " << dynamic_cast<void*>(p) << endl;  
}