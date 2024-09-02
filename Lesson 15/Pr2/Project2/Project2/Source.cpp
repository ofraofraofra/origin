#include <iostream>

template<typename T>
class Table {
private:
    T** data;
    size_t rows;
    size_t cols;

public:
    Table(size_t rows, size_t cols) : rows(rows), cols(cols) {
        data = new T * [rows];
        for (size_t i = 0; i < rows; ++i) {
            data[i] = new T[cols];
        }
    }

    T* operator[](size_t row) {
        return data[row];
    }

    const T* operator[](size_t row) const {
        return data[row];
    }

    size_t Size() const {
        return rows * cols;
    }

    ~Table() {
        for (size_t i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }
};

int main() {
    auto test = Table<int>(2, 3);
    test[0][0] = 4;
    std::cout << test[0][0]; // выводит 4
}
