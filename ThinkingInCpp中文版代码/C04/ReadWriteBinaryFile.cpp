//: C04:ReadWriteBinaryFile.cpp
// ���ԡ�C++���˼��, ��2��
// ���ߣ�Bruce Eckel & Chuck Allison��
// ���ߣ��ܾ�(bookzhou.com)
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

#include <iostream>
#include <fstream>

// ���ڲ���δ��ʽ����I/O����read()��get()��
// ����������data.binд����������ݣ��ٴ��ж�ȡ��
// ע�⣬���������ʾ����ԭ��û�С�
using namespace std;

int main() {
    // д�벿��
    ofstream outputFile("data.bin", ios::binary);  // �Զ�����ģʽ���ļ�
    int data[] = {1, 2, 3, 4, 5};
    outputFile.write(reinterpret_cast<char*>(data), sizeof(data));
    outputFile.close();

    // ��ȡ����
    ifstream inputFile("data.bin", ios::binary);  // �Զ�����ģʽ���ļ�
    int readData[sizeof(data)];
    inputFile.read(reinterpret_cast<char*>(readData), sizeof(data));
    inputFile.close();

    // ��ʾ��ȡ��������
    cout << "��ȡ�������ݣ�";
    for (int i = 0; i < sizeof(data) / sizeof(int); ++i) {
        cout << readData[i] << " ";
    }
    cout << endl;

    return 0;
}