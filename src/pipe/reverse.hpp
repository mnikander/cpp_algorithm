#pragma once

#include <cstdint>
#include <vector>
#include "../naive/reverse.hpp"
#include "expression.hpp"

namespace pn {

struct Reverse : Expression<Reverse>
{
    template <typename T>
    std::vector<int> operator()(std::vector<T> const& v) const { return nv::reverse(v); }
};

Reverse reverse(); // has no template parameters, so it had to be defined in a cpp file

}
