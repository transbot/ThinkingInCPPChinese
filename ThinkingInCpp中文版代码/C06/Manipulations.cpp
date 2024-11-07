//: C06:Manipulations.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ʾ�������в���
 //{L} Generators
// NString
#include <vector>
#include <string>
#include <functional> 
#include <algorithm>
#include "PrintSequence.h"
#include "NString.h"
#include "Generators.h"
using namespace std;

int main() {
    vector<int> v1(10);
    // ��������Ӧ�������У���ӡ���ɵ����У�����0-9��
    generate(v1.begin(), v1.end(), SkipGen());
    print(v1.begin(), v1.end(), "v1", " ");

    // ������v1һ����С����һ������v2
    vector<int> v2(v1.size());
    
    // ��v1�����һ��Ԫ�ؿ�ʼ�����򿽱���v2�����һ��λ�ã�
    // ֱ��v1�ĵ�һ��Ԫ�ر�������v2�ĵ�һ��λ�á�
    // ��ˣ�������v2�����ݽ���v1һ�¡�    
    copy_backward(v1.begin(), v1.end(), v2.end());
    print(v2.begin(), v2.end(), "copy_backward", " ");
    
    // ��תv1�����ݣ���������v2����ʼλ��
    reverse_copy(v1.begin(), v1.end(), v2.begin());
    print(v2.begin(), v2.end(), "reverse_copy", " ");
    
    // ԭ�ط�תv1������
    reverse(v1.begin(), v1.end());
    print(v1.begin(), v1.end(), "reverse", " ");
    
    int half = v1.size() / 2; // ʹ�ý����㷨ʱ����Χ����ȳ�
    // ����v1ǰ�벿�ֺͺ�벿�ֵ�����
    swap_ranges(v1.begin(), v1.begin() + half, v1.begin() + half);
    print(v1.begin(), v1.end(), "swap_ranges", " ");
    
    // ��һ���µ����п�ʼ
    generate(v1.begin(), v1.end(), SkipGen());
    print(v1.begin(), v1.end(), "v1", " ");
    
    // ��ʾ����ת�����汾1
    int third = v1.size() / 3;
    // ����ѭ����v1��ǰ����֮һ���ϡ���ת��������
    for(int i = 0; i < 10; i++) {
        rotate(v1.begin(), v1.begin() + third, v1.end());
        print(v1.begin(), v1.end(), "rotate", " ");
    }
    
    // ��ʾ"��ת"���汾2
    cout << "�ڶ�����תʾ��:" << endl;  
    char c[] = "ɽ��������һ�ȣ���ҹ��̵����ˡ�";
    const char CSZ = strlen(c);
    // ����ѭ�����ַ�����c��ǰ�����ַ���һ�����֣����ϡ���ת��������
    for(int i = 0; i < 10; i++) {
        rotate(c, c + 2, c + CSZ);
        print(c, c + CSZ, "", "");
    }
    
    // ���ɲ���ӡ"abcd"���е�����
    cout << "abcd������n!������:" << endl;
    int nf = 4 * 3 * 2 * 1; // ������ô��������
    char p[] = "abcd";    
    for(int i = 0; i < nf; i++) {
        next_permutation(p, p + 4);
        print(p, p + 4, "", "");
    }
    
    // ���ɲ���ӡ"abcd"���е����У�����Ϊʹ��prev_permutation
    cout << "ʹ��prev_permutation:" << endl;
    // ���ɲ���ӡ"abcd"�����С�ǰһ��������
    for(int i = 0; i < nf; i++) {
        prev_permutation(p, p + 4);
        print(p, p + 4, "", "");
    }
    
    // �������һ������:
    cout << "�������һ������:" << endl;
    string s("hello");
    cout << s << endl;
    // ��������ַ��� "hello" ����ӡ���
    for(int i = 0; i < 5; i++) {
        random_shuffle(s.begin(), s.end());
        cout << s << endl;
    }
    
    // NString��һ�֡�����ַ����������ټ�¼�����������ʵĳ��ִ������μ�6.3.1�ڣ�
    NString sa[] = { "a", "b", "c", "d", "a", "b", "c", "d",
                     "a", "b", "c", "d", "a", "b", "c"};
    const int SASZ = sizeof sa / sizeof *sa;
    vector<NString> ns(sa, sa + SASZ);
    print(ns.begin(), ns.end(), "ns", " ");
    
    // ʹ��partition��ns���з������������ǵ�һ������"b"��Ԫ��
    vector<NString>::iterator it = partition(ns.begin(), ns.end(),
                                             bind2nd(greater<NString>(), "b"));
    cout << "������: " << *it << endl;
    print(ns.begin(), ns.end(), "", " ");
    
    // ���¼�������
    copy(sa, sa + SASZ, ns.begin());

    // ʹ��stable_partition��ns���з������������ǵ�һ������"b"��Ԫ�أ�������ԭ�������˳��
    it = stable_partition(ns.begin(), ns.end(), bind2nd(greater<NString>(), "b"));
    cout << "�ȶ�����: " << endl;
    cout << "������: " << *it << endl;
    print(ns.begin(), ns.end(), "", " ");
}
///:~