#pragma once

#include <cstdint>
#include <vector>
#include "../meta/expression.hpp"
#include "../simple/size.hpp"

namespace xpr {

struct size : Expression<size>
{
    template <typename T>
    int32_t operator()(T const& v) const { return nv::size(v); }

    template <typename T>
    int32_t operator()(std::vector<T> const& v) const { return nv::size(v); }
};

}
