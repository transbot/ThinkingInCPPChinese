/*
��size_t(-1)����ǰƽ̨�����޷���������д��һ���ı��ļ�1 000 000 �Ρ��ظ���һ���̣�����ΰ���д��һ���������ļ����Ƚ��������ļ��Ĵ�С������ʹ�ö����Ƹ�ʽ�ܽ�ʡ���ٿռ䡣������ȹ���һ���Լ���ƽ̨���ܽ�ʡ���ٿռ䣬�ٺͳ�������н���Աȡ���
*/

#include <iostream>
#include <fstream>
#include <cstdint>

int main() {
    std::ofstream bin("ex11.bin", std::ios::binary);
	std::ofstream txt("ex11.txt", std::ios::out);

	size_t z = size_t(-1);
    // �������ļ�д��
	for (int i = 0; i < 1'000'000; ++i) {
		txt << z;
		bin.write(reinterpret_cast<const char*>(&z), sizeof(z));
	}
    
    // �ر��ļ���ͳ�ƣ�����ȷ
    txt.close();
    bin.close();

    // �Ƚϲ���ʾ�ļ���С    
    std::ifstream text_file_size("ex11.txt", std::ios::ate | std::ios::binary);
    std::streampos text_size = text_file_size.tellg();
    text_file_size.close();

    std::ifstream binary_file_size("ex11.bin", std::ios::ate | std::ios::binary);
    std::streampos binary_size = binary_file_size.tellg();
    binary_file_size.close();

    std::cout << "�ı��ļ���С: " << text_size << " �ֽ�" << std::endl;
    std::cout << "�������ļ���С: " << binary_size << " �ֽ�" << std::endl;
    std::cout << "��ʡ�ռ�: " << (text_size - binary_size) << " �ֽ�" << std::endl;

    return 0;
}