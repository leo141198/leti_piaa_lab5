#include <iostream>
#include <string>
#include "KMPTest.h"

using namespace std;

int kmp(const string& P_, const string& T_);

int search(const string& P_, const string& T_);

int main() {
    string text, pattern;
    for(int i = 1; i < 10; i++) {
        text = KMPTest::generateRandomString(100);
        for(int k = 1; k < i; k++) {
            text += text;
        }
        pattern = text.substr(0, KMPTest::getRandomNumber(100));
        cout << "Для строки длиной " << text.length() << " и паттерна длиной " << pattern.length()
             << ", повторяющегося в исходном тексте " << i << " раз, КМП алгоритму потребовалось " << kmp(pattern, text)
             << " операций, а наивному поиску - " << search(pattern, text) << endl;
    }
}

int kmp(const string& P_, const string& T_) {
    int counter = 0;

    string input = P_ + "@" + T_;
    size_t n = input.length();
    auto sub_size = new int[n];

    for(int i = 0; i < n; i++) {
        sub_size[i] = 0;
    }

    for(size_t i = 1; i < n; i++) {
        size_t j = sub_size[i - 1];
        while((j > 0) && (input[i] != input[j])) {
            counter++; //переход назад = сравнение
            j = sub_size[j - 1];
        }
        counter++;
        if(input[i] == input[j]) {
            j++;
        }
        sub_size[i] = j;
    }
    return counter;
}

int search(const string& P_, const string& T_) {
    int counter = 0;

    for(int i = 0; i < T_.length(); i++) {
        counter++; //сравниваем первый символ паттерна и текущий в строке
        if(T_[i] == P_[0] && (T_.length() - 1 - i >= P_.length())) {
            counter++; // в начале цикла сравниваем второй символ паттерна (если есть) с символом строки
            for(int k = 1; k < P_.length() && T_[i + k] == P_[k]; k++, counter++) {
                //сравниваем все оставшиеся символы паттерна и строки
            }
        }
    }
    return counter;
}