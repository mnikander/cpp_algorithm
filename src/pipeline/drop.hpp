#pragma once

#include <algorithm>
#include <cassert>
#include <vector>
#include "../meta/expression.hpp"
#include "size.hpp"
#include "../simple/drop.hpp"

namespace xpr {

struct drop : Expression<drop>
{
    drop(int count) : _count{count} {}

    template<typename T>
    std::vector<T> operator()(std::vector<T> const& v) const { return nv::drop(v, _count); }

    const int _count;
};

struct drop_last : Expression<drop_last>
{
    drop_last(int count) : _count{count} {}

    template<typename T>
    std::vector<T> operator()(std::vector<T> const& v) const { return nv::drop_last(v, _count); }

    const int _count;

};

}
