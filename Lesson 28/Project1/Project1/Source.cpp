#include <iostream>
#include <fstream>
#include <string>

class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};

class ConsoleLogCommand : public LogCommand {
public:
    void print(const std::string& message) override {
        std::cout << "�������: " << message << std::endl;
    }
};

class FileLogCommand : public LogCommand {
private:
    std::string filePath;
public:
    explicit FileLogCommand(const std::string& path) : filePath(path) {}

    void print(const std::string& message) override {
        std::ofstream outFile(filePath, std::ios::app);
        if (outFile.is_open()) {
            outFile << "����: " << message << std::endl;
            outFile.close();
        }
        else {
            std::cerr << "�� ������� ������� ����: " << filePath << std::endl;
        }
    }
};

void print(LogCommand& command, const std::string& message) {
    command.print(message);
}

int main() {

    setlocale(LC_ALL, "ru");
    system("chcp 1251");

    ConsoleLogCommand consoleLogger;
    FileLogCommand fileLogger("log.txt");

    print(consoleLogger, "��� ��������� ��� �������.");
    print(fileLogger, "��� ��������� ��� �����.");

}