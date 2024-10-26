//: C05:TemplateFunctionAddress.cpp {-mwcc}
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ȡ��ģ�����ɵĺ����ĵ�ַ

template<typename T> void f(T*) {}

void h(void (*pf)(int*)) {}

template<typename T> void g(void (*pf)(T*)) {}

int main() {
    h(&f<int>);      // ��ȫ�����޶�
    h(&f);           // �����ƶ�
    g<int>(&f<int>); // ���������޶�
    g(&f<int>);      // �����ƶ�
    g<int>(&f);      // ���֣����㹻�ģ��޶�
}
