#include <iostream>

#define MODE 1

#if defined(MODE)

#if MODE == 0
#error "���������� ���������� MODE"
#endif

#else
#error "���������� ���������� MODE"
#endif

void add(int a, int b) {
    std::cout << "��������� ��������: " << a + b << std::endl;
}

int main() {

    setlocale(LC_ALL, "ru");

    switch (MODE) {
    case 0:
        std::cout << "������� � ������ ����������" << std::endl;
        break;
    case 1:
        std::cout << "������� � ������ ������" << std::endl;
        int num1, num2;
        std::cout << "������� ����� 1: ";
        std::cin >> num1;
        std::cout << "������� ����� 2: ";
        std::cin >> num2;
        add(num1, num2);
        break;
    default:
        std::cout << "����������� �����. ���������� ������" << std::endl;
    }

}