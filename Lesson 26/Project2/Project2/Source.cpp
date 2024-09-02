#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

class SqlSelectQueryBuilder {
public:
    SqlSelectQueryBuilder& AddColumn(const std::string& column) {
        columns.push_back(column);
        return *this;
    }

    SqlSelectQueryBuilder& AddColumns(const std::vector<std::string>& cols) noexcept {
        for (const auto& col : cols) {
            columns.push_back(col);
        }
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

    SqlSelectQueryBuilder& AddWhere(const std::map<std::string, std::string>& kv) noexcept {
        for (const auto& pair : kv) {
            AddWhere(pair.first, pair.second);
        }
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

    std::map<std::string, std::string> conditions = { {"age", "20"}, {"grade", "A"} };
    query_builder.AddWhere(conditions);

    std::string expectedQuery = "SELECT name, phone FROM students WHERE id=42 AND name=John AND age=20 AND grade=A;";
    std::string actualQuery = query_builder.BuildQuery();

        if (actualQuery == expectedQuery) {
            std::cout << "������ ������������ ���������: " << actualQuery << std::endl;
        }
        else {
            std::cout << "������ � ��������� �������: " << actualQuery << std::endl;
        }
}