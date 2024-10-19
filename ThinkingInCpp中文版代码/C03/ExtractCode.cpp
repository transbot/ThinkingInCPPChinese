//: C03:ExtractCode.cpp {-edg} {RunByHand}
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ȡȫ���ĸ��еĴ���
#include <cassert>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// �ɵķǱ�׼Cͷ�ļ���Ϊ��ʹ��mkdir()
#if defined(__GNUC__) || defined(__MWERKS__)
#include <sys/stat.h>
#elif defined(__BORLANDC__) || defined(_MSC_VER) \
    || defined(__DMC__)
#include <direct.h>
#else
#error ��֧�ֵı�����
#endif

// ���Ŀ¼�Ƿ���ڣ�������
// ���������ڴ����ļ����������
bool exists(string fname) {
    size_t len = fname.length();
    if (fname[len-1] != '/' && fname[len-1] != '\\')
        fname.append("/");
    fname.append("000.tmp");
    ofstream outf(fname.c_str());
    bool existFlag = outf.is_open();
    if (outf) {
        outf.close();
        remove(fname.c_str());
    }
    return existFlag;
}

int main(int argc, char* argv[]) {
    // ����Ƿ�ָ���������ļ���
    if (argc == 1) {
        cerr << "�÷�: extractCode �ļ� [Ŀ¼]" << endl;
        exit(EXIT_FAILURE);
    }

    // ���ָ���������ļ��Ƿ����
    ifstream inf(argv[1]);
    if (!inf) {
        cerr << "���ļ�ʧ��: " << argv[1] << endl;
        exit(EXIT_FAILURE);
    }

    // ����Ƿ��ṩ�˿�ѡ�����Ŀ¼
    string root("./"); // Ĭ��Ϊ��ǰĿ¼
    if (argc == 3) {
        // ���ָ�������Ŀ¼�Ƿ����
        root = argv[2];
        if (!exists(root)) {
            cerr << "�����ڴ�Ŀ¼: " << root << endl;
            exit(EXIT_FAILURE);
        }
        size_t rootLen = root.length();
        if (root[rootLen-1] != '/' && root[rootLen-1] != '\\')
            root.append("/");
    }

    // ���ж�ȡ�����ļ�������
    // �����붨�����
    string line;
    bool inCode = false;
    bool printDelims = true;
    ofstream outf;
    while (getline(inf, line)) {
        size_t findDelim = line.find("//" "/:~");
        if (findDelim != string::npos) {
            // ������һ�в��ر��ļ�
            if (!inCode) {
                cerr << "��˳�����" << endl;
                exit(EXIT_FAILURE);
            }
            assert(outf);
            if (printDelims)
                outf << line << endl;
            outf.close();
            inCode = false;
            printDelims = true;
        } else {
            findDelim = line.find("//" ":");
            if (findDelim == 0) {
                // ���'!'ָ��
                if (line[3] == '!') {
                    printDelims = false;
                    ++findDelim; // Ϊ��һ����������'!'
                }
                // ��ȡ��Ŀ¼���ƣ�����еĻ�
                size_t startOfSubdir = line.find_first_not_of(" \t", findDelim+3);
                findDelim = line.find(':', startOfSubdir);
                if (findDelim == string::npos) {
                    cerr << "ȱ���ļ�����Ϣ\n" << endl;
                    exit(EXIT_FAILURE);
                }
                string subdir;
                if (findDelim > startOfSubdir)
                    subdir = line.substr(startOfSubdir, findDelim - startOfSubdir);
                // ��ȡ�ļ�����Ӧ����һ������
                size_t startOfFile = findDelim + 1;
                size_t endOfFile = line.find_first_of("\t", startOfFile);
                if (endOfFile == startOfFile) {
                    cerr << "ȱ���ļ���" << endl;
                    exit(EXIT_FAILURE);
                }
                // �����ѻ����������Ϣ����ʼ��������·������
                string fullPath(root);
                if (subdir.length() > 0)
                    fullPath.append(subdir).append("/");
                assert(fullPath[fullPath.length()-1] == '/');
                if (!exists(fullPath))
#if defined(__GNUC__) || defined(__MWERKS__)
                    mkdir(fullPath.c_str(), 0); // ������Ŀ¼
#else
                    mkdir(fullPath.c_str()); // ������Ŀ¼
#endif
                fullPath.append(line.substr(startOfFile, endOfFile - startOfFile));
                outf.open(fullPath.c_str());
                if (!outf) {
                    cerr << "�� " << fullPath << " �������ʱʧ��" << endl;
                    exit(EXIT_FAILURE);
                }
                inCode = true;
                cout << "���ڴ��� " << fullPath << endl;
                if (printDelims)
                    outf << line << endl;
            } else if (inCode) {
                assert(outf);
                outf << line << endl; // ����м�Ĵ�����
            }
        }
    }
    exit(EXIT_SUCCESS);
}
///:~
