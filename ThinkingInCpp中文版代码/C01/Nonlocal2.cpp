//: C01:Nonlocal2.cpp
// ��ʾ�쳣����
#include <iostream>
using namespace std;

// �������ħ������
class Rainbow {
public:
    Rainbow() { cout << "Rainbow()" << endl; }
    ~Rainbow() { cout << "~Rainbow()" << endl; }
};

// ģ������˿�ڰ��ȹ��ľ���
void oz() {
    Rainbow rb;
    for(int i = 0; i < 3; i++)
        cout << "û���ĸ��ط��ȼҸ���" << endl;
    throw 47;
}

int main() {
    try {
        cout << "����硢Ů�ס�â�����..." << endl;
        oz(); // ����ħ������
    } catch(int) {
        cout << "��ķ����! "
             << "�����˸�����ֵ���..."
             << endl;
    }
} ///:~
