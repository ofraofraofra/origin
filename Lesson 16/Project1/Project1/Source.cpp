#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector>



int main() {

    std::string text = "Hello world! !";

    std::cout << "[IN]: " << text << std::endl;

    std::map<char, int> charFrequency;

    for (char ch : text) {
        charFrequency[ch]++;
    }

    std::vector<std::pair<char, int>> sortedChars(charFrequency.begin(), charFrequency.end());
    std::sort(sortedChars.begin(), sortedChars.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
        });

    std::cout << "[OUT]:" << std::endl;

    for (const auto& pair : sortedChars) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}
