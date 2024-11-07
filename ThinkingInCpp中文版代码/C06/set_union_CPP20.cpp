//: C06:set_union_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ʾset_union()
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a = {1, 2, 3, 3, 4};
    vector<int> b = {2, 2, 5, 6, 6};
    vector<int> result(a.size() + b.size());

    auto it = set_union(a.begin(), a.end(), b.begin(), b.end(), result.begin());

    // ��ӡ���
    for (auto it_result = result.begin(); it_result != it; ++it_result) {
        cout << *it_result << " ";
    }
    cout << endl;

    return 0;
}