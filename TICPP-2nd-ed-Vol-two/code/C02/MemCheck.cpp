//: C02:MemCheck.cpp {O}
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstddef>
using namespace std;
#undef new

// Global flags set by macros in MemCheck.h
bool traceFlag = true;
bool activeFlag = false;

namespace {

// Memory map entry type
struct Info {
  void* ptr;
  const char* file;
  long line;
};

// Memory map data
const size_t MAXPTRS = 10000u;
Info memMap[MAXPTRS];
size_t nptrs = 0;

// Searches the map for an address
int findPtr(void* p) {
  for(size_t i = 0; i < nptrs; ++i)
    if(memMap[i].ptr == p)
      return i;
  return -1;
}

void delPtr(void* p) {
  int pos = findPtr(p);
  assert(pos >= 0);
  // Remove pointer from map
  for(size_t i = pos; i < nptrs-1; ++i)
    memMap[i] = memMap[i+1];
  --nptrs;
}

// Dummy type for static destructor
struct Sentinel {
  ~Sentinel() {
    if(nptrs > 0) {
      printf("Leaked memory at:\n");
      for(size_t i = 0; i < nptrs; ++i)
        printf("\t%p (file: %s, line %ld)\n",
          memMap[i].ptr, memMap[i].file, memMap[i].line);
    }
    else
      printf("No user memory leaks!\n");
  }
};

// Static dummy object
Sentinel s;

} // End anonymous namespace

// Overload scalar new
void*
operator new(size_t siz, const char* file, long line) {
  void* p = malloc(siz);
  if(activeFlag) {
    if(nptrs == MAXPTRS) {
      printf("memory map too small (increase MAXPTRS)\n");
      exit(1);
    }
    memMap[nptrs].ptr = p;
    memMap[nptrs].file = file;
    memMap[nptrs].line = line;
    ++nptrs;
  }
  if(traceFlag) {
    printf("Allocated %u bytes at address %p ", siz, p);
    printf("(file: %s, line: %ld)\n", file, line);
  }
  return p;
}

// Overload array new
void*
operator new[](size_t siz, const char* file, long line) {
  return operator new(siz, file, line);
}

// Override scalar delete
void operator delete(void* p) {
  if(findPtr(p) >= 0) {
    free(p);
    assert(nptrs > 0);
    delPtr(p);
    if(traceFlag)
      printf("Deleted memory at address %p\n", p);
  }
  else if(!p && activeFlag)
    printf("Attempt to delete unknown pointer: %p\n", p);
}

// Override array delete
void operator delete[](void* p) {
  operator delete(p);
} ///:~
