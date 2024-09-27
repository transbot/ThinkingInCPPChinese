#include <iostream>
#include <string>

class Exception {
public:
    virtual void printMessage() const = 0;
    virtual ~Exception() = default;
};

class FileException : public Exception {
public:
    FileException(const std::string& message) : message_(message) {}
    void printMessage() const override {
        std::cerr << "File error: " << message_ << std::endl;
    }

private:
    std::string message_;
};

class IOException : public Exception {
public:
    IOException() = default; // 添加默认构造函数
    IOException(const std::string& message) : message_(message) {}
    void printMessage() const override {
        std::cerr << "IO error: " << message_ << std::endl;
    }

private:
    std::string message_;
};

// 解决多重继承二义性问题
class FileNotFoundException : public FileException, public IOException {
public:
    FileNotFoundException(const std::string& filename) : FileException("File not found: " + filename), IOException("File not found: " + filename) {}
};

int main() {
    Exception* e1 = static_cast<Exception*>(new FileNotFoundException("data.txt"));
    e1->printMessage(); // 这里会调用 FileNotFoundException 的 printMessage() 方法

    // 使用 dynamic_cast 进行类型安全转换
    FileException* e2 = dynamic_cast<FileException*>(e1);
    if (e2) {
        e2->printMessage(); // 这里会调用 FileException 的 printMessage() 方法
    } else {
        std::cerr << "类型转换失败" << std::endl;
    }

    delete e1;
    return 0;
}