#pragma once

#include <algorithm>
#include <cassert>
#include <vector>
#include "size.hpp"

namespace naive {

template<typename T>
std::vector<T> drop(std::vector<T> const& v, int count)
{
    assert(0 <= count);
    assert(count <= size(v));
    
    std::vector<T> result(size(v) - count);
    std::copy(v.cbegin() + count, v.cend(), result.begin());
    return result;
}

}
