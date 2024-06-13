#pragma once

#include <cstdint>
#include <vector>
#include "../naive/reverse.hpp"
#include "expression.hpp"

namespace pn {

struct reverse : Expression<reverse>
{
    template <typename T>
    std::vector<int> operator()(std::vector<T> const& v) const { return nv::reverse(v); }
};

}
