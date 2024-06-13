#pragma once

#include <algorithm>
#include <vector>

namespace naive {

template<typename T>
std::vector<T> catenate(std::vector<T> const& left, std::vector<T> const& right)
{
    std::vector<T> result(left);
    result.reserve(left.size() + right.size());
    result.insert(result.end(), right.cbegin(), right.cend());
    return result;
}

}
