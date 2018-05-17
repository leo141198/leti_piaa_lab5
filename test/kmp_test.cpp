#include <iostream>
#include "KMPTest.h"

using namespace std;

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

INSTANTIATE_TEST_CASE_P(Default, KMPTest_kmp, ::testing::Values(
        KMPTest_shift::generateRandomString(10),
        KMPTest_shift::generateRandomString(1000),
        KMPTest_shift::generateRandomString(5000000)
));

TEST_P(KMPTest_kmp, test_eq) {
    cout << COUT_GTEST_MGT << "Checking correct input with text length " << text.length() << " and pattern length "
         << pattern.length() << ANSI_TXT_DFT << endl;
    EXPECT_EQ(kmp->pattern_search(pattern, text), KMPTest_kmp::findAllOccurances(pattern, text));
}

TEST_P(KMPTest_kmp, test_neq) {
    pattern += to_string(0);
    cout << COUT_GTEST_MGT << "Checking incorrect input (pattern doesn't exist in text) with text length "
         << text.length() << " and pattern length " << pattern.length() << ANSI_TXT_DFT << endl;
    EXPECT_EQ(kmp->pattern_search(pattern, text), KMPTest_kmp::findAllOccurances(pattern, text));
}