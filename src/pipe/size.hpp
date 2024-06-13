#pragma once

#include <cstdint>
#include <vector>
#include "../naive/size.hpp"
#include "expression.hpp"

namespace pn {

struct Size : Expression<Size>
{
    template <typename T>
    int32_t operator()(std::vector<T> const& v) const { return nv::size(v); }
};

Size size(); // has no template parameters, so it had to be defined in a cpp file

}
