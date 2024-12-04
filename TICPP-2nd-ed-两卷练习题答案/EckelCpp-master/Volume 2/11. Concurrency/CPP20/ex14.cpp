/* ����һ����æ�ȴ�����ʾ�����μ�11.6.2�ڣ���һ���߳�˯��һ����󣬽�һ����־����Ϊtrue��
 �ڶ����߳���һ��whileѭ���ڼ��Ӹñ�־������ǡ�æ�ȴ�����������־��Ϊtrueʱ��������������Ϊfalse���������̨����仯��
 ע������ڡ�æ�ȴ������˷��˶���ʱ�䣬�������������һ���汾��ʹ��wait()�����ǡ�æ�ȴ�����
 ������ϰ������ĳ������̽������profiler������ʾÿ������µ�CPUռ��ʱ�䡣 */

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

std::mutex mtx;
std::condition_variable cv;
bool flag = false;

void setFlagAfterSleep() {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    {
        std::lock_guard<std::mutex> lock(mtx);
        flag = true;
    }
    cv.notify_all();
}

void wait() {
    auto start = std::chrono::high_resolution_clock::now();
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, []{ return flag; });
    flag = false;
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "��־��Ϊtrue���ȴ�ʱ��: " << elapsed.count() << " ��" << std::endl;
}

int main() {
    std::thread t1(setFlagAfterSleep);
    std::thread t2(wait);

    t1.join();
    t2.join();

    return 0;
}
