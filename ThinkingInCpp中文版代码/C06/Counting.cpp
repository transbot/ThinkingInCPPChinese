//: C06:Counting.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// �����㷨
//{L} Generators
#include <algorithm>
#include <functional>
#include <iterator>
#include <set>
#include <vector>
#include <ctime> // Ϊ��ÿ�����ж���ò�ͬ�����������
#include "Generators.h"
#include "PrintSequence.h"
using namespace std;

int main() {
    // �������������
    std::srand(std::time(nullptr));  

    // �������50���ַ����������v
    vector<char> v;
    generate_n(back_inserter(v), 50, CharGen());
    print(v.begin(), v.end(), "v", "");

    // ��������v���ַ���һ�����ϣ������е������ַ������ظ�
    set<char> cs(v.begin(), v.end());
    typedef set<char>::iterator sci;

    // ���ռ���cs��ͳ������v��ÿ���ַ��ĳ��ִ���
    for(sci it = cs.begin(); it != cs.end(); it++) {
        int n = count(v.begin(), v.end(), *it);
        cout << *it << ": " << n << ", ";
    }

    // ͳ��Сд��ĸ�ж��ٸ�
    int lc = count_if(v.begin(), v.end(), bind2nd(greater<char>(), 'a'));
    cout << "\nСд��ĸ: " << lc << "��" << endl;

    // ������v�е�����ַ���������
    sort(v.begin(), v.end());
    print(v.begin(), v.end(), "�����", "");
} ///:~
