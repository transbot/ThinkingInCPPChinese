//: C05:TemplateFunctionAddress.cpp {-mwcc}
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 获取从模板生成的函数的地址

template<typename T> void f(T*) {}

void h(void (*pf)(int*)) {}

template<typename T> void g(void (*pf)(T*)) {}

int main() {
    h(&f<int>);      // 完全类型限定
    h(&f);           // 类型推断
    g<int>(&f<int>); // 完整类型限定
    g(&f<int>);      // 类型推断
    g<int>(&f);      // 部分（但足够的）限定
}
