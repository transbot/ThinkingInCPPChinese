//: C04:DataLogger.h
// ���ԡ�C++���˼��, ��2��
// ���ߣ�Bruce Eckel & Chuck Allison
// ���ߣ��ܾ�(bookzhou.com)
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// Datalogger����ļ�¼����
#ifndef DATALOG_H
#define DATALOG_H
#include <ctime>
#include <iosfwd>
#include <string>
using std::ostream;

struct Coord {
    int deg, min, sec;
    Coord(int d = 0, int m = 0, int s = 0) : deg(d), min(m), sec(s) {}
    std::string toString() const;
};

ostream& operator<<(ostream&, const Coord&);

class DataPoint {
    std::time_t timestamp;     // ʱ�������
    Coord latitude, longitude; // ��γ��
    double depth, temperature; // ��Ⱥ��¶�


public:
    DataPoint(std::time_t ts, const Coord& lat,
              const Coord& lon, double dep, double temp)
        : timestamp(ts), latitude(lat), longitude(lon),
            depth(dep), temperature(temp) {}

    DataPoint() : timestamp(0), depth(0), temperature(0) {}
    friend ostream& operator<<(ostream&, const DataPoint&);
};
#endif // DATALOG_H ///:~
