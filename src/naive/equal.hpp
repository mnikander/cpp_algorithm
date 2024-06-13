#pragma once

#include <algorithm>
#include <functional>
#include <vector>
#include "size.hpp"

namespace nv {

template<typename T, typename U>
bool equal(std::vector<T> const& left, std::vector<U> const& right)
{
    return std::equal(left.cbegin(), left.cend(), right.cbegin(), right.cend());
}

template<typename T, typename U, typename BinaryPred>
bool equal(std::vector<T> const& left, std::vector<U> const& right, BinaryPred op)
{
    return std::equal(left.cbegin(), left.cend(), right.cbegin(), right.cend(), op);
}

}
