//: C04:Cppcheck.cpp
// ���ԡ�C++���˼��, ��2��
// ���ߣ�Bruce Eckel & Chuck Allison
// ���ߣ��ܾ�(bookzhou.com)
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ����.h��.cpp�ļ���ʹ֮������ʽ��׼��
// ���������ļ���ȷ�����ϱ�׼��
#include <fstream>
#include <sstream>
#include <string>
#include <cstddef>
#include "../require.h"
using namespace std;

bool startsWith(const string& base, const string& key) {
    return base.compare(0, key.size(), key) == 0;
}

void cppCheck(string fileName) {
    enum bufs { BASE, HEADER, IMPLEMENT, HLINE1, GUARD1,
        GUARD2, GUARD3, CPPLINE1, INCLUDE, BUFNUM };
    string part[BUFNUM];

    part[BASE] = fileName;

    // �����ַ����е�'.'
    size_t loc = part[BASE].find('.');
    if(loc != string::npos)
        part[BASE].erase(loc); // ȥ����չ��

    // ǿ��ת��Ϊ��д��
    for(size_t i = 0; i < part[BASE].size(); i++)
        part[BASE][i] = toupper(part[BASE][i]);

    // �����ļ������ļ��ڲ��Ĵ����У�
    part[HEADER] = part[BASE] + ".h";
    part[IMPLEMENT] = part[BASE] + ".cpp";
    part[HLINE1] = "//" ": " + part[HEADER];
    part[GUARD1] = "#ifndef " + part[BASE] + "_H";
    part[GUARD2] = "#define " + part[BASE] + "_H";
    part[GUARD3] = "#endif // " + part[BASE] +"_H";
    part[CPPLINE1] = string("//") + ": " + part[IMPLEMENT];
    part[INCLUDE] = "#include \"" + part[HEADER] + "\"";

    // ���ȣ����Դ����е��ļ���
    ifstream existh(part[HEADER].c_str()),
             existcpp(part[IMPLEMENT].c_str());

    if(!existh) { // �ļ������ڣ�������
        ofstream newheader(part[HEADER].c_str());
        assure(newheader, part[HEADER].c_str());
        newheader << part[HLINE1] << endl
                  << part[GUARD1] << endl
                  << part[GUARD2] << endl << endl
                  << part[GUARD3] << endl;
    } else { // �ļ��Ѵ��ڣ���֤��
        stringstream hfile; // д��Ͷ�ȡ
        ostringstream newheader; // д��
        hfile << existh.rdbuf(); // ���ǰ�����Ƿ���ϱ�׼��
        bool changed = false;
        string s;
        hfile.seekg(0);
        getline(hfile, s);
        bool lineUsed = false;

        // ��good()�ĵ�����Ϊ�˼���Microsoft�ı���������ͬ��:
        for(int line = HLINE1; hfile.good() && line <= GUARD2; ++line) {
            if(startsWith(s, part[line])) {
                newheader << s << endl;
                lineUsed = true;
                if(getline(hfile, s))
                    lineUsed = false;
            } else {
                newheader << part[line] << endl;
                changed = true;
                lineUsed = false;
            }
        }

        // �����ļ�ʣ������
        if(!lineUsed)
            newheader << s << endl;
        newheader << hfile.rdbuf();

        // ���GUARD3
        string head = hfile.str();
        if(head.find(part[GUARD3]) == string::npos) {
            newheader << part[GUARD3] << endl;
            changed = true;
        }

        // ����б�����򸲸��ļ���
        if(changed) {
            existh.close();
            ofstream newH(part[HEADER].c_str());
            assure(newH, part[HEADER].c_str());
            newH << "//@//\n" // ������
                 << newheader.str();
        }
    }

    if(!existcpp) { // ���� .cpp �ļ�
        ofstream newcpp(part[IMPLEMENT].c_str());
        assure(newcpp, part[IMPLEMENT].c_str());
        newcpp << part[CPPLINE1] << endl
               << part[INCLUDE] << endl;
    } else { // �ļ��Ѵ��ڣ���֤��
        stringstream cppfile;
        ostringstream newcpp;
        cppfile << existcpp.rdbuf(); // ���ǰ�����Ƿ���ϱ�׼��
        bool changed = false;
        string s;
        cppfile.seekg(0);
        getline(cppfile, s);
        bool lineUsed = false;

        for(int line = CPPLINE1; cppfile.good() && line <= INCLUDE; ++line) {
            if(startsWith(s, part[line])) {
                newcpp << s << endl;
                lineUsed = true;
                if(getline(cppfile, s))
                    lineUsed = false;
            } else {
                newcpp << part[line] << endl;
                changed = true;
                lineUsed = false;
            }
        }

        // �����ļ�ʣ������
        if(!lineUsed)
            newcpp << s << endl;
        newcpp << cppfile.rdbuf();

        // ����и��ģ��򸲸��ļ���
        if(changed) {
            existcpp.close();
            ofstream newCPP(part[IMPLEMENT].c_str());
            assure(newCPP, part[IMPLEMENT].c_str());
            newCPP << "//@//\n" // ������
                   << newcpp.str();
        }
    }
}

int main(int argc, char* argv[]) {
    if(argc > 1)
        cppCheck(argv[1]);
    else
        cppCheck("cppCheckTest.h");
} ///:~
