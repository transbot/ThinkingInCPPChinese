//: C04:Cppcheck.cpp
// 来自《C++编程思想, 第2卷》
// 作者：Bruce Eckel & Chuck Allison
// 译者：周靖(bookzhou.com)
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 配置.h和.cpp文件，使之符合样式标准。
// 测试现有文件以确保符合标准。
#include <fstream>
#include <sstream>
#include <string>
#include <cstddef>
#include "../require.h"
using namespace std;

bool startsWith(const string& base, const string& key) {
    return base.compare(0, key.size(), key) == 0;
}

void cppCheck(string fileName) {
    enum bufs { BASE, HEADER, IMPLEMENT, HLINE1, GUARD1,
        GUARD2, GUARD3, CPPLINE1, INCLUDE, BUFNUM };
    string part[BUFNUM];

    part[BASE] = fileName;

    // 查找字符串中的'.'
    size_t loc = part[BASE].find('.');
    if(loc != string::npos)
        part[BASE].erase(loc); // 去掉扩展名

    // 强制转换为大写：
    for(size_t i = 0; i < part[BASE].size(); i++)
        part[BASE][i] = toupper(part[BASE][i]);

    // 创建文件名和文件内部的代码行：
    part[HEADER] = part[BASE] + ".h";
    part[IMPLEMENT] = part[BASE] + ".cpp";
    part[HLINE1] = "//" ": " + part[HEADER];
    part[GUARD1] = "#ifndef " + part[BASE] + "_H";
    part[GUARD2] = "#define " + part[BASE] + "_H";
    part[GUARD3] = "#endif // " + part[BASE] +"_H";
    part[CPPLINE1] = string("//") + ": " + part[IMPLEMENT];
    part[INCLUDE] = "#include \"" + part[HEADER] + "\"";

    // 首先，尝试打开现有的文件：
    ifstream existh(part[HEADER].c_str()),
             existcpp(part[IMPLEMENT].c_str());

    if(!existh) { // 文件不存在；创建它
        ofstream newheader(part[HEADER].c_str());
        assure(newheader, part[HEADER].c_str());
        newheader << part[HLINE1] << endl
                  << part[GUARD1] << endl
                  << part[GUARD2] << endl << endl
                  << part[GUARD3] << endl;
    } else { // 文件已存在；验证它
        stringstream hfile; // 写入和读取
        ostringstream newheader; // 写入
        hfile << existh.rdbuf(); // 检查前三行是否符合标准：
        bool changed = false;
        string s;
        hfile.seekg(0);
        getline(hfile, s);
        bool lineUsed = false;

        // 对good()的调用是为了兼容Microsoft的编译器（后同）:
        for(int line = HLINE1; hfile.good() && line <= GUARD2; ++line) {
            if(startsWith(s, part[line])) {
                newheader << s << endl;
                lineUsed = true;
                if(getline(hfile, s))
                    lineUsed = false;
            } else {
                newheader << part[line] << endl;
                changed = true;
                lineUsed = false;
            }
        }

        // 拷贝文件剩余内容
        if(!lineUsed)
            newheader << s << endl;
        newheader << hfile.rdbuf();

        // 检查GUARD3
        string head = hfile.str();
        if(head.find(part[GUARD3]) == string::npos) {
            newheader << part[GUARD3] << endl;
            changed = true;
        }

        // 如果有变更，则覆盖文件：
        if(changed) {
            existh.close();
            ofstream newH(part[HEADER].c_str());
            assure(newH, part[HEADER].c_str());
            newH << "//@//\n" // 变更标记
                 << newheader.str();
        }
    }

    if(!existcpp) { // 创建 .cpp 文件
        ofstream newcpp(part[IMPLEMENT].c_str());
        assure(newcpp, part[IMPLEMENT].c_str());
        newcpp << part[CPPLINE1] << endl
               << part[INCLUDE] << endl;
    } else { // 文件已存在；验证它
        stringstream cppfile;
        ostringstream newcpp;
        cppfile << existcpp.rdbuf(); // 检查前两行是否符合标准：
        bool changed = false;
        string s;
        cppfile.seekg(0);
        getline(cppfile, s);
        bool lineUsed = false;

        for(int line = CPPLINE1; cppfile.good() && line <= INCLUDE; ++line) {
            if(startsWith(s, part[line])) {
                newcpp << s << endl;
                lineUsed = true;
                if(getline(cppfile, s))
                    lineUsed = false;
            } else {
                newcpp << part[line] << endl;
                changed = true;
                lineUsed = false;
            }
        }

        // 拷贝文件剩余内容
        if(!lineUsed)
            newcpp << s << endl;
        newcpp << cppfile.rdbuf();

        // 如果有更改，则覆盖文件：
        if(changed) {
            existcpp.close();
            ofstream newCPP(part[IMPLEMENT].c_str());
            assure(newCPP, part[IMPLEMENT].c_str());
            newCPP << "//@//\n" // 变更标记
                   << newcpp.str();
        }
    }
}

int main(int argc, char* argv[]) {
    if(argc > 1)
        cppCheck(argv[1]);
    else
        cppCheck("cppCheckTest.h");
} ///:~
