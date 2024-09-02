
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

class Address
{
private:
    std::string city;
    std::string street;
    int home;
    int appartment;

public:

    Address(std::string city = "�����", std::string street = "�����", int home = 0, int appartment = 0)
        : city{ city }, street{ street }, home{ home }, appartment{ appartment }
    {}

    std::string get_output_address()
    {
        return city + ", " + street + ", " + std::to_string(home) + ", " + std::to_string(appartment);
    }

    std::string get_city()
    {
        return city;
    }

    void set_address(std::string city, std::string street, int home, int appartament)
    {
        this->city = city;
        this->street = street;
        this->home = home;
        this->appartment = appartament;
    }

};


bool compareByCity(Address& a, Address& b) {
    return a.get_city() > b.get_city();
}

void mysort(Address* addresses, int size) {
    std::sort(addresses, addresses + size, compareByCity);
}

int main()
{
    std::ifstream fin("C:\\Users\\ofrao\\Desktop\\origin\\Lesson 3\\Project2\\in.txt");

    int size;
    fin >> size;

    Address* address = new Address[size];

    for (int i = 0; i < size; ++i)
    {
        std::string city;
        std::string street;
        int home;
        int appartament;
        fin >> city;
        fin >> street;
        fin >> home;
        fin >> appartament;
        address[i].set_address(city, street, home, appartament);
    }

    mysort(address, size);

    std::ofstream fout("C:\\Users\\ofrao\\Desktop\\origin\\Lesson 3\\Project2\\out.txt");

    fout << size << std::endl;

    for (int i = 0; i < size; ++i)
    {
        fout << address[size - i - 1].get_output_address() << std::endl;
    }  

    fout.close();
    fin.close();
    delete[] address;

}
