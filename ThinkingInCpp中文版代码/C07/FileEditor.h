//: C07:FileEditor.h
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 一个文件编辑器
#ifndef FILEEDITOR_H
#define FILEEDITOR_H
#include <iostream>
#include <string>
#include <vector>

class FileEditor : public std::vector<std::string> {
public:
    void open(const char* filename);
    FileEditor(const char* filename) { open(filename); }
    FileEditor() {};
    void write(std::ostream& out = std::cout);
};
#endif // FILEEDITOR_H ///:~
