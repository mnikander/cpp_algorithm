#pragma once

#include <cstdint>
#include <vector>
#include "../meta/expression.hpp"

namespace nv {

template<typename T>
int32_t size(T const& v)
{
    return 1;
}

template<typename T>
int32_t size(std::vector<T> const& v)
{
    return static_cast<int32_t>(v.size());
}

}
