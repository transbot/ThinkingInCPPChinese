//: C09:Vendor.h
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��Ӧ���ṩ�����ͷ�ļ�
// ����ֻ���õ�������Լ�������Vendor.obj
#ifndef VENDOR_H
#define VENDOR_H

class Vendor {
public:
    virtual void v() const;
    void f() const; // ����ϣ���������...
    ~Vendor();      // ��ѽ��������ģ�
};

class Vendor1 : public Vendor {
public:
    void v() const;
    void f() const;
    ~Vendor1();
};

void A(const Vendor&);
void B(const Vendor&);
// �ȵ�...
#endif // VENDOR_H ///:~
