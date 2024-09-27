//: C01:HasDestructor.cpp {O}
class HasDestructor {
public:
    ~HasDestructor() {}
};

void g(); // 目前只知道可能抛出g

void f() {
    HasDestructor h;
    g();
} ///:~
