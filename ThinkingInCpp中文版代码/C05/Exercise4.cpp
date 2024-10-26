//: C05:Exercise4.cpp {-xo}
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

class Noncomparable {};

template<class T>
struct SoftLogic {
    Noncomparable nc1, nc2;
    void noOp() {}
    void compare() {
        nc1 == nc2;
    }
};

struct HardLogic {
    Noncomparable nc1, nc2;
    void compare() {
       return nc1 == nc2; // �������
    }
};


int main() {
    SoftLogic<Noncomparable> l;
    l.noOp();
}
