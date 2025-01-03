// Copyright (c) 2024, Marco Nikander

#pragma once

#include <cassert>
#include <vector>
#include <numeric>
#include "../meta/expression.hpp"

namespace nv {

template<typename T>
std::vector<T> iota(T firstValue, T lastValue)
{
    assert(lastValue >= firstValue);

    const size_t count = static_cast<size_t>(lastValue - firstValue);
    std::vector<T> result(count);
    std::iota(result.begin(), result.end(), firstValue);
    return result; // I hope copy-elision optimizes this out
    // TODO: how can I verify this? Perhaps with a wrapper around std::vector which prints in the copy-constructor?
}

template<typename T>
std::vector<T> iota(T lastValue)
{
    assert(lastValue >= 0);
    return iota(T{0}, lastValue);
}

}
