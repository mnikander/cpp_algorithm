// Copyright (c) 2024, Marco Nikander

#pragma once

#include <algorithm>
#include <cassert>
#include <vector>
#include "../meta/expression.hpp"

namespace nv {

template<typename T>
std::vector<T> repeat(T value, int count)
{
    assert(count >= 0);
    std::vector<T> result(count);
    std::fill(result.begin(), result.end(), value);
    return result;
}

}
