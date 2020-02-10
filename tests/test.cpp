// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>
#include "header.hpp"
#include "header2.hpp"

class summ{
public:
    summ();
    summ(int a, int b, int c)
    {
        rez = a+b+c;
    }
    int rez;
};

TEST(stack, Text){
	stack<int> test;
    int a = 2, b = 3, c = 4;

    test.push(a);
    test.push(b);
    test.push(c);
    test.push(12);
	
	EXPECT_EQ(test.head(), 12);
    EXPECT_EQ(test.pop(), 12);
	EXPECT_EQ(test.pop(), 4);
	EXPECT_EQ(test.pop(), 3);
	EXPECT_EQ(test.pop(), 2);
}

TEST(stack_t, Text){
    stack_t<int> test;
    int a = 2, b = 3, c = 4;
    test.push_emplace(1,2,3);
    test.push(a);
    test.push(b);
    test.push(c);
    test.push(12);

	EXPECT_EQ(test.head(), 12);
    EXPECT_EQ(test.pop(), 12);
	EXPECT_EQ(test.pop(), 4);
	EXPECT_EQ(test.pop(), 3);
	EXPECT_EQ(test.pop(), 2);
	EXPECT_EQ(test.pop(), 6);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}