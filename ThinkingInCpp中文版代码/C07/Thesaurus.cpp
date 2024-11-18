//: C07:Thesaurus.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 在一个map中将string映射到vector
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

// 名称查找解决方案（必须放到std命名空间）
namespace std {
    ostream& operator<<(ostream& os, const TEntry& t) {
        os << t.first << ": ";
        copy(t.second.begin(), t.second.end(),
             ostream_iterator<string>(os, " "));
        return os;
    }
}

// 同义词词典测试数据项的生成器
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

// 请求要查找的“单词”
string menu(Thesaurus& thesaurus) {
    while(true) {
        cout << "选择一个\"单词\"，输入0退出: ";
        for(TIter it = thesaurus.begin();
            it != thesaurus.end(); it++)
            cout << (*it).first << ' ';
        cout << endl;
        string reply;
        cin >> reply;
        if(reply.at(0) == '0') exit(0); // 退出
        if(thesaurus.find(reply) == thesaurus.end())
            continue; // 不在列表中，再次尝试
        return reply;
    }
}

int main() {
    srand(time(0)); // 初始化随机数生成器
    Thesaurus thesaurus;

    // 填充10个数据项
    generate_n(inserter(thesaurus, thesaurus.begin()),
               10, ThesaurusGen());

    // 打印所有内容
    copy(thesaurus.begin(), thesaurus.end(),
         ostream_iterator<TEntry>(cout, "\n"));

    // 创建键的一个列表
    string keys[10];
    int i = 0;
    for(TIter it = thesaurus.begin();
        it != thesaurus.end(); it++)
        keys[i++] = (*it).first;
    for(int count = 0; count < 10; count++) {
        // 从控制台输入（临时注释掉以进行自动化测试）：
        // string reply = menu(thesaurus);
        // 随机生成一个选择：
        string reply = keys[rand() % 10];
        vector<string>& v = thesaurus[reply];
        copy(v.begin(), v.end(),
             ostream_iterator<string>(cout, " "));
        cout << endl;
    }
} ///:~
