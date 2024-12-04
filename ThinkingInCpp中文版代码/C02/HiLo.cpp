//: C02:HiLo.cpp {RunByHand}
// ������´�С����Ϸ������ѭ��������
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "����һ��1��100֮�������" << endl
         << "�һ��������������Ҳµ�����̫��(H)������̫С(L)" << endl;
    int low = 1, high = 100; // ��ʼ��Χ
    bool guessed = false;    // �Ƿ���еı�־
    
    while(!guessed) {
        // INVARIANT(������): �����ڷ�Χ[low, high]��
        if(low > high) { // Υ��������
            cout << "�����ף��Ҳ����ˣ�" << endl;
            return EXIT_FAILURE;
        }
        
        int guess = (low + high) / 2;
        cout << "�Ҳµ�����" << guess << "��";
        cout << "(H)̫��, (L)̫С, ���� (E)�¶���? ";
        string response;
        cin >> response;
        
        switch(toupper(response[0])) {
            case 'H':
            case 'h':
                high = guess - 1;
                break;
            case 'L':
            case 'l':
                low = guess + 1;
                break;
            case 'E':
            case 'e':
                guessed = true;
                break;
            default:
                cout << "��Ч�ش�" << endl;
                continue;
        }
    }
    
    cout << "�Ҳµ��ˣ�" << endl;
    return EXIT_SUCCESS;
} ///:~
