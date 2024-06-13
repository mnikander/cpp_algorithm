#pragma once

#include <algorithm>
#include <cassert>
#include <vector>
#include "meta/expression.hpp"

namespace nv {

template<typename T>
std::vector<T> repeat(T value, int count)
{
    assert(count >= 0);
    std::vector<T> result(count);
    std::fill(result.begin(), result.end(), value);
    return result;
}

}

namespace xpr {

struct repeat : Expression<repeat>
{
    repeat(int count) : _count{count} {}

    template<typename T>
    std::vector<T> operator()(T value) const { return nv::repeat(value, _count); }

    int const _count;
};

}
