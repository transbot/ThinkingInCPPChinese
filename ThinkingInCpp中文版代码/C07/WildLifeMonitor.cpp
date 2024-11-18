//: C07:WildLifeMonitor.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
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
    int x, y;    // λ������
    time_t time; // ����ʱ��
public:
    DataPoint() : x(0), y(0), time(0) {}
    DataPoint(int xx, int yy, time_t tm) :
        x(xx), y(yy), time(tm) {}
    // �������Զ����ɵĿ������캯���͸�ֵ���������㹻�ˣ�
    // ����Ҫ�ֶ�������Щ������
    int getX() const { return x; }
    int getY() const { return y; }
    const time_t* getTime() const { return &time; }
};

string animal[] = {
    "������", "����", "��̡", "������", "����",
    "����", "��", "ӥ", "ӥ��", "����", "¹",
    "ˮ̡", "����"
};
const int ASZ = sizeof animal / sizeof *animal;
vector<string> animals(animal, animal + ASZ);

// ������Ϣ��������һ��Sighting���۲��¼���У������Է��͵������
typedef pair<string, DataPoint> Sighting;

ostream& operator<<(ostream& os, const Sighting& s) {
    return os << s.first << "��x= " << s.second.getX()
              << ", y= " << s.second.getY() << "�۲쵽, ʱ�� = "
              << ctime(s.second.getTime());
}

// Sighting������
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

// ��ʾ����˵��������û�ѡ��һ��������������ֵ
int menu() {
    cout << "��ѡ��һ�������'q'�˳�: ";
    for(size_t i = 0; i < animals.size(); i++)
        cout << '[' << i << ']' << animals[i] << ' ';
    cout << endl;
    string reply;
    cin >> reply;
    if(reply.at(0) == 'q') exit(0);
    istringstream r(reply);
    int i;
    r >> i; // ת��Ϊ����
    i %= animals.size();
    return i;
}

int main() {
    typedef multimap<string, DataPoint> DataMap;
    typedef DataMap::iterator DMIter;
    DataMap sightings;
    srand(time(0)); // �����
    generate_n(inserter(sightings, sightings.begin()),
               50, SightingGen(animals));

    // ��ӡ��������
    copy(sightings.begin(), sightings.end(),
         ostream_iterator<Sighting>(cout, ""));

    // ��ӡѡ����������й۲��¼
    for(int count = 1; count < 10; count++) {
        // ʹ�ò˵���ȡ�û���ѡ��
        // int i = menu();
        // ����ѡ������һ����������Խ����Զ������ԣ���        
        int i = rand() % animals.size();

        // ��equal_range���صĵ�����pair�У���һ����������ʾ
        // ƥ�䷶Χ����ʼλ�ã��ڶ�����������ʾƥ�䷶Χ�Ľ���λ��
        //�������һ��ƥ��Ԫ�ص���һ��λ�ã���
        pair<DMIter, DMIter> range =
            sightings.equal_range(animals[i]);
        copy(range.first, range.second,
             ostream_iterator<Sighting>(cout, ""));
    }
} ///:~
