//: C01:MyError.cpp {RunByHand}

class MyError {
    const char* const data;

public:
    MyError(const char* const msg = nullptr) : data(msg) {}
};

void f() {
    // ����������׳���һ���쳣����
    throw MyError("�����˲��õ�����");
}

int main() {
    // �Ժ�ὲ������Ҫ�������һ����try �顱��
    f();
} ///:~
