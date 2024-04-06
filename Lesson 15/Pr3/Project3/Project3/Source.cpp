#include <iostream>
#include <vector>
#include <algorithm>

class DivisibleByThreeCounter {
private:
    int sum;
    int count;

public:
    DivisibleByThreeCounter() : sum(0), count(0) {}
    
    void operator()(int num) {
        if (num % 3 == 0) {
            sum += num;
            ++count;
        }
    }
    
    int get_sum() const {
        return sum;
    }

    int get_count() const {
        return count;
    }
};

int main() {
    

    std::vector<int> numbers{ 4, 1, 3, 6, 25, 54 };
    std::cout << "[IN]: ";
    for (const auto& elem : numbers) {
        std::cout << elem << " ";
    };
    std::cout << std::endl;

    DivisibleByThreeCounter counter = std::for_each(numbers.begin(), numbers.end(), DivisibleByThreeCounter());

    std::cout << "[OUT]: get_sum() = " << counter.get_sum() << std::endl;
    std::cout << "[OUT]: get_count() = " << counter.get_count() << std::endl;

}
