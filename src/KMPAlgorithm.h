#ifndef PIAA_LAB5_KMPALGORITHM_H
#define PIAA_LAB5_KMPALGORITHM_H

#include <string>
#include <sstream>

using namespace std;

class KMPAlgorithm {
public:
    string pattern_search(const string& P_, const string& T_);

    string cycle_shift(const string& P_, const string& T_);

private:
    int* prefix(const string& input);
};

#endif