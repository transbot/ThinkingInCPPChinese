//: C10:LogFile.cpp {O}
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
#include "LogFile.h"
std::ofstream& logfile() {
  static std::ofstream log("Logfile.log");
  return log;
} ///:~
