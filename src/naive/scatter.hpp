// naive implementation of 'scatter' from nvidia thrust library
// https://nvidia.github.io/cccl/thrust/api/groups/group__scattering.html

#pragma once

#include <cassert>
#include <vector>
#include "size.hpp"

namespace naive {

template<typename T>
std::vector<T> scatter(std::vector<T> const& data, std::vector<int> const& order)
{
    assert(size(order) <= size(data));

    std::vector<T> result(size(order));

    for(int i = 0; i < size(order); ++i)
    {
        result[order[i]] = data[i];
    }
    
    return result;
}

}
