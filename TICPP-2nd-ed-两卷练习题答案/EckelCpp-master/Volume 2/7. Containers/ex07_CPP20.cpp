/*
��쳲������������һ��stack<int>��ͨ��������ָ��쳲����������е�Ԫ��������
����Ӧ������һ��쳲�����������ʾ��Ӧ����һ��ѭ���м��ջ�����������Ԫ�أ�
����ÿ��ѭ����ѹ��һ����Ԫ�ء�
*/

#include <iostream>
#include <stack>

int main() {
    int n = 0;
    std::cout << "������쳲����������е�Ԫ������: ";
    std::cin >> n;

    if (n < 1) {
        std::cerr << "Ԫ�������������0" << std::endl;
        return 1;
    }

    if (n == 1 || n == 2) {
        std::cout << "�� " << n << " ��쳲���������: 1" << std::endl;
        return 0;
    }

    std::stack<int> numbers;

    int a = 1;
    int b = 1;
    int c = 0;

    numbers.push(a);
    numbers.push(b);

    for (int i = 3; i <= n; i++) {
        b = numbers.top();
        numbers.pop();

        a = numbers.top();
        numbers.pop();

        c = a + b;

        numbers.push(a);
        numbers.push(b);
        numbers.push(c);
    }

    std::cout << "�� " << n << " ��쳲���������: " << numbers.top() << std::endl;

    return 0;
}