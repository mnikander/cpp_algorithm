// Copyright (c) 2024, Marco Nikander

#pragma once

#include <algorithm>
#include <cassert>
#include <vector>
#include "../meta/expression.hpp"
#include "size.hpp"

namespace nv {

template<typename T>
std::vector<T> drop(std::vector<T> const& v, int count)
{
    assert(0 <= count);
    assert(count <= size(v));
    
    std::vector<T> result(size(v) - count);
    std::copy(v.cbegin() + count, v.cend(), result.begin());
    return result;
}


template<typename T>
std::vector<T> drop_last(std::vector<T> const& v, int count)
{
    assert(0 <= count);
    assert(count <= size(v));

    std::vector<T> result(size(v) - count);
    std::copy(v.cbegin(), v.cend() - count, result.begin());
    return result;
}

}
