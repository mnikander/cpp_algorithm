#pragma once

#include <algorithm>
#include <cassert>
#include <vector>
#include "reverse.hpp"

namespace naive {

template<typename T>
std::vector<T> rotate(std::vector<T> const& v, int count)
{
    assert(-static_cast<int>(v.size()) <= count);
    assert(count <= static_cast<int>(v.size()));

    std::vector<T> result(v);
    if(count >= 0)
    {
        std::rotate(result.begin(), result.begin() + count, result.end());
    }
    else
    {
        std::rotate(result.rbegin(), result.rbegin() + (-count), result.rend());
    }
    return result;
}

template<typename T>
std::vector<T> rotate(std::vector<T> const& v) // no count
{
    return reverse(v);
}

}