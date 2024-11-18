//: C07:FileEditor.h
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// һ���ļ��༭��
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
