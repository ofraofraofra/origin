#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <stdexcept>

class ini_parser {
private:
    std::map<std::string, std::map<std::string, std::string>> data;

public:
    ini_parser(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Не удалось открыть файл: " + filename);
        }

        std::string line;
        std::string current_section;
        while (std::getline(file, line)) {
            line.erase(0, line.find_first_not_of(" \t"));
            line.erase(line.find_last_not_of(" \t") + 1);

            if (line.empty() || line[0] == ';') {
                continue;
            }

            if (line[0] == '[' && line[line.size() - 1] == ']') {
                current_section = line.substr(1, line.size() - 2);
            }
            else {
                std::istringstream iss(line);
                std::string key, value;
                if (std::getline(iss, key, '=')) {
                    if (std::getline(iss, value)) {
                        value.erase(0, value.find_first_not_of(" \t"));
                        value.erase(value.find_last_not_of(" \t") + 1);
                    }
                    else {
                        value = "";
                    }
                    key.erase(0, key.find_first_not_of(" \t"));
                    key.erase(key.find_last_not_of(" \t") + 1);
                    data[current_section][key] = value;
                }
                else {
                    std::cerr << "Ошибка: Неверный формат строки: " << line << std::endl;
                    throw std::runtime_error("Неверный формат файла: " + filename);
                }
            }
        }
    }

    template<typename T>
    T get_value(const std::string& section_key) const {
        std::istringstream iss(section_key);
        std::string section, key;
        if (std::getline(iss, section, '.') && std::getline(iss, key)) {
            auto it = data.find(section);
            if (it != data.end()) {
                auto inner_map = it->second;
                auto inner_it = inner_map.find(key);
                if (inner_it != inner_map.end()) {
                    if (inner_it->second.empty()) {
                        throw std::runtime_error("Пустое значение для секции.ключа: " + section_key);
                    }
                    std::istringstream converter(inner_it->second);
                    T result;
                    if (!(converter >> result)) {
                        return inner_it->second;
                    }
                    return result;
                }
            }
        }
        throw std::runtime_error("Значение не найдено для секции.ключа: " + section_key);
    }
};

int main() {

    setlocale(LC_ALL, "ru");
    system("chcp 1251");

    try {
        ini_parser parser("C:\\Users\\ofrao\\Desktop\\origin\\Kursovaya 3\\Project1\\test.ini");
        auto value = parser.get_value<std::string>("Section1.var2");
        std::cout << "Значение: " << value << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
}


