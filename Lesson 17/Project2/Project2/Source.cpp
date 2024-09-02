#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <string>

template<typename Container>
void print_container(const Container& cont) {
    auto it = cont.begin();
    if (it != cont.end()) {
        std::cout << *it;
        ++it;
        for (; it != cont.end(); ++it) {
            std::cout << ", " << *it;
        }
    }
    std::cout << std::endl;
}


int main() {
    std::set<std::string> test_set = { "one", "two", "three", "four" };
    std::cout << "std::set<std::string>: ";
    print_container(test_set);

    std::list<std::string> test_list = { "one", "two", "three", "four" };
    std::cout << "std::list<std::string>: ";
    print_container(test_list);

    std::vector<std::string> test_vector = { "one", "two", "three", "four" };
    std::cout << "std::vector<std::string>: ";
    print_container(test_vector);

}
