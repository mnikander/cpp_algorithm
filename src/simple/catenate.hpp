// Copyright (c) 2024, Marco Nikander

#pragma once

#include <algorithm>
#include <vector>
#include "../meta/expression.hpp"
#include "size.hpp"

namespace nv {

template<typename T>
std::vector<T> catenate(std::vector<T> const& left, std::vector<T> const& right)
{
    std::vector<T> result(left);
    result.reserve(size(left) + size(right));
    result.insert(result.end(), right.cbegin(), right.cend());
    return result;
}

template<typename T>
std::vector<T> catenate(T const& left, std::vector<T> const& right)
{
    std::vector<T> result = {left}; // careful with the parenthesis / braces here (O_o)
    result.reserve(1 + size(right));
    result.insert(result.end(), right.cbegin(), right.cend());
    return result;
}

template<typename T>
std::vector<T> catenate(std::vector<T> const& left, T const& right)
{
    std::vector<T> result(left);
    result.reserve(size(left) + 1);
    result.push_back(right);
    return result;
}

template<typename T>
std::vector<T> catenate(T const& left, T const& right)
{
    return std::vector<T>{left, right};
}

}
