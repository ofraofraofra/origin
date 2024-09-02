#include <iostream>
#include <mutex>
#include <thread>

class Data {
public:
    int value;
    std::mutex mtx;

    Data(int val) : value(val) {}
};

// Вариант 1
void swap_lock(Data& a, Data& b) {
    
    std::lock(a.mtx, b.mtx);
  
    std::lock_guard<std::mutex> lock1(a.mtx, std::adopt_lock);
    std::lock_guard<std::mutex> lock2(b.mtx, std::adopt_lock);
   
    std::swap(a.value, b.value);
}

// Вариант 2
void swap_scoped_lock(Data& a, Data& b) {
   
    std::scoped_lock lock(a.mtx, b.mtx);

    std::swap(a.value, b.value);
}

// Вариант 3
void swap_unique_lock(Data& a, Data& b) {
    
    std::unique_lock<std::mutex> lock1(a.mtx, std::defer_lock);
    std::unique_lock<std::mutex> lock2(b.mtx, std::defer_lock);

    std::lock(lock1, lock2);

    std::swap(a.value, b.value);
}

int main() {

    Data data1(1);
    Data data2(2);

    std::cout << "Before swap_lock: data1 = " << data1.value << ", data2 = " << data2.value << std::endl;
    swap_lock(data1, data2);
    std::cout << "After swap_lock: data1 = " << data1.value << ", data2 = " << data2.value << std::endl;

    swap_scoped_lock(data1, data2);
    std::cout << "After swap_scoped_lock: data1 = " << data1.value << ", data2 = " << data2.value << std::endl;

    swap_unique_lock(data1, data2);
    std::cout << "After swap_unique_lock: data1 = " << data1.value << ", data2 = " << data2.value << std::endl;

    return 0;
}
