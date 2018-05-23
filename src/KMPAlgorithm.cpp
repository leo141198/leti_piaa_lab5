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

string KMPAlgorithm::pattern_search(const string& P_, const string& T_) {
    string positions;
    stringstream output;
    int size = P_.length();
    string P = P_ + "@" + T_;
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

string KMPAlgorithm::cycle_shift(const string& P_, const string& T_) {
    int size = P_.length();
    if(P_.length() != T_.length()) {
        return "-1";
    }
    string T = T_ + "@" + P_ + P_;
    auto result = prefix(T);
    for(size_t i = 0; i < T.length(); i++) {
        if(result[i] == size) {
            return to_string(i - 2 * size);
        }
    }
    return "-1";
}