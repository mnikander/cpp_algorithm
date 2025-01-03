// Copyright (c) 2024, Marco Nikander

#pragma once

#include <algorithm>
#include <cassert>
#include <vector>
#include "reverse.hpp"
#include "size.hpp"
#include "../simple/rotate.hpp"

namespace xpr {

struct rotate : Expression<rotate>
{
    rotate(int count) : _count{count} {}

    template<typename T>
    std::vector<T> operator()(std::vector<T> const& v) const { return nv::rotate(v, _count); }

    const int _count;
};

struct rotate_last : Expression<rotate_last>
{
    rotate_last(int count) : _count{count} {}

    template<typename T>
    std::vector<T> operator()(std::vector<T> const& v) const { return nv::rotate_last(v, _count); }

    const int _count;

};

}
