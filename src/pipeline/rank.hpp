// Copyright (c) 2024, Marco Nikander

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
