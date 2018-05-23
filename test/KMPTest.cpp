#include "KMPTest.h"

string KMPTest::generateRandomString(int num) {
    string s;
    mt19937 mt{random_device{}()};
    uniform_int_distribution<char> dist{'a', 'z'};
    generate_n(back_inserter(s), num, [&dist, &mt]() { return dist(mt); });
    return s;
}

int KMPTest::getRandomNumber(int max) {
    mt19937 mt{random_device{}()};
    uniform_real_distribution<double> dist(1, max);
    return dist(mt);
}

void KMPTest_shift::SetUp() {
    kmp = new KMPAlgorithm;
    auto params = GetParam();
    text = std::get<0>(params);
    pattern = std::get<1>(params);
    res = std::get<2>(params);
}

void KMPTest_kmp::SetUp() {
    kmp = new KMPAlgorithm;
    auto params = GetParam();
    text = params.first;
    pattern = params.second;
}

string KMPTest_kmp::findAllOccurances(const string& pattern, const string& text) {
    string result;
    size_t pos = text.find(pattern);
    while(pos != std::string::npos) {
        result += to_string(pos) + ',';
        pos = text.find(pattern, pos + 1);
    }
    result = result.substr(0, result.length() - 1);
    if(result == "") {
        return "-1";
    }
    return result;
}