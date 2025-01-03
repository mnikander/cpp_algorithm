// naive implementation of 'gather' from nvidia thrust library
// https://nvidia.github.io/cccl/thrust/api/groups/group__gathering.html

#pragma once

#include <cassert>
#include <vector>
#include "../meta/expression.hpp"
#include "size.hpp"

namespace nv {

template<typename T>
std::vector<T> gather(std::vector<T> const& data, std::vector<int> const& order)
{
    assert(size(order) <= size(data));

    std::vector<T> result(size(order));

    for(int i = 0; i < size(order); ++i)
    {
        result[i] = data[order[i]];
    }
    
    return result;
}

}
