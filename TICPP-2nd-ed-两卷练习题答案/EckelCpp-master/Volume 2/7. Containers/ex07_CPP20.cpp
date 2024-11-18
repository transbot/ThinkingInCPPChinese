/*
用斐波那契数列填充一个stack<int>。通过命令行指定斐波那契数列中的元素数量。
程序应输出最后一个斐波那契数。提示：应该在一个循环中检查栈顶的最后两个元素，
并且每次循环都压入一个新元素。
*/

#include <iostream>
#include <stack>

int main() {
    int n = 0;
    std::cout << "请输入斐波那契数列中的元素数量: ";
    std::cin >> n;

    if (n < 1) {
        std::cerr << "元素数量必须大于0" << std::endl;
        return 1;
    }

    if (n == 1 || n == 2) {
        std::cout << "第 " << n << " 个斐波那契数是: 1" << std::endl;
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

    std::cout << "第 " << n << " 个斐波那契数是: " << numbers.top() << std::endl;

    return 0;
}