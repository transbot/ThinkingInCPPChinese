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
    IOException() = default; // ���Ĭ�Ϲ��캯��
    IOException(const std::string& message) : message_(message) {}
    void printMessage() const override {
        std::cerr << "IO error: " << message_ << std::endl;
    }

private:
    std::string message_;
};

// ������ؼ̳ж���������
class FileNotFoundException : public FileException, public IOException {
public:
    FileNotFoundException(const std::string& filename) : FileException("File not found: " + filename), IOException("File not found: " + filename) {}
};

int main() {
    Exception* e1 = static_cast<Exception*>(new FileNotFoundException("data.txt"));
    e1->printMessage(); // �������� FileNotFoundException �� printMessage() ����

    // ʹ�� dynamic_cast �������Ͱ�ȫת��
    FileException* e2 = dynamic_cast<FileException*>(e1);
    if (e2) {
        e2->printMessage(); // �������� FileException �� printMessage() ����
    } else {
        std::cerr << "����ת��ʧ��" << std::endl;
    }

    delete e1;
    return 0;
}