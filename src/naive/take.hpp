#pragma once

#include <algorithm>
#include <cassert>
#include <vector>
#include "size.hpp"

namespace naive {

template<typename T>
std::vector<T> take(std::vector<T> const& v, int count)
{
    assert(0 <= count);
    assert(count <= size(v));

    std::vector<T> result(count);
    std::copy(v.cbegin(), v.cbegin() + count, result.begin());
    return result;
}

}
