// gives the rank of an object, note that currently only rank 0 and 1 are supported, do not use this with nested vectors

#pragma once

#include <vector>
#include "../common.hpp"

namespace nv {

template<typename T>
i64 rank(T const& v)
{
    return 0;
}

template<typename T>
i64 rank(std::vector<T> const& v)
{
    return 1;
}

}
