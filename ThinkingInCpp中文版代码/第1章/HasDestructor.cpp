//: C01:HasDestructor.cpp {O}
class HasDestructor {
public:
    ~HasDestructor() {}
};

void g(); // Ŀǰֻ֪�������׳�g

void f() {
    HasDestructor h;
    g();
} ///:~
