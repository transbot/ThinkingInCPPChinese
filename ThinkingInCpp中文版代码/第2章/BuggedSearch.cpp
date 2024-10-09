//: C02:BuggedSearch.cpp {-xo}
//{L} ../TestSuite/Test
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <fstream>
#include "../TestSuite/Test.h"
using namespace std;

// 这个函数是唯一有bug的函数
int* binarySearch(int* beg, int* end, int what) {
    while (end - beg != 1) {
        if (*beg == what) return beg;
        int mid = (end - beg) / 2;
        if (what <= beg[mid]) end = beg + mid;
        else beg = beg + mid;
    }
    return 0; // 返回0表示未找到目标值
}

class BinarySearchTest : public TestSuite::Test {
public:
    enum { SZ = 10 };   // 把data数组的大小固定为10
    int* data;
    int max;            // 最大数字
    int current;        // 当前不包含的数字，在notContained()中使用

    // 查找数组中不包含的下一个数字 
    int notContained() {
        while (data[current] + 1 == data[current + 1]) {
            ++current;
        }
        if (current >= SZ) return max + 1;
        int retValue = data[current++] + 1;
        return retValue;
    }

    void setData() {
        data = new int[SZ];
        assert(!max); // 在调用setData()函数之前，max应该被初始化为0，遂有此断言
        // 创建一个包含递增值的数组。
        // 本例会随机决定增量。换言之，每次循环，都会随机决定max是递增1还是递增2。
        for(int i = 0; i < SZ; rand() % 2 == 0 ? max += 1 : max += 2) {
            data[i++] = max;
        }
    }

    void testInBound() {
        // 测试二叉查找函数binarySearch在数组边界内的正确性
        // 1. 测试数组中的所有元素：
        //    * 从数组末尾开始，逐个元素进行二叉查找
        //    * 由于元素一定在数组中，因此查找结果应该为true
        for (int i = SZ; --i >= 0;) {
            test_(binarySearch(data, data + SZ, data[i]));
        }
        // 2. 测试不在数组中的元素：
        //    * 循环获取不在数组中的元素
        //    * 对这些元素进行二叉查找，结果应该为false
        for (int i = notContained(); i < max; i = notContained()) {
            test_(!binarySearch(data, data + SZ, i));
        }
    }

    void testOutBounds() {
        // 测试二叉查找函数binarySearch在数组边界外的正确性
        // 1. 测试比数组最小值小的值：
        //    * 从数组最小值的前一个值开始，递减到最小值减去100
        //    * 这些值一定不在数组中，因此查找结果应该为false
        for (int i = data[0]; --i > data[0] - 100;) {
            test_(!binarySearch(data, data + SZ, i));
        }
        // 2. 测试比数组最大值大的值：
        //    * 从数组最大值的后一个值开始，递增到最大值加100
        //    * 这些值一定不在数组中，因此查找结果应该为false 
        for (int i = data[SZ - 1]; ++i < data[SZ - 1] + 100;) {
            test_(!binarySearch(data, data + SZ, i));
        }
    }

public:
    BinarySearchTest() {
        max = current = 0;
    }

    void run() {
        setData();
        testInBound();
        testOutBounds();
        delete[] data;
    }
};

int main() {
    srand(time(0));
    BinarySearchTest t;
    t.run();
    return t.report();
} ///:~
