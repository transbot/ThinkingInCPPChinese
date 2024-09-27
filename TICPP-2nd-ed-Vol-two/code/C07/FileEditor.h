//: C07:FileEditor.h
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// A file editor tool.
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
