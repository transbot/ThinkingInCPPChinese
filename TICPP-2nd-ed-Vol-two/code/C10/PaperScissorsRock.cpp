//: C10:PaperScissorsRock.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
// Demonstration of multiple dispatching.
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "../purge.h"
using namespace std;

class Paper;
class Scissors;
class Rock;

enum Outcome { WIN, LOSE, DRAW };

ostream& operator<<(ostream& os, const Outcome out) {
  switch(out) {
    default:
    case WIN: return os << "win";
    case LOSE: return os << "lose";
    case DRAW: return os << "draw";
  }
}

class Item {
public:
  virtual Outcome compete(const Item*) = 0;
  virtual Outcome eval(const Paper*) const = 0;
  virtual Outcome eval(const Scissors*) const= 0;
  virtual Outcome eval(const Rock*) const = 0;
  virtual ostream& print(ostream& os) const = 0;
  virtual ~Item() {}
  friend ostream& operator<<(ostream& os, const Item* it) {
    return it->print(os);
  }
};

class Paper : public Item {
public:
  Outcome compete(const Item* it) { return it->eval(this);}
  Outcome eval(const Paper*) const { return DRAW; }
  Outcome eval(const Scissors*) const { return WIN; }
  Outcome eval(const Rock*) const { return LOSE; }
  ostream& print(ostream& os) const {
    return os << "Paper   ";
  }
};

class Scissors : public Item {
public:
  Outcome compete(const Item* it) { return it->eval(this);}
  Outcome eval(const Paper*) const { return LOSE; }
  Outcome eval(const Scissors*) const { return DRAW; }
  Outcome eval(const Rock*) const { return WIN; }
  ostream& print(ostream& os) const {
    return os << "Scissors";
  }
};

class Rock : public Item {
public:
  Outcome compete(const Item* it) { return it->eval(this);}
  Outcome eval(const Paper*) const { return WIN; }
  Outcome eval(const Scissors*) const { return LOSE; }
  Outcome eval(const Rock*) const { return DRAW; }
  ostream& print(ostream& os) const {
    return os << "Rock    ";
  }
};

struct ItemGen {
  Item* operator()() {
    switch(rand() % 3) {
      default:
      case 0: return new Scissors;
      case 1: return new Paper;
      case 2: return new Rock;
    }
  }
};

struct Compete {
  Outcome operator()(Item* a, Item* b) {
    cout << a << "\t" << b << "\t";
    return a->compete(b);
  }
};

int main() {
  srand(time(0)); // Seed the random number generator
  const int sz = 20;
  vector<Item*> v(sz*2);
  generate(v.begin(), v.end(), ItemGen());
  transform(v.begin(), v.begin() + sz,
    v.begin() + sz,
    ostream_iterator<Outcome>(cout, "\n"),
    Compete());
  purge(v);
} ///:~
