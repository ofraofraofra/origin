﻿#include <iostream>

enum class seasons
{
    January = 1,
    February = 2 ,
    March = 3,
    April = 4,
    May = 5,
    June = 6,
    July = 7,
    August = 8,
    September = 9,
    October = 10,
    November = 11,
    December = 12,   
};


int main()

{
    setlocale(LC_ALL, "ru");
   
    while (true)
    {
        std::cout << "Введите номер месяца: " << std::endl;

        int num;
        std::cin >> num;

        if (num == 0) {
            std::cout << "До свидания!" << std::endl;
            break;
        }

        seasons s = static_cast<seasons>(num);

        switch (s)
        {
        case seasons::January:
            std::cout << "Январь" << std::endl;
            break;
        case seasons::February:
            std::cout << "Февраль" << std::endl;
            break;
        case seasons::March:
            std::cout << "Март" << std::endl;
            break;
        case seasons::April:
            std::cout << "Апрель" << std::endl;
            break;
        case seasons::May:
            std::cout << "Май" << std::endl;
            break;
        case seasons::June:
            
            std::cout << "Июнь" << std::endl;
            break;
        case seasons::July:
            
            std::cout << "Июль" << std::endl;
            break;
        case seasons::August:
            
            std::cout << "Август" << std::endl;
            break;
        case seasons::September:
            
            std::cout << "Сентябрь" << std::endl;
            break;
        case seasons::October:
            
            std::cout << "Октябрь" << std::endl;
            break;
        case seasons::November:
            
            std::cout << "Ноябрь" << std::endl;
            break;
        case seasons::December:
           
            std::cout << "Декабрь" << std::endl;
            break;
        default:
            std::cout << "Вы ввели неверный номер!" << std::endl;
            break;
        }
    }

  }
