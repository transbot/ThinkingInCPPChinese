//: C05:Exercise7.cpp {-xo}
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// �𰸣����벻�ܱ����ԭ�����ڣ�
// ��My���У���Ա����i��Ĭ�Ϸ���Ȩ����private��
// ����ζ��iֻ����My���ڲ����ʣ���play������Ȼ��My��ĳ�Ա������
// ������ͼ����һ��My�����޸�i���ⳬ����private��Ա�ķ��ʷ�Χ��
// ���Ա����ֻ�ܷ���ͬһ�������˽�г�Ա�����ܷ������������˽�г�Ա��
// ����������������ͬһ�����ʵ������������ʽ���������ַ��ʡ�

class Buddy {};

template<class T> class My {
  int i;
public:
  void play(My<Buddy>& s) {
    s.i = 3;
  }
};

int main() {
  My<int> h;
  My<Buddy> me, bud;
  h.play(bud);
  me.play(bud);
} ///:~
