#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class SqlSelectQueryBuilder {
public:
    SqlSelectQueryBuilder& AddColumn(const std::string& column) {
        columns.push_back(column);
        return *this;
    }

    SqlSelectQueryBuilder& AddFrom(const std::string& table) {
        fromTable = table;
        return *this;
    }

    SqlSelectQueryBuilder& AddWhere(const std::string& column, const std::string& value) {
        if (!whereClauses.empty()) {
            whereClauses += " AND ";
        }
        whereClauses += column + "=" + value;
        return *this;
    }

    std::string BuildQuery() {
        std::ostringstream query;

        query << "SELECT ";
        if (columns.empty()) {
            query << "*";
        }
        else {
            for (size_t i = 0; i < columns.size(); ++i) {
                query << columns[i];
                if (i < columns.size() - 1) {
                    query << ", ";
                }
            }
        }

        query << " FROM " << fromTable;

        if (!whereClauses.empty()) {
            query << " WHERE " << whereClauses;
        }

        query << ";";
        return query.str();
    }

private:
    std::vector<std::string> columns;
    std::string fromTable;
    std::string whereClauses;
};

int main() {

    setlocale(LC_ALL, "ru");
    system("chcp 1251");

    SqlSelectQueryBuilder query_builder;
    query_builder.AddColumn("name").AddColumn("phone");
    query_builder.AddFrom("students");
    query_builder.AddWhere("id", "42").AddWhere("name", "John");
  
    std::string expectedQuery = "SELECT name, phone FROM students WHERE id=42 AND name=John;";
    std::string actualQuery = query_builder.BuildQuery();

    if (actualQuery == expectedQuery) {
        std::cout << "Запрос сгенерирован корректно: " << actualQuery << std::endl;
    }
    else {
        std::cout << "Ошибка в генерации запроса: " << actualQuery << std::endl;
    }
}