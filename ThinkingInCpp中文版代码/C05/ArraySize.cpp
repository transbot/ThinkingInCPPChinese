//: C05:ArraySize.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
#include <cstddef>
using std::size_t;

template<size_t R, size_t C, typename T> 
void init1(T a[R][C]) { 
    for(size_t i = 0; i < R; ++i) 
        for(size_t j = 0; j < C; ++j) 
            a[i][j] = T(); 
}

template<size_t R, size_t C, class T> 
void init2(T (&a)[R][C]) { // ���ò��� 
    for(size_t i = 0; i < R; ++i) 
        for(size_t j = 0; j < C; ++j) 
            a[i][j] = T(); 
}

int main() { 
    int a[10][20]; 
    init1<10,20>(a); // ����ָ����С 
    init2(a);        // �Զ��ƶϴ�С
} ///:~
