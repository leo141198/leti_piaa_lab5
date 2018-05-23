#include <iostream>
#include "KMPTest.h"

using namespace std;

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

INSTANTIATE_TEST_CASE_P(Default, KMPTest_kmp, ::testing::Values(
        test_type_kmp("abcdefabc", "abc"),
        test_type_kmp("123112334351233", "123"),
        test_type_kmp("abc", "def"),
        test_type_kmp("abcabcabc", "abcabc")
));

TEST_P(KMPTest_kmp, test_eq) {
    cout << COUT_GTEST_MGT << "Checking text \"" << text << "\" and pattern \"" << pattern << "\"" << ANSI_TXT_DFT
         << endl;
    EXPECT_EQ(kmp->pattern_search(pattern, text), KMPTest_kmp::findAllOccurances(pattern, text));
}