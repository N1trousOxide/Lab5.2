//Copyright 2020 <ZaitsevGames & N1trousOxide>

#include <gtest/gtest.h>
#include <iostream>
#include <stack.hpp>
#include <simple_stack.hpp>
#include <any>

const int a = 7;
const int b = 15;

TEST(Example, EmptyTest) {
    simple_stack <int> stack;

    stack.push(a);
    stack.push(b);

    EXPECT_EQ(stack.head(), b);
}

TEST(simple_stack, pop)
{
    simple_stack <int> stack;

    stack.push(a);
    stack.push(b);

    stack.pop();

    EXPECT_EQ(stack.head(), a);
}

TEST(simple_stack, second_push)
{
    simple_stack <int> stack;

    stack.push(std::move(a));
    stack.push(std::move(b));

    EXPECT_EQ(stack.head(), b);

    stack.pop();

    EXPECT_EQ(stack.head(), a);
}


TEST(stak12, testcopy)
{
    EXPECT_EQ(std::is_copy_constructible_v<simple_stack<int>>, false);
    EXPECT_EQ(std::is_copy_constructible_v<stack<int>>, false);

    EXPECT_EQ(std::is_copy_assignable_v<simple_stack<int>>, false);
    EXPECT_EQ(std::is_copy_assignable_v<stack<int>>, false);
}

TEST(stak12, testmove)
{
    EXPECT_EQ(std::is_move_constructible_v<simple_stack<int>>, true);
    EXPECT_EQ(std::is_move_constructible_v<stack<int>>, true);

    EXPECT_EQ(std::is_move_assignable_v<simple_stack<int>>, true);
    EXPECT_EQ(std::is_move_assignable_v<stack<int>>, true);
}
