#include <iostream>
#include <fstream>
#include "data.h"

int main() {

    setlocale(LC_ALL, "ru");
    system("chcp 1251");
   
    TextData textData("This is plain text");
    HTMLData htmlData("This is HTML text");
    JSONData jsonData("This is JSON text");

    std::ofstream textFile("textData.txt");
    std::ofstream htmlFile("htmlData.html");
    std::ofstream jsonFile("jsonData.json");

    if (!textFile || !htmlFile || !jsonFile) {
        std::cerr << "Ошибка открытия файла для записи" << std::endl;
        return 1;
    }

    saveToAsText(textFile, textData);
    saveToAsHTML(htmlFile, htmlData);
    saveToAsJSON(jsonFile, jsonData);

    textFile.close();
    htmlFile.close();
    jsonFile.close();

}
