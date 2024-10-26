//: C05:Exercise7.cpp {-xo}
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 答案：代码不能编译的原因在于：
// 在My类中，成员变量i的默认访问权限是private。
// 这意味着i只能在My类内部访问，而play函数虽然是My类的成员函数，
// 但它试图从另一个My对象修改i，这超出了private成员的访问范围。
// 类成员函数只能访问同一个对象的私有成员，不能访问其他对象的私有成员，
// 除非这两个对象是同一个类的实例并且类中显式地允许这种访问。

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
