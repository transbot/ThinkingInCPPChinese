/*
将size_t(-1)（当前平台最大的无符号整数）写入一个文本文件1 000 000 次。重复这一过程，但这次把它写入一个二进制文件。比较这两个文件的大小，看看使用二进制格式能节省多少空间。（最好先估算一下自己的平台上能节省多少空间，再和程序的运行结果对比。）
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
