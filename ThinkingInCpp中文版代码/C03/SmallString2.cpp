//: C03:SmallString2.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.


#include <string>
#include <iostream>

using namespace std;

int main() {
    string s1("What is the sound of one clam napping?");
    string s2("Anything worth doing is worth overdoing.");
    string s3("I saw Elvis in a UFO");

    // ����ǰ8���ַ�
    string s4(s1, 0, 8);
    cout << s4 << endl;  // �����What is 

    // ����Դ�ַ����м�λ�õ�6���ַ�
    string s5(s2, 15, 6);
    cout << s5 << endl;  // �����doing

    // ���м�λ�ÿ�������β
    string s6(s3, 6, 15);
    cout << s6 << endl;  // �����Elvis in a UFO

    // �ϲ�����ַ���
    string quoteMe = s4 + "that" +
                     // substr()��Ԫ��20��ʼ����10���ַ���
                     s1.substr(20, 10) + s5 +
                     // substr()��Ԫ��5��ʼ�������100���ַ���
                     // ����һֱ�������ַ���ĩβ��
                     "with" + s3.substr(5, 100) +
                     // �������������������ַ�������ģ�
                     s1.substr(37, 1);
    cout << quoteMe << endl;  // �����What is that one clam doing with Elvis in a UFO?
} ///:~
