#include <iostream>
#include <stdexcept>

class smart_array {
private:
    int* data;
    int size;
    int capacity;

public:
    smart_array(int initial_capacity) : size(0), capacity(initial_capacity) {
        data = new int[capacity];
    }

    smart_array(const smart_array& other) : size(other.size), capacity(other.capacity) {
        data = new int[capacity];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    smart_array& operator=(const smart_array& other) {
        if (this == &other) {
            return *this;
        }

        delete[] data;

        capacity = other.capacity;
        size = other.size;
        data = new int[capacity];

        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }

        return *this;
    }

    ~smart_array() {
        delete[] data;
    }

    void add_element(int element) {
        if (size >= capacity) {
            int new_capacity = capacity * 2 * sizeof(int);
            int* new_data = new int[new_capacity];
            for (int i = 0; i < size; ++i) {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
            capacity = new_capacity / sizeof(int);
        }
        data[size++] = element;
    }

    int get_element(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }
};

int main() {
    try {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);

        smart_array new_array(2);
        new_array.add_element(44);
        new_array.add_element(34);

        arr = new_array;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }

}
