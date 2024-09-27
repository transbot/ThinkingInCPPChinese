//: C11:FixedDiningPhilosophers.cpp {RunByHand}
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Dining Philosophers without Deadlock.
//{L} ZThread
#include <ctime>
#include "DiningPhilosophers.h"
#include "zthread/ThreadedExecutor.h"
using namespace ZThread;
using namespace std;

int main(int argc, char* argv[]) {
  srand(time(0)); // Seed the random number generator
  int ponder = argc > 1 ? atoi(argv[1]) : 5;
  cout << "Press <ENTER> to quit" << endl;
  enum { SZ = 5 };
  try {
    CountedPtr<Display> d(new Display);
    ThreadedExecutor executor;
    Chopstick c[SZ];
    for(int i = 0; i < SZ; i++) {
      if(i < (SZ-1))
        executor.execute(
          new Philosopher(c[i], c[i + 1], d, i, ponder));
      else
        executor.execute(
          new Philosopher(c[0], c[i], d, i, ponder));
    }
    cin.get();
    executor.interrupt();
    executor.wait();
  } catch(Synchronization_Exception& e) {
    cerr << e.what() << endl;
  }
} ///:~
