#pragma once

#include <cstdint>
#include <vector>
#include "expression.hpp"

namespace nv {

template<typename T>
int32_t size(std::vector<T> const& v)
{
    return static_cast<int32_t>(v.size());
}

}

namespace xpr {

struct size : Expression<size>
{
    template <typename T>
    int32_t operator()(std::vector<T> const& v) const { return nv::size(v); }
};

}
