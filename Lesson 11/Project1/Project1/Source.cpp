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

    smart_array(const smart_array&) = delete;

    smart_array& operator=(const smart_array&) = delete;

    ~smart_array() {
        delete[] data;
    }

    void add_element(int element) {
        if (size >= capacity) {
            int new_capacity = capacity * 2;
            int* new_data = new int[new_capacity];
            for (int i = 0; i < size; ++i) {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
            capacity = new_capacity;
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
        arr.add_element(14);
        arr.add_element(15);
        std::cout << arr.get_element(1) << std::endl;
      //smart_array arr2 = arr;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
}
