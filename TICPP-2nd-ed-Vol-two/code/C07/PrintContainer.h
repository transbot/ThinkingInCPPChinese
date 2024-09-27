//: C07:PrintContainer.h
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Prints a sequence container
#ifndef PRINT_CONTAINER_H
#define PRINT_CONTAINER_H
#include "../C06/PrintSequence.h"

template<class Cont>
void print(Cont& c, const char* nm = "",
           const char* sep = "\n",
           std::ostream& os = std::cout) {
  print(c.begin(), c.end(), nm, sep, os);
}
#endif ///:~
