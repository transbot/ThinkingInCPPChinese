//: C07:Thesaurus.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��һ��map�н�stringӳ�䵽vector
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

typedef map<string, vector<string> > Thesaurus;
typedef pair<string, vector<string> > TEntry;
typedef Thesaurus::iterator TIter;

// ���Ʋ��ҽ������������ŵ�std�����ռ䣩
namespace std {
    ostream& operator<<(ostream& os, const TEntry& t) {
        os << t.first << ": ";
        copy(t.second.begin(), t.second.end(),
             ostream_iterator<string>(os, " "));
        return os;
    }
}

// ͬ��ʴʵ�����������������
class ThesaurusGen {
    static const string letters;
    static int count;
public:
    int maxSize() { return letters.size(); }
    TEntry operator()() {
        TEntry result;
        if(count >= maxSize()) count = 0;
        result.first = letters[count++];
        int entries = (rand() % 5) + 2;
        for(int i = 0; i < entries; i++) {
            int choice = rand() % maxSize();
            char cbuf[2] = { 0 };
            cbuf[0] = letters[choice];
            result.second.push_back(cbuf);
        }
        return result;
    }
};

int ThesaurusGen::count = 0;
const string ThesaurusGen::letters("ABCDEFGHIJKL"
                                  "MNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

// ����Ҫ���ҵġ����ʡ�
string menu(Thesaurus& thesaurus) {
    while(true) {
        cout << "ѡ��һ��\"����\"������0�˳�: ";
        for(TIter it = thesaurus.begin();
            it != thesaurus.end(); it++)
            cout << (*it).first << ' ';
        cout << endl;
        string reply;
        cin >> reply;
        if(reply.at(0) == '0') exit(0); // �˳�
        if(thesaurus.find(reply) == thesaurus.end())
            continue; // �����б��У��ٴγ���
        return reply;
    }
}

int main() {
    srand(time(0)); // ��ʼ�������������
    Thesaurus thesaurus;

    // ���10��������
    generate_n(inserter(thesaurus, thesaurus.begin()),
               10, ThesaurusGen());

    // ��ӡ��������
    copy(thesaurus.begin(), thesaurus.end(),
         ostream_iterator<TEntry>(cout, "\n"));

    // ��������һ���б�
    string keys[10];
    int i = 0;
    for(TIter it = thesaurus.begin();
        it != thesaurus.end(); it++)
        keys[i++] = (*it).first;
    for(int count = 0; count < 10; count++) {
        // �ӿ���̨���루��ʱע�͵��Խ����Զ������ԣ���
        // string reply = menu(thesaurus);
        // �������һ��ѡ��
        string reply = keys[rand() % 10];
        vector<string>& v = thesaurus[reply];
        copy(v.begin(), v.end(),
             ostream_iterator<string>(cout, " "));
        cout << endl;
    }
} ///:~
