#include <vector>
#include <memory>
#include <ranges>
#include <utility>
#include <iostream>

constexpr int f(int i)
{
    auto p = std::make_unique<int>(1);
    return *p;
}

int main1()
{
    constexpr int i = f(1);
}