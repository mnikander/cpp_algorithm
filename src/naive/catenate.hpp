#pragma once

#include <algorithm>
#include <vector>
#include "size.hpp"

namespace naive {

template<typename T>
std::vector<T> catenate(std::vector<T> const& left, std::vector<T> const& right)
{
    std::vector<T> result(left);
    result.reserve(size(left) + size(right));
    result.insert(result.end(), right.cbegin(), right.cend());
    return result;
}

}
