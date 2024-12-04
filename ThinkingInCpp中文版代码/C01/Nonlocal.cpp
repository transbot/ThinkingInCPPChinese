//: C01:Nonlocal.cpp
// ��ʾsetjmp() & longjmp()
#include <iostream>
#include <csetjmp>
using namespace std;

// �������ħ������
class Rainbow {
public:
    Rainbow() { cout << "Rainbow()" << endl; }
    ~Rainbow() { cout << "~Rainbow()" << endl; }
};

jmp_buf kansas; // ������ת�صĵ�

// ģ������˿�ڰ��ȹ��ľ���
void oz() {
    Rainbow rb; // ����ħ������
    for (int i = 0; i < 3; i++)
        cout << "û���ĸ��ط��ȼҸ���" << endl;
    // ���ع��µĿ�ͷ
    longjmp(kansas, 47);
}

int main() {
    // ���浱ǰִ��������
    if (setjmp(kansas) == 0) {
        cout << "����硢Ů�ס�â�����..." << endl;
        oz(); // ����ħ������
    }
    else {
        // ���ξ�������
        cout << "��ķ����! "
            << "�����˸�����ֵ���..."
            << endl;
    }
} ///:~
