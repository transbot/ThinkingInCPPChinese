//: C07:WildLifeMonitor.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
#include <algorithm>
#include <cstdlib>
#include <cstddef>
#include <ctime>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class DataPoint {
    int x, y;    // 位置坐标
    time_t time; // 发现时间
public:
    DataPoint() : x(0), y(0), time(0) {}
    DataPoint(int xx, int yy, time_t tm) :
        x(xx), y(yy), time(tm) {}
    // 编译器自动生成的拷贝构造函数和赋值操作符就足够了，
    // 不需要手动定义这些函数。
    int getX() const { return x; }
    int getY() const { return y; }
    const time_t* getTime() const { return &time; }
};

string animal[] = {
    "花栗鼠", "海狸", "旱獭", "黄鼠狼", "松鼠",
    "雷鸟", "熊", "鹰", "鹰雕", "田鼠", "鹿",
    "水獭", "蜂鸟"
};
const int ASZ = sizeof animal / sizeof *animal;
vector<string> animals(animal, animal + ASZ);

// 所有信息都包含在一个Sighting（观察记录）中，它可以发送到输出流
typedef pair<string, DataPoint> Sighting;

ostream& operator<<(ostream& os, const Sighting& s) {
    return os << s.first << "在x= " << s.second.getX()
              << ", y= " << s.second.getY() << "观察到, 时间 = "
              << ctime(s.second.getTime());
}

// Sighting生成器
class SightingGen {
    vector<string>& animals;
    enum { D = 100 };
public:
    SightingGen(vector<string>& an) : animals(an) {}
    Sighting operator()() {
        Sighting result;
        int select = rand() % animals.size();
        result.first = animals[select];
        result.second = DataPoint(
            rand() % D, rand() % D, time(0));
        return result;
    }
};

// 显示动物菜单，允许用户选择一个，返回其索引值
int menu() {
    cout << "请选择一个动物或按'q'退出: ";
    for(size_t i = 0; i < animals.size(); i++)
        cout << '[' << i << ']' << animals[i] << ' ';
    cout << endl;
    string reply;
    cin >> reply;
    if(reply.at(0) == 'q') exit(0);
    istringstream r(reply);
    int i;
    r >> i; // 转换为整数
    i %= animals.size();
    return i;
}

int main() {
    typedef multimap<string, DataPoint> DataMap;
    typedef DataMap::iterator DMIter;
    DataMap sightings;
    srand(time(0)); // 随机化
    generate_n(inserter(sightings, sightings.begin()),
               50, SightingGen(animals));

    // 打印所有内容
    copy(sightings.begin(), sightings.end(),
         ostream_iterator<Sighting>(cout, ""));

    // 打印选定动物的所有观察记录
    for(int count = 1; count < 10; count++) {
        // 使用菜单获取用户的选择：
        // int i = menu();
        // 本例选择生成一个随机数（以进行自动化测试）：        
        int i = rand() % animals.size();

        // 在equal_range返回的迭代器pair中，第一个迭代器表示
        // 匹配范围的起始位置，第二个迭代器表示匹配范围的结束位置
        //（即最后一个匹配元素的下一个位置）。
        pair<DMIter, DMIter> range =
            sightings.equal_range(animals[i]);
        copy(range.first, range.second,
             ostream_iterator<Sighting>(cout, ""));
    }
} ///:~
