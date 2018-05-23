#include <iostream>
#include "KMPTest.h"

using namespace std;

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

INSTANTIATE_TEST_CASE_P(Default, KMPTest_shift, ::testing::Values(
        make_tuple("abcdef", "defabc", "3"),
        make_tuple("123123", "123123", "0"),
        make_tuple("abcdef", "xyzxyz", "-1"),
        make_tuple("abcdef", "abcabcabcabc", "-1")
));

TEST_P(KMPTest_shift, test_eq) {
    cout << COUT_GTEST_MGT << "Checking first text \"" << text << "\" and second text \"" << pattern << "\" for cycle shift"
         << ANSI_TXT_DFT << endl;
    EXPECT_EQ(kmp->cycle_shift(text, pattern), res);
}