//: C11:Incrementer_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ���ִ�C++��������ʾ��Ϊ�����̹߳���ͬһ���ڳ������ʱ���ٵĶ���������ġ��δ��󡱡�
// n���յ��ۼӽ��Ӧ����200�򣬶����м��Σ��ͻᷢ�����Ρ�
/* �������: Count���������̹߳������Ƕ�ָ��ͬһ���ڴ��ַ��
   ��������: �����߳�ͬʱ��count.n�����޸ģ�û��ͬ�����ơ�
   �δ���ԭ��:
       1. ��main��������ʱ��count�������������Ҳ��������ռ�õ��ڴ汻�ͷš�
       2. ���ǣ�t1��t2�߳̿��ܻ�û����ɶ�count.n���޸Ĳ�����
       3. ����Щ�߳���ͼ�����Ѿ����ͷŵ��ڴ�ʱ���ͻᴥ���δ���
*/
#include <thread>
#include <vector>
#include <iostream>

class Count {
public:
    int n = 0;
    void increment() {
        n++;
    }
};

void incrementer(Count* count) {
    for (int i = 0; i < 1000000; ++i) {
        count->increment();
    }
}

int main() {
    Count count;
    std::thread t1(incrementer, &count);
    std::thread t2(incrementer, &count);

    t1.join();
    t2.join();

    std::cout << count.n << std::endl;
    return 0;
}