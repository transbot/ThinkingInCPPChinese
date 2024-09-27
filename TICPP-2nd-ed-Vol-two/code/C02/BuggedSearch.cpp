//: C02:BuggedSearch.cpp {-xo}
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
//{L} ../TestSuite/Test
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <fstream>
#include "../TestSuite/Test.h"
using namespace std;

// This function is only one with bugs
int* binarySearch(int* beg, int* end, int what) {
  while(end - beg != 1) {
    if(*beg == what) return beg;
    int mid = (end - beg) / 2;
    if(what <= beg[mid]) end = beg + mid;
    else beg = beg + mid;
  }
  return 0;
}

class BinarySearchTest : public TestSuite::Test {
  enum { SZ = 10 };
  int* data;
  int max; // Track largest number
  int current; // Current non-contained number
               // Used in notContained()
  // Find the next number not contained in the array
  int notContained() {
    while(data[current] + 1 == data[current + 1])
      ++current;
    if(current >= SZ) return max + 1;
    int retValue = data[current++] + 1;
    return retValue;
  }
  void setData() {
    data = new int[SZ];
    assert(!max);
    // Input values with increments of one.  Leave
    // out some values on both odd and even indexes.
    for(int i = 0; i < SZ;
        rand() % 2 == 0 ? max += 1 : max += 2)
      data[i++] = max;
  }
  void testInBound() {
    // Test locations both odd and even
    // not contained and contained
    for(int i = SZ; --i >=0;)
      test_(binarySearch(data, data + SZ, data[i]));
    for(int i = notContained(); i < max;
        i = notContained())
      test_(!binarySearch(data, data + SZ, i));
  }
  void testOutBounds() {
    // Test lower values
    for(int i = data[0]; --i > data[0] - 100;)
      test_(!binarySearch(data, data + SZ, i));
    // Test higher values
    for(int i = data[SZ - 1];
        ++i < data[SZ -1] + 100;)
      test_(!binarySearch(data, data + SZ, i));
  }
public:
  BinarySearchTest() { max = current = 0; }
  void run() {
    setData();
    testInBound();
    testOutBounds();
    delete [] data;
  }
};

int main() {
  srand(time(0));
  BinarySearchTest t;
  t.run();
  return t.report();
} ///:~
