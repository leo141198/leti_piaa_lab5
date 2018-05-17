#include <iostream>
#include "KMPAlgorithm.h"

using namespace std;

int main() {
    string P,T;
    getline(cin, P);
    getline(cin, T);
    auto kmp = new KMPAlgorithm();
    cout << kmp->cycle_shift(P,T);
    return 0;
}