/*
��size_t(-1)����ǰƽ̨�����޷���������д��һ���ı��ļ�1 000 000 �Ρ��ظ���һ���̣�����ΰ���д��һ���������ļ����Ƚ��������ļ��Ĵ�С������ʹ�ö����Ƹ�ʽ�ܽ�ʡ���ٿռ䡣������ȹ���һ���Լ���ƽ̨���ܽ�ʡ���ٿռ䣬�ٺͳ�������н���Աȡ���
*/

#include <iostream>
#include <fstream>

int main() {

	std::ofstream bin("ex11.bin", std::ios::binary);
	std::ofstream txt("ex11.txt", std::ios::out);

	size_t z = size_t(-1);

	for (int i = 0; i < 1'000'000; ++i) {
		txt << z;
		bin.write(reinterpret_cast<const char*>(&z), sizeof(z));
	}

return 0;
}
