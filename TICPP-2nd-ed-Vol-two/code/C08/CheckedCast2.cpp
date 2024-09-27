//: C08:CheckedCast2.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Uses RTTI's dynamic_cast.
#include <vector>
#include "../purge.h"
#include "Security.h"
using namespace std;

int main() {
  vector<Security*> portfolio;
  portfolio.push_back(new Metal);
  portfolio.push_back(new Investment);
  portfolio.push_back(new Bond);
  portfolio.push_back(new Stock);
  for(vector<Security*>::iterator it =
       portfolio.begin();
       it != portfolio.end(); ++it) {
    Investment* cm = dynamic_cast<Investment*>(*it);
    if(cm)
      cm->special();
    else
      cout << "not a Investment" << endl;
  }
  cout << "cast from intermediate pointer:" << endl;
  Security* sp = new Metal;
  Investment* cp = dynamic_cast<Investment*>(sp);
  if(cp) cout << "  it's an Investment" << endl;
  Metal* mp = dynamic_cast<Metal*>(sp);
  if(mp) cout << "  it's a Metal too!" << endl;
  purge(portfolio);
} ///:~
