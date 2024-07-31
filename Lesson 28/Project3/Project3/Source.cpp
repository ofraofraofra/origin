#include <iostream>
#include <fstream>
#include <memory>
#include <string>

enum class Type {
    Warning,
    Error,
    FatalError,
    Unknown
};

class LogMessage {
public:
    LogMessage(Type type, const std::string& message)
        : type_(type), message_(message) {}

    Type type() const { return type_; }
    const std::string& message() const { return message_; }

private:
    Type type_;
    std::string message_;
};

class LogHandler {
public:
    virtual ~LogHandler() = default;

    void setNext(std::shared_ptr<LogHandler> next) {
        next_ = next;
    }

    void handle(const LogMessage& message) {
        if (canHandle(message)) {
            process(message);
        }
        else if (next_) {
            next_->handle(message);
        }
    }

protected:
    virtual bool canHandle(const LogMessage& message) = 0;
    virtual void process(const LogMessage& message) = 0;

private:
    std::shared_ptr<LogHandler> next_;
};

class FatalErrorHandler : public LogHandler {
protected:
    bool canHandle(const LogMessage& message) override {
        return message.type() == Type::FatalError;
    }

    void process(const LogMessage& message) override {
        throw std::runtime_error("Фатальная ошибка: " + message.message());
    }
};

class ErrorHandler : public LogHandler {
protected:
    bool canHandle(const LogMessage& message) override {
        return message.type() == Type::Error;
    }

    void process(const LogMessage& message) override {
        std::ofstream file("errors.log", std::ios::app);
        if (file.is_open()) {
            file << "Ошибка: " << message.message() << std::endl;
            file.close();
        }
        else {
            std::cerr << "Не удалось открыть файл для записи ошибок." << std::endl;
        }
    }
};

class WarningHandler : public LogHandler {
protected:
    bool canHandle(const LogMessage& message) override {
        return message.type() == Type::Warning;
    }

    void process(const LogMessage& message) override {
        std::cout << "Предупреждение: " << message.message() << std::endl;
    }
};

class UnknownMessageHandler : public LogHandler
{
protected:
    bool canHandle(const LogMessage& message) override {
        return message.type() == Type::Unknown;
    }

    void process(const LogMessage& message) override {
        throw std::runtime_error("Неизвестное сообщение: " + message.message());
    }
};

int main() {

    setlocale(LC_ALL, "ru");
    system("chcp 1251");
   
    auto fatalHandler = std::make_shared<FatalErrorHandler>();
    auto errorHandler = std::make_shared<ErrorHandler>();
    auto warningHandler = std::make_shared<WarningHandler>();
    auto unknownHandler = std::make_shared<UnknownMessageHandler>();

    fatalHandler->setNext(errorHandler);
    errorHandler->setNext(warningHandler);
    warningHandler->setNext(unknownHandler);

    try {
        LogMessage fatalMessage(Type::FatalError, "Системная ошибка.");
        fatalHandler->handle(fatalMessage);
    }
    catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    LogMessage errorMessage(Type::Error, "Ошибка ввода-вывода.");
    fatalHandler->handle(errorMessage);

    LogMessage warningMessage(Type::Warning, "Низкий уровень батареи.");
    fatalHandler->handle(warningMessage);

    LogMessage unknownMessage(Type::Unknown, "Неизвестный тип сообщения.");
    try {
        fatalHandler->handle(unknownMessage);
    }
    catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
}