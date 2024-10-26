//: C05:OurMin2.cpp
// “导出模板”min的定义
#include "OurMin2.h"
export template<typename T>
const T& min(const T& a, const T& b) {
    return (a < b) ? a : b;
}
