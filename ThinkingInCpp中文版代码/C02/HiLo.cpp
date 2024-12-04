//: C02:HiLo.cpp {RunByHand}
// 这个“猜大小”游戏利用了循环不变量
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "请想一个1到100之间的数字" << endl
         << "我会猜这个数；告诉我猜的数是太大(H)，还是太小(L)" << endl;
    int low = 1, high = 100; // 初始范围
    bool guessed = false;    // 是否猜中的标志
    
    while(!guessed) {
        // INVARIANT(不变量): 数字在范围[low, high]内
        if(low > high) { // 违反不变量
            cout << "你作弊！我不玩了！" << endl;
            return EXIT_FAILURE;
        }
        
        int guess = (low + high) / 2;
        cout << "我猜的数是" << guess << "。";
        cout << "(H)太大, (L)太小, 或者 (E)猜对了? ";
        string response;
        cin >> response;
        
        switch(toupper(response[0])) {
            case 'H':
            case 'h':
                high = guess - 1;
                break;
            case 'L':
            case 'l':
                low = guess + 1;
                break;
            case 'E':
            case 'e':
                guessed = true;
                break;
            default:
                cout << "无效回答" << endl;
                continue;
        }
    }
    
    cout << "我猜到了！" << endl;
    return EXIT_SUCCESS;
} ///:~
