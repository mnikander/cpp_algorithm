// Copyright (c) 2024, Marco Nikander
// gives the rank of an object, note that currently only rank 0 and 1 are supported, do not use this with nested vectors

#pragma once

#include <cstdint>
#include <vector>
#include "../meta/expression.hpp"
#include "../simple/rank.hpp"

namespace xpr {

struct rank : Expression<rank>
{
    template <typename T>
    int32_t operator()(T const& v) const { return nv::rank(v); }

    template <typename T>
    int32_t operator()(std::vector<T> const& v) const { return nv::rank(v); }
};

}
