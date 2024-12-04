// C11:ResponsiveUI_CPP20.cpp {RunByHand}
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ͨ�����̴߳�����ʵ����Ӧ������UI
#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

class DisplayTask {
    ifstream in;
    string line;
    bool quitFlag;

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
        while(getline(in, line) && !quitFlag) {
            cout << line << endl;
            this_thread::sleep_for(chrono::milliseconds(1000)); // ģ�ⳤʱ�����е�����
        }
    }
    void quit() {
        quitFlag = true;
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