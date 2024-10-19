//: C04:Showerr.cpp {RunByHand}
// 来自《C++编程思想, 第2卷》
// 作者：Bruce Eckel & Chuck Allison
// 译者：周靖(bookzhou.com)
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 取消对有错误的行的注释
#include <cstddef>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "../require.h"
using namespace std;

const string USAGE =
    "用法: showerr filename chapnum\n"
    "其中，filename是C++源文件，\n"
    "chapnum是该文件所在章的编号。\n"
    "本程序查找//!形式的注释行，删除这个标记，\n"
    "并在行末追加一条带编号的注释，即//(#)。其中，# \n"
    "在所有文件中都是唯一的，以便判断\n"
    "编译器是否在指定文件中发现了错误。\n"
    "执行showerr /r\n"
    "将重置这个全局唯一的计数器。";

class Showerr {
    const int CHAP;
    const string MARKER, FNAME;
    // 包含错误编号计数器的文件：
    const string ERRNUM;
    // 包含错误行的文件：
    const string ERRFILE;
    stringstream edited; // 已编辑的文件
    int counter;

public:
    Showerr(const string& f, const string& en, const string& ef, int c)
        : CHAP(c), MARKER("//!"), FNAME(f), ERRNUM(en), ERRFILE(ef), counter(0) {}

    void replaceErrors() {
        ifstream infile(FNAME.c_str());
        assure(infile, FNAME.c_str());
        ifstream count(ERRNUM.c_str());
        if (count) count >> counter;
        int linecount = 1;
        string buf;
        ofstream errlines(ERRFILE.c_str(), ios::app);
        assure(errlines, ERRFILE.c_str());
        while (getline(infile, buf)) {
            // 查找行首的标记：
            size_t pos = buf.find(MARKER);
            if (pos != string::npos) {
                // 删除标记：
                buf.erase(pos, MARKER.size() + 1);
                // 追加计数器和错误信息：
                ostringstream out;
                out << buf << " // (" << ++counter << ") "
                    << " 章号：" << CHAP
                    << " 文件：" << FNAME
                    << " 行：" << linecount << endl;
                edited << out.str();
                errlines << out.str(); // 在错误文件中追加数据
            } else {
                edited << buf << "\n"; // 仅拷贝
            }
            ++linecount;
        }
    }

    void saveFiles() {
        ofstream outfile(FNAME.c_str()); // 覆盖
        assure(outfile, FNAME.c_str());
        outfile << edited.rdbuf();
        ofstream count(ERRNUM.c_str()); // 覆盖
        assure(count, ERRNUM.c_str());
        count << counter; // 保存新的计数器
    }
};

int main(int argc, char* argv[]) {
    const string ERRCOUNT("../errnum.txt"), ERRFILE("../errlines.txt");
    requireMinArgs(argc, 1, USAGE.c_str());
    if (argv[1][0] == '/' || argv[1][0] == '-') {
        // 可以自行添加更多开关选项:
        switch (argv[1][1]) {
            case 'r': case 'R':
                cout << "重置计数器" << endl;
                remove(ERRCOUNT.c_str()); // 删除文件
                remove(ERRFILE.c_str());
                return EXIT_SUCCESS;
            default:
                cerr << USAGE << endl;
                return EXIT_FAILURE;
        }
    }

    if (argc == 3) {
        Showerr s(argv[1], ERRCOUNT, ERRFILE, atoi(argv[2]));
        s.replaceErrors();
        s.saveFiles();
    }
} ///:~
