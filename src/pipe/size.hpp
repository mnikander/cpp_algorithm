#pragma once

#include <cstdint>
#include <vector>
#include "../naive/size.hpp"
#include "expression.hpp"

namespace pn {

struct size : Expression<size>
{
    template <typename T>
    int32_t operator()(std::vector<T> const& v) const { return nv::size(v); }
};

}
