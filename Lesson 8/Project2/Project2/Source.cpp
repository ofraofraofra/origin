#include <iostream>

class Fraction
{
private:
    int numerator_;
    int denominator_;

    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    void reduce() {
        int common = gcd(numerator_, denominator_);
        numerator_ /= common;
        denominator_ /= common;
    }

public:
    Fraction(int numerator, int denominator)
    {
        numerator_ = numerator;
        denominator_ = denominator;
    }

    bool operator==(const Fraction& other) const
    {
        return (numerator_ * other.denominator_ == other.numerator_ * denominator_);
    }

    bool operator!=(const Fraction& other) const
    {
        return !(*this == other);
    }

    bool operator<(const Fraction& other) const
    {
        return (numerator_ * other.denominator_ < other.numerator_* denominator_);
    }

    bool operator>(const Fraction& other) const {
        return (other < *this);
    }

    bool operator<=(const Fraction& other) const
    {
        return !(*this > other);
    }

    bool operator>=(const Fraction& other) const
    {
        return !(*this < other);
    }

    Fraction operator+(const Fraction& other) const {
        int new_numerator = numerator_ * other.denominator_ + other.numerator_ * denominator_;
        int new_denominator = denominator_ * other.denominator_;
        Fraction result(new_numerator, new_denominator);
        result.reduce();
        return result;
    }

     Fraction operator-(const Fraction & other) const {
        int new_numerator = numerator_ * other.denominator_ - other.numerator_ * denominator_;
        int new_denominator = denominator_ * other.denominator_;
        Fraction result(new_numerator, new_denominator);
        result.reduce();
        return result;
     }

 
     Fraction operator*(const Fraction& other) {
         int new_numerator = numerator_ * other.numerator_;
         int new_denominator = denominator_ * other.denominator_;
         Fraction result(new_numerator, new_denominator);
         result.reduce();
         return result;
     }

     Fraction operator/(const Fraction& other) {
         int new_numerator = numerator_ * other.denominator_;
         int new_denominator = denominator_ * other.numerator_;
         Fraction result(new_numerator, new_denominator);
         result.reduce();
         return result;
     }

     Fraction operator-() const {
         return Fraction(-numerator_, denominator_);
     }

     Fraction& operator++() {
         numerator_ += denominator_;
         reduce();
         return *this;
     }

     Fraction operator++(int) {
         Fraction temp = *this;
         numerator_ += denominator_;
         reduce();
         return temp;
     }

     Fraction& operator--() {
         numerator_ -= denominator_;
         reduce();
         return *this;
     }

     Fraction operator--(int) {
         Fraction temp = *this;
         numerator_ -= denominator_;
         reduce();
         return temp;
     }

     int getNumerator() const {
         return numerator_;
     }

     int getDenominator() const {
         return denominator_;
     }

};

int main()
{
    setlocale(LC_ALL, "ru");
    system("chcp 1251");
    int num1, den1, num2, den2;
    std::cout << "¬ведите числитель дроби 1: ";
    std::cin >> num1;
    std::cout << "¬ведите знаменатель дроби 1: ";
    std::cin >> den1;
    std::cout << "¬ведите числитель дроби 2: ";
    std::cin >> num2;
    std::cout << "¬ведите знаменатель дроби 2: ";
    std::cin >> den2;

    Fraction f1(num1, den1);
    Fraction f2(num2, den2);
    
    std::cout << f1.getNumerator() << "/" << f1.getDenominator() << " + " <<
        f2.getNumerator() << "/" << f2.getDenominator() << " = " <<
        (f1 + f2).getNumerator() << "/" << (f1 + f2).getDenominator() << std::endl;
    std::cout << f1.getNumerator() << "/" << f1.getDenominator() << " - " <<
        f2.getNumerator() << "/" << f2.getDenominator() << " = " <<
        (f1 - f2).getNumerator() << "/" << (f1 - f2).getDenominator() << std::endl;


    std::cout << f1.getNumerator() << "/" << f1.getDenominator() << " * " <<
        f2.getNumerator() << "/" << f2.getDenominator() << " = " <<
        (f1 * f2).getNumerator() << "/" << (f1 * f2).getDenominator() << std::endl;


    std::cout << f1.getNumerator() << "/" << f1.getDenominator() << " / " <<
        f2.getNumerator() << "/" << f2.getDenominator() << " = " <<
        (f1 / f2).getNumerator() << "/" << (f1 / f2).getDenominator() << std::endl;
    
    std::cout << "++" << f1.getNumerator() << "/" << f1.getDenominator() << " * "
        << f2.getNumerator() << "/" << f2.getDenominator() << " = ";
    std::cout << (++f1*f2).getNumerator() << "/" << (f1 * f2).getDenominator() << std::endl;
    std::cout << "«начение дроби 1 = " << f1.getNumerator() << "/" << f1.getDenominator() << std::endl;


    std::cout  << f1.getNumerator() << "/" << f1.getDenominator() << "--" << " * "
        << f2.getNumerator() << "/" << f2.getDenominator() << " = ";
    std::cout << (f1-- * f2).getNumerator() << "/" << (f1 * f2).getDenominator() << std::endl;
    std::cout << "«начение дроби 1 = " << f1.getNumerator() << "/" << f1.getDenominator() << std::endl;

    
}

