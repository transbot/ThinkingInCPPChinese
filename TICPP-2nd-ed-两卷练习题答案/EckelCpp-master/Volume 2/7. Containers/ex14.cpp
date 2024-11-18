/*
Create an iterator class called BitBucket that just absorbs whatever you send to 
it without writing it anywhere.
*/

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

template<class InputIter, class _Tp>
class BitBucket : public std::iterator<
    std::input_iterator_tag, _Tp, std::ptrdiff_t> {
  InputIter first;
  _Tp t;
public:
  BitBucket(InputIter begin)
    : first(begin){}
  BitBucket() : first(NULL) {} // End sentinel
  // Prefix increment:
  BitBucket& operator++() {
    first++;
    return *this;
  }
  BitBucket operator++(int) {
    BitBucket b = *this;
    ++first;
    return b;
  }  
  _Tp& operator *() { return t; }
  bool operator == ( const BitBucket&b ) const{ return first == b.first; } 
  bool operator != ( const BitBucket&b ) const{ return !(*this==b); }
};

struct RandGen {
  int operator()() { return std::rand() %20; }
};
int main(int argc, char**argv) {
  vector<int> v;
  generate_n(back_inserter(v),10,RandGen());
  BitBucket<vector<int>::iterator,int> b1(v.begin()),b2(v.end());
  while (b1!=b2) *b1++ = 13;
  copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
  return 0; 
} 