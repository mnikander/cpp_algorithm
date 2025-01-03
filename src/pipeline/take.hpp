#pragma once

#include <algorithm>
#include <cassert>
#include <vector>
#include "size.hpp"
#include "../simple/take.hpp"

namespace xpr {

struct take : Expression<take>
{
    take(int count) : _count{count} {}

    template<typename T>
    std::vector<T> operator()(std::vector<T> const& v) const { return nv::take(v, _count); }

    const int _count;
};

struct take_last : Expression<take_last>
{
    take_last(int count) : _count{count} {}

    template<typename T>
    std::vector<T> operator()(std::vector<T> const& v) const { return nv::take_last(v, _count); }

    const int _count;
};

}
