//: C05:TypenamedID.cpp {-bor}
// ���ԡ�C++���˼��, ��2��
// ���ߣ�Bruce Eckel & Chuck Allison
// ���ߣ��ܾ�(bookzhou.com)
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ʹ��typename��ΪǶ�����͵�ǰ׺��

template<class T> class X {
    // û��typename�Ļ�������ᱨ��
    typename T::id i;
public:
    void f() { i.g(); }
};

class Y {
public:
    class id {
    public:
        void g() {}
    };
};

int main() {
    X<Y> xy;
    xy.f();
} ///:~
