#pragma once

#include <algorithm>
#include <iterator>
#include <vector>
#include "size.hpp"

namespace nv {

template<typename T, typename UnaryPred>
std::vector<T> filter(std::vector<T> const& v, UnaryPred op)
{
    std::vector<T> result{};
    std::copy_if(v.cbegin(), v.cend(), std::back_inserter(result), op);
    return result;
}

}
