//: C02:BuggedSearch.cpp {-xo}
//{L} ../TestSuite/Test
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <fstream>
#include "../TestSuite/Test.h"
using namespace std;

// ���������Ψһ��bug�ĺ���
int* binarySearch(int* beg, int* end, int what) {
    while (end - beg != 1) {
        if (*beg == what) return beg;
        int mid = (end - beg) / 2;
        if (what <= beg[mid]) end = beg + mid;
        else beg = beg + mid;
    }
    return 0; // ����0��ʾδ�ҵ�Ŀ��ֵ
}

class BinarySearchTest : public TestSuite::Test {
public:
    enum { SZ = 10 };   // ��data����Ĵ�С�̶�Ϊ10
    int* data;
    int max;            // �������
    int current;        // ��ǰ�����������֣���notContained()��ʹ��

    // ���������в���������һ������ 
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
        assert(!max); // �ڵ���setData()����֮ǰ��maxӦ�ñ���ʼ��Ϊ0�����д˶���
        // ����һ����������ֵ�����顣
        // �����������������������֮��ÿ��ѭ���������������max�ǵ���1���ǵ���2��
        for(int i = 0; i < SZ; rand() % 2 == 0 ? max += 1 : max += 2) {
            data[i++] = max;
        }
    }

    void testInBound() {
        // ���Զ�����Һ���binarySearch������߽��ڵ���ȷ��
        // 1. ���������е�����Ԫ�أ�
        //    * ������ĩβ��ʼ�����Ԫ�ؽ��ж������
        //    * ����Ԫ��һ���������У���˲��ҽ��Ӧ��Ϊtrue
        for (int i = SZ; --i >= 0;) {
            test_(binarySearch(data, data + SZ, data[i]));
        }
        // 2. ���Բ��������е�Ԫ�أ�
        //    * ѭ����ȡ���������е�Ԫ��
        //    * ����ЩԪ�ؽ��ж�����ң����Ӧ��Ϊfalse
        for (int i = notContained(); i < max; i = notContained()) {
            test_(!binarySearch(data, data + SZ, i));
        }
    }

    void testOutBounds() {
        // ���Զ�����Һ���binarySearch������߽������ȷ��
        // 1. ���Ա�������СֵС��ֵ��
        //    * ��������Сֵ��ǰһ��ֵ��ʼ���ݼ�����Сֵ��ȥ100
        //    * ��Щֵһ�����������У���˲��ҽ��Ӧ��Ϊfalse
        for (int i = data[0]; --i > data[0] - 100;) {
            test_(!binarySearch(data, data + SZ, i));
        }
        // 2. ���Ա��������ֵ���ֵ��
        //    * ���������ֵ�ĺ�һ��ֵ��ʼ�����������ֵ��100
        //    * ��Щֵһ�����������У���˲��ҽ��Ӧ��Ϊfalse 
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
