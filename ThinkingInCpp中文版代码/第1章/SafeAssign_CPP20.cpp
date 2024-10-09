//: C01:SafeAssign_CPP20.cpp
#include <vector>
#include <iostream>
#include <memory>
#include <cstring>
#include <new>
#include <cstddef>
using namespace std;

// �����������ָ���Ա
class HasPointers {
    // һ�������������ݵľ����
    struct MyData {
        const char* theString;
        const int* theInts;
        size_t numInts;

        MyData(const char* pString, const int* pInts, size_t nInts)
            : theString(pString), theInts(pInts), numInts(nInts) {}
    };

private:
    std::unique_ptr<MyData> theData; // ʹ������ָ��

    // ��¡����
    static std::unique_ptr<MyData> clone(const char* otherString, const int* otherInts, size_t nInts) {
        char* newChars = new char[strlen(otherString) + 1];
        int* newInts;

        try {
            newInts = new int[nInts];
        } catch (bad_alloc&) {
            delete[] newChars;
            throw;
        }

        try {
            // ����ʹ�����Ե��������ͣ���˲����׳��쳣��
            // ���ǣ���ʹ�������ͣ�������׳��쳣��
            // ���ԣ�������try������ʾ������Ҳ�Ǳ������ص㣡��
            strcpy(newChars, otherString);
            for (size_t i = 0; i < nInts; ++i)
                newInts[i] = otherInts[i];
        } catch (...) {
            delete[] newInts;
            delete[] newChars;
            throw;
        }

        return std::unique_ptr<MyData>(new MyData(newChars, newInts, nInts));
    }

    static std::unique_ptr<MyData> clone(const MyData* otherData) {
        return clone(otherData->theString, otherData->theInts, otherData->numInts);
    }

    static void cleanup(const MyData* theData) {
        delete[] theData->theString;
        delete[] theData->theInts;
        delete theData;
    }

public:
    HasPointers(const char* someString, const int* someInts, size_t numInts)
        : theData(clone(someString, someInts, numInts)) {}

    HasPointers(const HasPointers& source)
        : theData(clone(source.theData.get())) {}

    HasPointers& operator=(const HasPointers& rhs) {
        if (this != &rhs) {
            theData = clone(rhs.theData.get());
        }
        return *this;
    }

    ~HasPointers() = default;

    friend std::ostream& operator<<(std::ostream& os, const HasPointers& obj) {
        os << obj.theData->theString << ": ";
        for (size_t i = 0; i < obj.theData->numInts; ++i)
            os << obj.theData->theInts[i] << ' ';
        return os;
    }
};

int main() {
    int someNums[] = { 1, 2, 3, 4 };
    size_t someCount = sizeof someNums / sizeof someNums[0];
    int someMoreNums[] = { 5, 6, 7 };
    size_t someMoreCount = sizeof someMoreNums / sizeof someMoreNums[0];

    HasPointers h1("���", someNums, someCount);
    HasPointers h2("�ټ�", someMoreNums, someMoreCount);

    std::cout << h1 << std::endl; // ���: 1 2 3 4
    h1 = h2;
    std::cout << h1 << std::endl; // �ټ�: 5 6 7

    return 0;
} ///:~