//: C05:OurMin2.cpp
// ������ģ�塱min�Ķ���
#include "OurMin2.h"
export template<typename T>
const T& min(const T& a, const T& b) {
    return (a < b) ? a : b;
}
