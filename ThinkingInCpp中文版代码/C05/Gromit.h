//: C05:Gromit.h
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// Gromit�����ߣ���һֻ�Ƽ�����techno-dog�������Ա�����ܻ�ȡ��ͬ������ʵ��
#include <iostream>
class Gromit {
    int arf;
    int totalBarks;
public:
    // ��Ա����arf����ʼ��Ϊarf + 1
    Gromit(int arf = 1) : arf(arf + 1), totalBarks(0) {}

    // �ð��߽У�����arf��������ֵ�������ж�����
    // ÿ�����������ʵ����ʱ��arfֵ�������ͬ������ "��! "
    void speak(int) {
        for(int i = 0; i < arf; i++) {
            std::cout << "��! ";
            ++totalBarks;
        }
        std::cout << std::endl;
    }

    // ģ�Ⱒ�߳Է�
    // const�����ú��������޸Ķ���ĳ�Ա����
    char eat(float) const {
        std::cout << "�ҳԳԳ�!" << std::endl;
        return 'z';
    }

    // ģ�Ⱒ��˯��
    // const�����ú��������޸Ķ���ĳ�Ա����
    int sleep(char, double) const {
        std::cout << "zzz..." << std::endl;
        return 0;
    }

    // ģ�Ⱒ������
    // const�����ú��������޸Ķ���ĳ�Ա����
    void sit() const {
        std::cout << "��������..." << std::endl;
    }
}; ///:~
