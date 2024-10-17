//: C04:Effector.cpp
// ���ԡ�C++���˼��, ��2��
// ���ߣ�Bruce Eckel & Chuck Allison��
// ���ߣ��ܾ�(bookzhou.com)
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// Jerry Schwarz�ġ�Ч��������effector��
#include <cassert>
#include <limits>  // Ϊ��ʹ��max()
#include <sstream>
#include <iostream>
#include <string>
using namespace std;

// �ضϲ�����ַ�����ǰ׺���֣�ָ����ȣ���
class Fixw {
    string str;
public:
    Fixw(const string& s, int width) : str(s, 0, width) {}
    friend ostream& operator<<(ostream& os, const Fixw& fw) {
        return os << fw.str;
    }
};

// �Զ�������ʽ��ӡһ�����֣�
typedef unsigned long ulong;

class Bin {
    ulong n;
public:
    Bin(ulong nn) { n = nn; }
    friend ostream& operator<<(ostream& os, const Bin& b) {
        const ulong ULMAX = numeric_limits<ulong>::max();
        ulong bit = ~(ULMAX >> 1); // �������λ
        while (bit) {
            os << (b.n & bit ? '1' : '0');
            bit >>= 1;
        }
        return os;
    }
};

int main() {
    string words = "Things that make us happy, make us wise";
    // ����ѭ��ÿ�ζ����ַ����н�ȥһ���ַ������ԭʼ�ַ����������̵ġ�ǰ׺��
    // ����ַ���������ȫ�Ǻ��ֺ�ȫ�Ǳ�㣬�뽫--i�޸ĳ�(i=i-2)
    for (int i = words.size(); --i >= 0;) {
        ostringstream s;
        s << Fixw(words, i);
        assert(s.str() == words.substr(0, i));
        cout << s.str() << endl;
    }

    ostringstream xs, ys;
    xs << Bin(0xCAFEBABEUL);
    assert(xs.str() == "1100""1010""1111""1110""1011""1010""1011""1110");
    cout << xs.str() << endl;

    ys << Bin(0x76543210UL);
    assert(ys.str() == "0111""0110""0101""0100""0011""0010""0001""0000");
    cout << ys.str() << endl;
} ///:~
