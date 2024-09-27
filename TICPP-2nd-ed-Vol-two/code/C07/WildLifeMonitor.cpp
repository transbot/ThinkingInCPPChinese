//: C07:WildLifeMonitor.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
#include <algorithm>
#include <cstdlib>
#include <cstddef>
#include <ctime>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class DataPoint {
  int x, y; // Location coordinates
  time_t time; // Time of Sighting
public:
  DataPoint() : x(0), y(0), time(0) {}
  DataPoint(int xx, int yy, time_t tm) :
    x(xx), y(yy), time(tm) {}
  // Synthesized operator=, copy-constructor OK
  int getX() const { return x; }
  int getY() const { return y; }
  const time_t* getTime() const { return &time; }
};

string animal[] = {
  "chipmunk", "beaver", "marmot", "weasel",
  "squirrel", "ptarmigan", "bear", "eagle",
  "hawk", "vole", "deer", "otter", "hummingbird",
};
const int ASZ = sizeof animal/sizeof *animal;
vector<string> animals(animal, animal + ASZ);

// All the information is contained in a
// "Sighting," which can be sent to an ostream:
typedef pair<string, DataPoint> Sighting;

ostream&
operator<<(ostream& os, const Sighting& s) {
  return os << s.first << " sighted at x= "
    << s.second.getX() << ", y= " << s.second.getY()
    << ", time = " << ctime(s.second.getTime());
}

// A generator for Sightings:
class SightingGen {
  vector<string>& animals;
  enum { D = 100 };
public:
  SightingGen(vector<string>& an) : animals(an) {}
  Sighting operator()() {
    Sighting result;
    int select = rand() % animals.size();
    result.first = animals[select];
    result.second = DataPoint(
      rand() % D, rand() % D, time(0));
    return result;
  }
};

// Display a menu of animals, allow the user to
// select one, return the index value:
int menu() {
  cout << "select an animal or 'q' to quit: ";
  for(size_t i = 0; i < animals.size(); i++)
    cout <<'['<< i <<']'<< animals[i] << ' ';
  cout << endl;
  string reply;
  cin >> reply;
  if(reply.at(0) == 'q') return 0;
  istringstream r(reply);
  int i;
  r >> i; // Converts to int
  i %= animals.size();
  return i;
}

int main() {
  typedef multimap<string, DataPoint> DataMap;
  typedef DataMap::iterator DMIter;
  DataMap sightings;
  srand(time(0));  // Randomize
  generate_n(inserter(sightings, sightings.begin()),
    50, SightingGen(animals));
  // Print everything:
  copy(sightings.begin(), sightings.end(),
    ostream_iterator<Sighting>(cout, ""));
  // Print sightings for selected animal:
  for(int count = 1; count < 10; count++) {
    // Use menu to get selection:
    // int i = menu();
    // Generate randomly (for automated testing):
    int i = rand() % animals.size();
    // Iterators in "range" denote begin, one
    // past end of matching range:
    pair<DMIter, DMIter> range =
      sightings.equal_range(animals[i]);
    copy(range.first, range.second,
      ostream_iterator<Sighting>(cout, ""));
  }
} ///:~
