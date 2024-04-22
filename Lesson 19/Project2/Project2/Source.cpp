#include <iostream>
#include <vector>
#include <algorithm>

class big_integer {
private:
    std::vector<int> digits;

public:

    big_integer(const std::string& num) { //обычный конструктор
        for (char c : num) {
            digits.push_back(c - '0');
        }
        std::reverse(digits.begin(), digits.end());
    }

    big_integer& operator=(const std::string& num) { //обычный оператор
        digits.clear();
        for (char c : num) {
            digits.push_back(c - '0');
        }
        std::reverse(digits.begin(), digits.end());
        return *this;
    }

    // Перемещающий конструктор
    big_integer(big_integer&& num) noexcept : digits(std::move(num.digits)) {}

    // Перемещающий оператор присваивания
    big_integer& operator=(big_integer&& num) noexcept {
        if (this != &num) {
            digits = std::move(num.digits);
        }
        return *this;
    }

    //сложение двух больших чисел
    big_integer operator+(const big_integer& other) const {
        big_integer result("");
        int carry = 0;
        size_t max_size = std::max(digits.size(), other.digits.size());
        for (size_t i = 0; i < max_size; ++i) {
            int sum = carry;
            if (i < digits.size()) sum += digits[i];
            if (i < other.digits.size()) sum += other.digits[i];
            result.digits.push_back(sum % 10);
            carry = sum / 10;
        }
        if (carry > 0) result.digits.push_back(carry);
        return result;
    }

    // умножения на число
    big_integer operator*(int num) const {
        big_integer result("");
        int carry = 0;
        for (int digit : digits) {
            int prod = digit * num + carry;
            result.digits.push_back(prod % 10);
            carry = prod / 10;
        }
        while (carry > 0) {
            result.digits.push_back(carry % 10);
            carry /= 10;
        }
        return result;
    }

    //перегрузка вывода
    friend std::ostream& operator<<(std::ostream& os, const big_integer& bigint) {
        for (auto it = bigint.digits.rbegin(); it != bigint.digits.rend(); ++it) {
            os << *it;
        }
        return os;
    }
};

int main() {

    auto number1 = big_integer("114575");
    auto number2 = big_integer("78524");
    auto result = number1 + number2;
    std::cout << result; // 193099

}
