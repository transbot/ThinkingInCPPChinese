//: C03:ExtractCode_CPP20.cpp {-edg} {RunByHand}
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 提取全书文稿中的代码，使用自C++17引入的filesystem库
#include <cassert>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

// 检查目录是否存在，做法是
// 尝试在其内打开新文件进行输出。
bool exists(string fname) {
    size_t len = fname.length();
    if (fname[len-1] != '/' && fname[len-1] != '\\')
        fname.append("/");
    fname.append("000.tmp");
    ofstream outf(fname.c_str());
    bool existFlag = outf.is_open();
    if (outf) {
        outf.close();
        remove(fname.c_str());
    }
    return existFlag;
}

int main(int argc, char* argv[]) {
    // 检查是否指定了输入文件名
    if (argc == 1) {
        cerr << "用法: extractCode 文件 [目录]" << endl;
        exit(EXIT_FAILURE);
    }

    // 检查指定的输入文件是否存在
    ifstream inf(argv[1]);
    if (!inf) {
        cerr << "打开文件失败: " << argv[1] << endl;
        exit(EXIT_FAILURE);
    }

    // 检查是否提供了可选的输出目录
    string root("./"); // 默认为当前目录
    if (argc == 3) {
        // 检查指定的输出目录是否存在
        root = argv[2];
        if (!exists(root)) {
            cerr << "不存在此目录: " << root << endl;
            exit(EXIT_FAILURE);
        }
        size_t rootLen = root.length();
        if (root[rootLen-1] != '/' && root[rootLen-1] != '\\')
            root.append("/");
    }

    // 逐行读取输入文件，并且
    // 检查代码定界符。
    string line;
    bool inCode = false;
    bool printDelims = true;
    ofstream outf;
    while (getline(inf, line)) {
        size_t findDelim = line.find("//" "/:~");
        if (findDelim != string::npos) {
            // 输出最后一行并关闭文件
            if (!inCode) {
                cerr << "行顺序错误" << endl;
                exit(EXIT_FAILURE);
            }
            assert(outf);
            if (printDelims)
                outf << line << endl;
            outf.close();
            inCode = false;
            printDelims = true;
        } else {
            findDelim = line.find("//" ":");
            if (findDelim == 0) {
                // 检查'!'指令
                if (line[3] == '!') {
                    printDelims = false;
                    ++findDelim; // 为下一次搜索跳过'!'
                }
                // 提取子目录名称，如果有的话
                size_t startOfSubdir = line.find_first_not_of(" \t", findDelim+3);
                findDelim = line.find(':', startOfSubdir);
                if (findDelim == string::npos) {
                    cerr << "缺少文件名信息\n" << endl;
                    exit(EXIT_FAILURE);
                }
                string subdir;
                if (findDelim > startOfSubdir)
                    subdir = line.substr(startOfSubdir, findDelim - startOfSubdir);
                // 提取文件名（应该有一个！）
                size_t startOfFile = findDelim + 1;
                size_t endOfFile = line.find_first_of("\t", startOfFile);
                if (endOfFile == startOfFile) {
                    cerr << "缺少文件名" << endl;
                    exit(EXIT_FAILURE);
                }
                // 现在已获得了所有信息，开始构建完整路径名称
                string fullPath(root);
                if (subdir.length() > 0)
                    fullPath.append(subdir).append("/");
                assert(fullPath[fullPath.length()-1] == '/');
                
                // 若目录不存在，就创建目录
                if (!fs::exists(fullPath))
                    fs::create_directories(fullPath); // 创建子目录

                fullPath.append(line.substr(startOfFile, endOfFile - startOfFile));
                outf.open(fullPath.c_str());
                if (!outf) {
                    cerr << "打开 " << fullPath << " 进行输出时失败" << endl;
                    exit(EXIT_FAILURE);
                }
                inCode = true;
                cout << "正在处理 " << fullPath << endl;
                if (printDelims)
                    outf << line << endl;
            } else if (inCode) {
                assert(outf);
                outf << line << endl; // 输出中间的代码行
            }
        }
    }
    exit(EXIT_SUCCESS);
}
///:~
