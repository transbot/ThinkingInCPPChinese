/* 只使用三个stack对随机数序列进行排序。这三个stack分别是source（源栈）、sorted（已排序栈）和loser（失败栈）。
首先填充源栈。假设源栈顶部的数字最大，并将其压入已排序栈。继续弹出源栈，将其与已排序栈顶的数字进行比较。
不管哪个数字较小，都从其对应的栈中弹出，并压入失败栈。一旦源栈为空，就使用失败栈作为源栈来重复上述过程，
此时使用源栈作为失败栈。重复上述过程，直到所有元素都被移入已排序栈。 */

#include <iostream>
#include <stack>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void sortWithThreeStacks(stack<int>& source, stack<int>& sorted, stack<int>& loser) {
    // 假设source栈顶部的数字最大，并将其压入sorted栈
    sorted.push(source.top());
    source.pop();

    while (!source.empty() || !loser.empty()) {
        while (!source.empty()) {
            int topSource = source.top();
            source.pop();

            if (sorted.empty() || topSource >= sorted.top()) {
                sorted.push(topSource);
            } else {
                int topSorted = sorted.top();
                sorted.pop();
                loser.push(topSorted);
                source.push(topSource);
            }
        }

        // 交换source和loser的角色
        swap(source, loser);
    }
}

int main() {
    srand(time(0)); // 初始化随机数生成器

    stack<int> source, sorted, loser;

    // 填充source栈
    vector<int> randomNumbers;
    for (int i = 0; i < 10; ++i) {
        randomNumbers.push_back(rand() % 100);
    }
    for (int num : randomNumbers) {
        source.push(num);
    }

    cout << "原始序列: ";
    for (int num : randomNumbers) {
        cout << num << " ";
    }
    cout << endl;

    sortWithThreeStacks(source, sorted, loser);

    cout << "排序后的序列: ";
    while (!sorted.empty()) {
        cout << sorted.top() << " ";
        sorted.pop();
    }
    cout << endl;

    return 0;
}