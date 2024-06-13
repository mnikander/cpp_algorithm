#pragma once

#include <algorithm>
#include <cassert>
#include <functional>
#include <vector>
#include "size.hpp"

namespace naive {

template<typename T>
using Plus = std::plus<T>;

template <typename T>
T plus(T left, T right)
{
    return Plus<T>{}(left, right);
}

template <typename T>
std::vector<T> plus(T left, std::vector<T> const& right)
{
    std::vector<T> result(size(right));
    std::transform(right.cbegin(), right.cend(), result.begin(), [left](T x){ return left+x; });
    return result;
}

template <typename T>
std::vector<T> plus(std::vector<T> const& left, T right)
{
    std::vector<T> result(size(left));
    std::transform(left.cbegin(), left.cend(), result.begin(), [right](T x){ return x + right; });
    return result;
}

template <typename T>
std::vector<T> plus(std::vector<T> const& left, std::vector<T> const& right)
{
    assert(size(left) == size(right));
    std::vector<T> result(size(left));
    std::transform(left.cbegin(), left.cend(), right.cbegin(), result.begin(), std::plus<T>{});
    return result;
}

template<typename T>
struct Max
{
    T operator()(T const& left, T const& right) const { return std::max(left, right); }
};

template<typename T>
struct Min
{
    T operator()(T const& left, T const& right) const { return std::min(left, right); }
};

}
