#include <iostream>
#include <string>
#include <algorithm>
#include <locale>


int main() {
    setlocale(LC_ALL, "Russian");

    std::string word;

    std::cout << "введите слово: ";
    std::cin >> word;

    int choice;
    std::cout << "выберите действие:\n"
        << "1. вывести слово задом наперед\n"
        << "2. вывести слово без гласных\n"
        << "3. вывести слово без согласных\n"
        << "4. рандомно раскидывать буквы слова\n"
        << "ваш выбор: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
        std::reverse(word.begin(), word.end());
        break;
    case 2:
        word.erase(std::remove_if(word.begin(), word.end(), [](char c) {
            return std::string("aeiouAEIOUаеёиоуыэюяАЕЁИОУЫЭЮЯ").find(c) != std::string::npos;
            }), word.end());
        break;
    case 3:
        word.erase(std::remove_if(word.begin(), word.end(), [](char c) {
            return std::string("bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZбцдфгхйклмнпрстфвшщзжчйьъБЦДФГХЙКЛМНПРСТФВШЩЗЖЧЙЬЪ").find(c) != std::string::npos;
            }), word.end());
        break;
    case 4:
        std::random_shuffle(word.begin(), word.end());
        break;
    default:
        std::cout << "некорректный выбор действия.";
        return 0;
    }

    std::cout << "результат: " << word;

    return 0;
}