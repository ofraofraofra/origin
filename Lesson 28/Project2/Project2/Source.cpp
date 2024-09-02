#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>


class Observer {
public:
    virtual void onWarning(const std::string& message) {}
    virtual void onError(const std::string& message) {}
    virtual void onFatalError(const std::string& message) {}
    virtual ~Observer() = default; 
};

class Subject {
private:
    std::vector<Observer*> observers; 

public:
    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void warning(const std::string& message) const {
        for (auto observer : observers) {
            observer->onWarning(message);
        }
    }

    void error(const std::string& message) const {
        for (auto observer : observers) {
            observer->onError(message);
        }
    }

    void fatalError(const std::string& message) const {
        for (auto observer : observers) {
            observer->onFatalError(message);
        }
    }
};


class WarningObserver : public Observer {
public:
    void onWarning(const std::string& message) override {
        std::cout << "Предупреждение: " << message << std::endl;
    }
};

class ErrorObserver : public Observer {
private:
    std::string filePath;

public:
    explicit ErrorObserver(const std::string& path) : filePath(path) {}

    void onError(const std::string& message) override {
        std::ofstream outFile(filePath, std::ios::app);
        if (outFile.is_open()) {
            outFile << "Ошибка: " << message << std::endl;
            outFile.close();
        }
        else {
            std::cerr << "Не удалось открыть файл: " << filePath << std::endl;
        }
    }
};

class FatalErrorObserver : public Observer {
private:
    std::string filePath;

public:
    explicit FatalErrorObserver(const std::string& path) : filePath(path) {}

    void onFatalError(const std::string& message) override {
        std::cout << "Фатальная ошибка: " << message << std::endl;
        std::ofstream outFile(filePath, std::ios::app);
        if (outFile.is_open()) {
            outFile << "Фатальная ошибка: " << message << std::endl;
            outFile.close();
        }
        else {
            std::cerr << "Не удалось открыть файл: " << filePath << std::endl;
        }
    }
};

int main() {

    setlocale(LC_ALL, "ru");
    system("chcp 1251");

    Subject subject;

    WarningObserver warningObserver;
    ErrorObserver errorObserver("errors.log");
    FatalErrorObserver fatalErrorObserver("fatal_errors.log");

    subject.addObserver(&warningObserver);
    subject.addObserver(&errorObserver);
    subject.addObserver(&fatalErrorObserver);

    subject.warning("Это предупреждение.");
    subject.error("Это ошибка.");
    subject.fatalError("Это фатальная ошибка.");

}