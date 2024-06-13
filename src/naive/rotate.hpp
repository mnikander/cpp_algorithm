#pragma once

#include <algorithm>
#include <cassert>
#include <vector>
#include "reverse.hpp"
#include "size.hpp"

namespace naive {

template<typename T>
std::vector<T> rotate(std::vector<T> const& v, int count)
{
    assert(0 <= count);
    assert(count <= size(v));

    std::vector<T> result(v);
    std::rotate(result.begin(), result.begin() + count, result.end());
    return result;
}

template<typename T>
std::vector<T> rotate(std::vector<T> const& v) // no count
{
    return reverse(v);
}

template<typename T>
std::vector<T> rotate_last(std::vector<T> const& v, int count)
{
    assert(0 <= count);
    assert(count <= size(v));

    std::vector<T> result(v);
    std::rotate(result.rbegin(), result.rbegin() + count, result.rend());
    return result;
}

}
