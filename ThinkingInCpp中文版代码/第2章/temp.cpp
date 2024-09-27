#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
void generateData1(int data[], int SZ) {
    int max = 0; // ��ʼ�� max Ϊ 0
    for (int i = 0; i < SZ; ++i) {
        data[i] = max + (rand() % 2 == 0 ? 1 : 2);
        max = data[i - 1];
    }
}

void generateData2(int data[], int SZ) {
    int max = 0; // ��ʼ�� max Ϊ 0
    for (int i = 0; i < SZ; rand() % 2 == 0 ? max += 1 : max += 2) {
        data[i++] = max;
    }
}
int main() {
    const int SZ = 10;
    int data1[SZ], data2[SZ];

    // ��ʼ�����������
    srand(time(0));

    // ��������1
    generateData1(data1, SZ);

    cout << "data1: ";
    for (int i = 0; i < SZ; ++i) {
        cout << data1[i] << " ";
    }
    cout << endl;

    // ��������2
    generateData2(data2, SZ);

    cout << "data2: ";
    for (int i = 0; i < SZ; ++i) {
        cout << data2[i] << " ";
    }
    cout << endl;

    return 0;
}