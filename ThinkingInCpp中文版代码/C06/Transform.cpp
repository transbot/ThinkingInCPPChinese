//: C06:Transform.cpp {-mwcc}
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
// ʹ��STL transform()�㷨
//{L} Counted
#include <iostream>
#include <vector>
#include <algorithm>
#include "Counted.h"
using namespace std;

template<class T> T* deleteP(T* x) {
    delete x;
    return 0; // �ִ�C++����nullptr������ȷ
}

template<class T> struct Deleter {
    T* operator()(T* x) {
        delete x;
        return 0; // �ִ�C++����nullptr������ȷ
    }
};


int main() {
    CountedVector cv("��");
    transform(cv.begin(), cv.end(), cv.begin(), deleteP<Counted>);
    CountedVector cv2("��");
    transform(cv2.begin(), cv2.end(), cv2.begin(), Deleter<Counted>());
} ///:~
