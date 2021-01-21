// Copyright 2021 Krissupervizz
#include <gtest/gtest.h>
#include <string>
#include "postfix.h"

TEST(PostfixTest, test1) {
    std::string inf = "2 + 2";
    std::string postf = infix2prefix(inf);
    std::string expected = "22+";
    EXPECT_EQ(expected, postf);
}

TEST(PostfixTest, test2) {
    std::string inf = "2 + 6 * 3 / (4 - 2)";
    std::string postf = infix2prefix(inf);
    std::string expected = "263*42-/+";
    EXPECT_EQ(expected, postf);
}

TEST(PostfixTest, test3) {
    std::string inf = "(1 + 2) / (3 + 4 * 6.7) - 5.3 * 4.4";
    std::string postf = infix2prefix(inf);
    std::string expected = "12+346.7*+/5.34.4*-";
    EXPECT_EQ(expected, postf);
}
