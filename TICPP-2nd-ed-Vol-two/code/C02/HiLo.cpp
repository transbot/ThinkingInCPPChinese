//: C02:HiLo.cpp {RunByHand}
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
// Plays the game of Hi-Lo to illustrate a loop invariant.
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int main() {
  cout << "Think of a number between 1 and 100" << endl
        << "I will make a guess; "
        << "tell me if I'm (H)igh or (L)ow" << endl;
  int low = 1, high = 100;
  bool guessed = false;
  while(!guessed) {
    // Invariant: the number is in the range [low, high]
    if(low > high) {  // Invariant violation
      cout << "You cheated! I quit" << endl;
      return EXIT_FAILURE;
    }
    int guess = (low + high) / 2;
    cout << "My guess is " << guess << ". ";
    cout << "(H)igh, (L)ow, or (E)qual? ";
    string response;
    cin >> response;
    switch(toupper(response[0])) {
      case 'H':
        high = guess - 1;
        break;
      case 'L':
        low = guess + 1;
        break;
      case 'E':
        guessed = true;
        break;
      default:
        cout << "Invalid response" << endl;
        continue;
    }
  }
  cout << "I got it!" << endl;
  return EXIT_SUCCESS;
} ///:~
