//: C07:AssocInserter.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ʹ��һ��insert_iterator��ʹfill_n()��generate_n()
// �ܹ����������һ��ʹ�á�
#include <iterator>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include "SimpleGenerators.h"

using namespace std;

int main() {
    set<int> s;
    // ��s�����10��47
    // ����set��ȥ�����ԣ���Ϊֻ����һ��47
    fill_n(inserter(s, s.begin()), 10, 47);

    // �ٲ���10��������ֵ����12��ʼ
    generate_n(inserter(s, s.begin()), 10, IncrGen<int>(12));
    copy(s.begin(), s.end(), ostream_iterator<int>(cout, "\n"));

    map<int, int> m;
    // ��m�����10����ֵ�ԣ���(90, 120)
    // m�еļ�Ӧ����Ψһ�ģ�����ظ��ļ�90ֻ�����һ��
    fill_n(inserter(m, m.begin()), 10, make_pair(90,120));

    // �ٲ���10����ֵ�ԣ�����3��ʼ������ֵ��9��ʼ�������μ�PairGen�Ķ��壩    
    generate_n(inserter(m, m.begin()), 10, PairGen<int, int>(3, 9));
    copy(m.begin(), m.end(), ostream_iterator<pair<int,int>>(cout, "\n"));
} ///:~
