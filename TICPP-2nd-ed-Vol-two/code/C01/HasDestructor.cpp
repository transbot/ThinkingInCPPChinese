//: C01:HasDestructor.cpp {O}
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
class HasDestructor {
public:
  ~HasDestructor() {}
};

void g(); // For all we know, g may throw.

void f() {
  HasDestructor h;
  g();
} ///:~
