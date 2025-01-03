#pragma once

#include <algorithm>
#include <cassert>
#include <vector>
#include "../meta/expression.hpp"
#include "../simple/repeat.hpp"

namespace xpr {

struct repeat : Expression<repeat>
{
    repeat(int count) : _count{count} {}

    template<typename T>
    std::vector<T> operator()(T value) const { return nv::repeat(value, _count); }

    int const _count;
};

}
