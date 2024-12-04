// �޸�ResponsiveUI.cpp��ʹ��interrupt()������quitFlag������ 

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include <condition_variable>

using namespace std;

class DisplayTask {
    ifstream in;
    string line;
    bool quitFlag;
    std::mutex mtx;
    std::condition_variable cv;

public:
    DisplayTask(const string& file) : quitFlag(false) {
        in.open(file);
        if (!in.is_open()) {
            throw runtime_error("�޷����ļ�");
        }
    }
    ~DisplayTask() {
        in.close();
    }
    void run() {
        while (true) {
            std::unique_lock<std::mutex> lock(mtx);
            if (cv.wait_for(lock, chrono::milliseconds(1000), [this] { return quitFlag; })) {
                break;
            }
            if (getline(in, line)) {
                cout << line << endl;
            } else {
                break;
            }
        }
    }
    void quit() {
        std::lock_guard<std::mutex> lock(mtx);
        quitFlag = true;
        cv.notify_all();
    }
};

int main() {
    try {
        cout << "�밴<Enter>���˳�:" << endl;
        DisplayTask dt("ResponsiveUI_CPP20.cpp");
        thread t(&DisplayTask::run, &dt);
        cin.get();
        dt.quit();
        t.join();
    } catch(const exception& e) {
        cerr << "�쳣: " << e.what() << endl;
    }
    cout << "���ڹر�..." << endl;
    return 0;
}
