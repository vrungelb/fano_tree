#include <iostream>
#include <vector>
#include <string>
#include <conio.h>

using namespace std;

// Функция, конвертирующая число в двоичную строку заданной длины.
string to_binary(int num, int length) {
    string s;
    while (num > 0) { // 
        s = (num % 2 == 0 ? "0" : "1") + s;
        num /= 2;
    }
    while (s.length() < length) {
        s = "0" + s;
    }
    return s;
}

// Функция, проверяющая, удовлетворяет ли код условию Фано - ни один код не является префиксом другого.
bool isFanoConditionSatisfied(const string& newCode, const vector<string>& existingCodes) {
    for (const string& code : existingCodes) {
        if (code.find(newCode) == 0 || newCode.find(code) == 0) {
            return false;
        }
    }
    return true;
}

// Функция, находящая код для буквы М, который удовлетворяет условию Фано.
string find_code_for_m() {
    vector<string> existingCodes = {"111", "0", "100"};
    vector<string> possibleCodes;

    // Генерация всевозможных кодов длиной от 1 до 3.
    for (int length = 1; length <= 3; ++length) {
        int max_num = (1 << length) - 1; // 2^length - 1, это макс. число для данной длины
        for (int num = 0; num <= max_num; ++num) {
            possibleCodes.push_back(to_binary(num, length));
        }
    }

    // Отбор кодов, удовлетворяющих условию Фано.
    vector<string> validCodes;
    for (const string& code : possibleCodes) {
        if (isFanoConditionSatisfied(code, existingCodes)) {
            validCodes.push_back(code);
        }
    }

    // Нахождение кода с максимальной длиной.
    string bestCode = "";
    for (const string& code : validCodes) {
        if (code.length() > bestCode.length()) {
            bestCode = code;
        } else if (code.length() == bestCode.length()) {
            if (code > bestCode) {
                bestCode = code;
            }
        }
    }

    return bestCode;
}

int main() {
    string code = find_code_for_m();
    cout << "Code for M letter: " << code << endl;

    getch();

    return 0;
}
