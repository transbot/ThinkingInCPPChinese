//: C06:Removing.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// �ӷ�Χ��ɾ����remove��Ԫ�ص��㷨
// {L} Generators
#include <algorithm>
#include <cctype>
#include <string>
#include "Generators.h"
#include "PrintSequence.h"
using namespace std;

// IsUpper�ṹ�嶨����һ����������Ҳ��Ϊ�º�����functor����
// �����ж�һ���ַ��Ƿ�Ϊ��д��ĸ��
struct IsUpper { 
    bool operator()(char c) { 
        return isupper(c); 
    } 
};

int main() { 
    std::srand(std::time(nullptr));  // �������������
    string v; 
    v.resize(25); 
    generate(v.begin(), v.end(), CharGen());  // ���ַ���v��������25���ַ�����Ϊ��ĸ��
    print(v.begin(), v.end(), "ԭʼ��v", "");  // ��ӡ�ַ���v������

    string us(v.begin(), v.end());  // �����µ��ַ���us����������v��ͬ
    sort(us.begin(), us.end());     // ��us��������

    // ʹ��unique��ɾ��us�е��ظ�Ԫ�أ�����ȡ�����еġ�ĩ�˺󡱵�����uend
    string::iterator it = us.begin(), cit = v.end(),
                          uend = unique(us.begin(), us.end()); 

    // �������б�����ɾ��ÿ����Ψһ����Ԫ�ء�
    // citָ�����remove���������γɵġ��߼�ĩβ����
    // Ҳ����˵��[v.begin(), cit)������δ��ɾ����Ԫ�أ�
    // ��[cit, v.end())�����˱�ɾ����Ԫ�أ���ЩԪ�ص�ֵ��δ����ģ���
    // ÿ��remove�����������cit��λ�á�
    while(it != uend) { 
        cit = remove(v.begin(), cit, *it); 
        print(v.begin(), v.end(), "������v", ""); 
        print(v.begin(), cit, "αv ", " ");
        cout << "ɾ����Ԫ��:\t" << *it << "\nαv�����һ��Ԫ��:\t" << *cit << endl << endl; 
        ++it; // �ƶ���us�е���һ��Ψһ�ַ�
    } 

    // ��������v������
    generate(v.begin(), v.end(), CharGen()); 
    print(v.begin(), v.end(), "v", ""); 

    // ʹ��remove_if�Ƴ����д�д��ĸ
    cit = remove_if(v.begin(), v.end(), IsUpper()); 
    print(v.begin(), cit, "ִ��remove_if IsUpper���v", " "); 

    // û����ʾremove()��remove_if()�ġ�copy���汾��
    // ��Ϊ�����Ƿǿ����汾�ļ򵥱��壬����Ӧ������ʾ��������⡣

    // ��ɾ��������ķ�Χ��������
    sort(v.begin(), cit); 
    print(v.begin(), cit, "������v", " "); 

    // ����һ���µ��ַ���v2����ʹ��unique_copyɾ���ظ�Ԫ��
    string v2; 
    v2.resize(cit - v.begin()); 
    unique_copy(v.begin(), cit, v2.begin()); 
    print(v2.begin(), v2.end(), "unique_copy", " "); 

    // ����ʹ��uniqueɾ���ظ�Ԫ�أ���ָ������ԱȽ�ν��
    cit = unique(v.begin(), cit, equal_to<char>()); 
    print(v.begin(), cit, "unique equal_to<char>", " "); 
} ///:~
