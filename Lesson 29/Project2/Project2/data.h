#pragma once

#include <string>
#include <fstream>

class HTMLPrintable
{
public:
    virtual ~HTMLPrintable() = default;
    virtual std::string printAsHTML() const = 0;
};

class TextPrintable
{
public:
    virtual ~TextPrintable() = default;
    virtual std::string printAsText() const = 0;
};

class JSONPrintable
{
public:
    virtual ~JSONPrintable() = default;
    virtual std::string printAsJSON() const = 0;
};

class Data
{
public:
    Data(std::string data) : data_(std::move(data)) {}
    virtual ~Data() = default;

protected:
    std::string data_;
};

class TextData : public Data, public TextPrintable
{
public:
    TextData(std::string data) : Data(std::move(data)) {}

    std::string printAsText() const override
    {
        return data_;
    }
};

class HTMLData : public Data, public HTMLPrintable
{
public:
    HTMLData(std::string data) : Data(std::move(data)) {}

    std::string printAsHTML() const override
    {
        return "<html>" + data_ + "</html>";
    }
};

class JSONData : public Data, public JSONPrintable
{
public:
    JSONData(std::string data) : Data(std::move(data)) {}

    std::string printAsJSON() const override
    {
        return "{ \"data\": \"" + data_ + "\" }";
    }
};

void saveTo(std::ofstream& file, const TextPrintable& printable)
{
    file << printable.printAsText();
}

void saveTo(std::ofstream& file, const HTMLPrintable& printable)
{
    file << printable.printAsHTML();
}

void saveTo(std::ofstream& file, const JSONPrintable& printable)
{
    file << printable.printAsJSON();
}

void saveToAsHTML(std::ofstream& file, const HTMLPrintable& printable) {
    saveTo(file, printable);
}

void saveToAsJSON(std::ofstream& file, const JSONPrintable& printable) {
    saveTo(file, printable);
}

void saveToAsText(std::ofstream& file, const TextPrintable& printable) {
    saveTo(file, printable);
}
