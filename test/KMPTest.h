#ifndef PIAA_LAB5_KMPTEST_H
#define PIAA_LAB5_KMPTEST_H

#include <string>
#include <random>
#include <gtest/gtest.h>
#include "../src/KMPAlgorithm.h"

#define ANSI_TXT_GRN "\033[0;32m"
#define ANSI_TXT_MGT "\033[0;35m"
#define ANSI_TXT_DFT "\033[0;0m"
#define GTEST_BOX "[          ] "
#define COUT_GTEST ANSI_TXT_GRN << GTEST_BOX
#define COUT_GTEST_MGT COUT_GTEST << ANSI_TXT_MGT

typedef pair<string, int> test_type_shift;
typedef string test_type_kmp;

class KMPTest : public ::testing::Test {
public:
    KMPTest() : kmp(new KMPAlgorithm) {}

    static string generateRandomString(int num);

    static int getRandomNumber(int max);

protected:
    KMPAlgorithm* kmp;
    string text;
    string pattern;

    virtual void SetUp() = 0;
};

class KMPTest_shift : public KMPTest, public testing::WithParamInterface<test_type_shift> {
protected:
    int num;

    void SetUp() override;
};

class KMPTest_kmp : public KMPTest, public testing::WithParamInterface<test_type_kmp> {
protected:
    void SetUp() override;

public:
    string findAllOccurances(string& pattern, string& text);
};

#endif //PIAA_LAB5_KMPTEST_H