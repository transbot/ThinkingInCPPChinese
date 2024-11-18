/* ֻʹ������stack����������н�������������stack�ֱ���source��Դջ����sorted��������ջ����loser��ʧ��ջ����
�������Դջ������Դջ������������󣬲�����ѹ��������ջ����������Դջ��������������ջ�������ֽ��бȽϡ�
�����ĸ����ֽ�С���������Ӧ��ջ�е�������ѹ��ʧ��ջ��һ��ԴջΪ�գ���ʹ��ʧ��ջ��ΪԴջ���ظ��������̣�
��ʱʹ��Դջ��Ϊʧ��ջ���ظ��������̣�ֱ������Ԫ�ض�������������ջ�� */

#include <iostream>
#include <stack>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void sortWithThreeStacks(stack<int>& source, stack<int>& sorted, stack<int>& loser) {
    // ����sourceջ������������󣬲�����ѹ��sortedջ
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

        // ����source��loser�Ľ�ɫ
        swap(source, loser);
    }
}

int main() {
    srand(time(0)); // ��ʼ�������������

    stack<int> source, sorted, loser;

    // ���sourceջ
    vector<int> randomNumbers;
    for (int i = 0; i < 10; ++i) {
        randomNumbers.push_back(rand() % 100);
    }
    for (int num : randomNumbers) {
        source.push(num);
    }

    cout << "ԭʼ����: ";
    for (int num : randomNumbers) {
        cout << num << " ";
    }
    cout << endl;

    sortWithThreeStacks(source, sorted, loser);

    cout << "����������: ";
    while (!sorted.empty()) {
        cout << sorted.top() << " ";
        sorted.pop();
    }
    cout << endl;

    return 0;
}