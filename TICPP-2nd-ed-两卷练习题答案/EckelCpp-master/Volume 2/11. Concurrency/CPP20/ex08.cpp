// 修改ResponsiveUI.cpp，使用interrupt()而不是quitFlag方法。 

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
            throw runtime_error("无法打开文件");
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
        cout << "请按<Enter>键退出:" << endl;
        DisplayTask dt("ResponsiveUI_CPP20.cpp");
        thread t(&DisplayTask::run, &dt);
        cin.get();
        dt.quit();
        t.join();
    } catch(const exception& e) {
        cerr << "异常: " << e.what() << endl;
    }
    cout << "正在关闭..." << endl;
    return 0;
}
