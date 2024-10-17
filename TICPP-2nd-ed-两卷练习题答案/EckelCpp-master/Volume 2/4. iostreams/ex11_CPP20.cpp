/*
将size_t(-1)（当前平台最大的无符号整数）写入一个文本文件1 000 000 次。重复这一过程，但这次把它写入一个二进制文件。比较这两个文件的大小，看看使用二进制格式能节省多少空间。（最好先估算一下自己的平台上能节省多少空间，再和程序的运行结果对比。）
*/

#include <iostream>
#include <fstream>
#include <cstdint>

int main() {
    std::ofstream bin("ex11.bin", std::ios::binary);
	std::ofstream txt("ex11.txt", std::ios::out);

	size_t z = size_t(-1);
    // 向两个文件写入
	for (int i = 0; i < 1'000'000; ++i) {
		txt << z;
		bin.write(reinterpret_cast<const char*>(&z), sizeof(z));
	}
    
    // 关闭文件再统计，更精确
    txt.close();
    bin.close();

    // 比较并显示文件大小    
    std::ifstream text_file_size("ex11.txt", std::ios::ate | std::ios::binary);
    std::streampos text_size = text_file_size.tellg();
    text_file_size.close();

    std::ifstream binary_file_size("ex11.bin", std::ios::ate | std::ios::binary);
    std::streampos binary_size = binary_file_size.tellg();
    binary_file_size.close();

    std::cout << "文本文件大小: " << text_size << " 字节" << std::endl;
    std::cout << "二进制文件大小: " << binary_size << " 字节" << std::endl;
    std::cout << "节省空间: " << (text_size - binary_size) << " 字节" << std::endl;

    return 0;
}