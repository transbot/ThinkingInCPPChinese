//: C04:Showerr.cpp {RunByHand}
// ���ԡ�C++���˼��, ��2��
// ���ߣ�Bruce Eckel & Chuck Allison
// ���ߣ��ܾ�(bookzhou.com)
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ȡ�����д�����е�ע��
#include <cstddef>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "../require.h"
using namespace std;

const string USAGE =
    "�÷�: showerr filename chapnum\n"
    "���У�filename��C++Դ�ļ���\n"
    "chapnum�Ǹ��ļ������µı�š�\n"
    "���������//!��ʽ��ע���У�ɾ�������ǣ�\n"
    "������ĩ׷��һ������ŵ�ע�ͣ���//(#)�����У�# \n"
    "�������ļ��ж���Ψһ�ģ��Ա��ж�\n"
    "�������Ƿ���ָ���ļ��з����˴���\n"
    "ִ��showerr /r\n"
    "���������ȫ��Ψһ�ļ�������";

class Showerr {
    const int CHAP;
    const string MARKER, FNAME;
    // ���������ż��������ļ���
    const string ERRNUM;
    // ���������е��ļ���
    const string ERRFILE;
    stringstream edited; // �ѱ༭���ļ�
    int counter;

public:
    Showerr(const string& f, const string& en, const string& ef, int c)
        : CHAP(c), MARKER("//!"), FNAME(f), ERRNUM(en), ERRFILE(ef), counter(0) {}

    void replaceErrors() {
        ifstream infile(FNAME.c_str());
        assure(infile, FNAME.c_str());
        ifstream count(ERRNUM.c_str());
        if (count) count >> counter;
        int linecount = 1;
        string buf;
        ofstream errlines(ERRFILE.c_str(), ios::app);
        assure(errlines, ERRFILE.c_str());
        while (getline(infile, buf)) {
            // �������׵ı�ǣ�
            size_t pos = buf.find(MARKER);
            if (pos != string::npos) {
                // ɾ����ǣ�
                buf.erase(pos, MARKER.size() + 1);
                // ׷�Ӽ������ʹ�����Ϣ��
                ostringstream out;
                out << buf << " // (" << ++counter << ") "
                    << " �ºţ�" << CHAP
                    << " �ļ���" << FNAME
                    << " �У�" << linecount << endl;
                edited << out.str();
                errlines << out.str(); // �ڴ����ļ���׷������
            } else {
                edited << buf << "\n"; // ������
            }
            ++linecount;
        }
    }

    void saveFiles() {
        ofstream outfile(FNAME.c_str()); // ����
        assure(outfile, FNAME.c_str());
        outfile << edited.rdbuf();
        ofstream count(ERRNUM.c_str()); // ����
        assure(count, ERRNUM.c_str());
        count << counter; // �����µļ�����
    }
};

int main(int argc, char* argv[]) {
    const string ERRCOUNT("../errnum.txt"), ERRFILE("../errlines.txt");
    requireMinArgs(argc, 1, USAGE.c_str());
    if (argv[1][0] == '/' || argv[1][0] == '-') {
        // ����������Ӹ��࿪��ѡ��:
        switch (argv[1][1]) {
            case 'r': case 'R':
                cout << "���ü�����" << endl;
                remove(ERRCOUNT.c_str()); // ɾ���ļ�
                remove(ERRFILE.c_str());
                return EXIT_SUCCESS;
            default:
                cerr << USAGE << endl;
                return EXIT_FAILURE;
        }
    }

    if (argc == 3) {
        Showerr s(argv[1], ERRCOUNT, ERRFILE, atoi(argv[2]));
        s.replaceErrors();
        s.saveFiles();
    }
} ///:~
