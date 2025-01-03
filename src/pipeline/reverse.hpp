#pragma once

#include <algorithm>
#include <vector>
#include "../meta/expression.hpp"
#include "../simple/reverse.hpp"

namespace xpr {

struct reverse : Expression<reverse>
{
    template <typename T>
    std::vector<int> operator()(std::vector<T> const& v) const { return nv::reverse(v); }
};

}
