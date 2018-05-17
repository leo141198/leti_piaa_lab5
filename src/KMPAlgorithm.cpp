#include "KMPAlgorithm.h"

int* KMPAlgorithm::prefix(const string& input) {
    size_t n = input.length();
    auto sub_size = new int[n];
    for(int i = 0; i < n; i++) {
        sub_size[i] = 0;
    }
    for(size_t i = 1; i < n; i++) {
        size_t j = sub_size[i - 1];
        while((j > 0) && (input[i] != input[j])) {
            j = sub_size[j - 1];
        }
        if(input[i] == input[j]) {
            j++;
        }
        sub_size[i] = j;
    }
    return sub_size;
}

string KMPAlgorithm::pattern_search(string P, string T) {
    string positions;
    stringstream output;
    int size = P.length();
    P += "@" + T;
    auto result = prefix(P);
    for(int i = 0; i < P.length(); i++) {
        if(result[i] == size) {
            output << i - 2 * size << ",";
        }
    }
    positions = output.str();
    if(positions.length() == 0) {
        return "-1";
    } else {
        return positions.substr(0, positions.length() - 1);
    }
}

string KMPAlgorithm::cycle_shift(string P, string T) {
    int size = P.length();
    if(P.length() != T.length()) {
        return "-1";
    }
    T += "@" + P + P;
    auto result = prefix(T);
    for(size_t i = 0; i < T.length(); i++) {
        if(result[i] == size) {
            return to_string(i - 2 * size);
        }
    }
    return "-1";
}