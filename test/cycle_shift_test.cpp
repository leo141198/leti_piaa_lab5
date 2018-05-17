#include <iostream>
#include "KMPTest.h"

using namespace std;

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

INSTANTIATE_TEST_CASE_P(Default, KMPTest_shift, ::testing::Values(
        test_type_shift(KMPTest_shift::generateRandomString(10), KMPTest_shift::getRandomNumber(10)),
        test_type_shift(KMPTest_shift::generateRandomString(1000), KMPTest_shift::getRandomNumber(1000)),
        test_type_shift(KMPTest_shift::generateRandomString(5000000), KMPTest_shift::getRandomNumber(5000000))
));

TEST_P(KMPTest_shift, test_eq) {
    cout << COUT_GTEST_MGT << "Checking correct input with text length " << text.length() << " and shift " << num
         << ANSI_TXT_DFT << endl;
    EXPECT_EQ(kmp->cycle_shift(text, pattern), to_string(num));
}

TEST_P(KMPTest_shift, test_neq_length) {
    pattern += to_string(0);
    cout << COUT_GTEST_MGT << "Checking incorrect input (different length) with first text length " << text.length()
         << " and second text length " << pattern.length() << ANSI_TXT_DFT << endl;
    EXPECT_NE(kmp->cycle_shift(text, pattern), to_string(num));
}

TEST_P(KMPTest_shift, test_neq_str) {
    pattern[0] = '*';
    cout << COUT_GTEST_MGT << "Checking incorrect input (shift can't be found) with first text start \"" << text.substr(0,5)
         << "...\" and second text start \"" << pattern.substr(0,5) << "...\""<<ANSI_TXT_DFT << endl;
    EXPECT_NE(kmp->cycle_shift(text, pattern), to_string(num));
}