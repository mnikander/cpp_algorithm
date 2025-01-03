// gives the rank of an object, note that currently only rank 0 and 1 are supported, do not use this with nested vectors

#pragma once

#include <cstdint>
#include <vector>
#include "../meta/expression.hpp"

namespace nv {

template<typename T>
int32_t rank(T const& v)
{
    return 0;
}

template<typename T>
int32_t rank(std::vector<T> const& v)
{
    return 1;
}

}
