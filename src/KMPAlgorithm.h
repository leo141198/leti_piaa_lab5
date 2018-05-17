#ifndef PIAA_LAB5_KMPALGORITHM_H
#define PIAA_LAB5_KMPALGORITHM_H

#include <string>
#include <sstream>

using namespace std;

class KMPAlgorithm {
public:
    string pattern_search(string P, string T);

    string cycle_shift(string P, string T);

private:
    int* prefix(const string& input);
};

#endif