//: :require.h
// ���ԡ�C++���˼��, ��2�桷
// ���ߣ�Bruce Eckel & Chuck Allison��
// ���ߣ��ܾ�(bookzhou.com)
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳhttps://bookzhou.com���ء�

// ���Գ����еĴ��������error conditions��
#ifndef REQUIRE_H
#define REQUIRE_H
#include <cstdio>
#include <cstdlib>
#include <fstream>

inline void require(bool requirement,
  const char* msg = "δ��������") {
  // �ɱ�����Ҫ��ֲ���"using namespace std":
  using namespace std;
  if(!requirement) {
    fputs(msg, stderr);
    fputs("\n", stderr);
    exit(EXIT_FAILURE);
  }
}

inline void requireArgs(int argc, int args,
  const char* msg = "�����ṩ%d��ʵ��") {
  using namespace std;
  if(argc != args + 1) {
    fprintf(stderr, msg, args);
    fputs("\n", stderr);
    exit(EXIT_FAILURE);
  }
}

inline void requireMinArgs(int argc, int minArgs,
  const char* msg = "������Ҫ�ṩ%d��ʵ��") {
  using namespace std;
  if(argc < minArgs + 1) {
    fprintf(stderr, msg, minArgs);
    fputs("\n", stderr);
    exit(EXIT_FAILURE);
  }
}

inline void assure(std::ifstream& in,
  const char* filename = "") {
  using namespace std;
  if(!in) {
    fprintf(stderr, "�޷����ļ�%s\n", filename);
    exit(EXIT_FAILURE);
  }
}

inline void assure(std::ofstream& in,
  const char* filename = "") {
  using namespace std;
  if(!in) {
    fprintf(stderr, "�޷����ļ�%s\n", filename);
    exit(EXIT_FAILURE);
  }
}

inline void assure(std::fstream& in,
  const char* filename = "") {
  using namespace std;
  if(!in) {
    fprintf(stderr, "�޷����ļ�%s\n", filename);
    exit(EXIT_FAILURE);
  }
}
#endif // REQUIRE_H ///:~
