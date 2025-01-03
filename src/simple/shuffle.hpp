// Copyright (c) 2024, Marco Nikander

#pragma once

#include <algorithm>
#include <vector>

namespace nv {

// example initialization of g: 
//     std::mt19937 generator{std::random_device{}()};
template<typename T, typename RandomGenerator>
std::vector<T> shuffle(std::vector<T> const& v, RandomGenerator& g)
{
    std::vector<T> result = v;
    std::shuffle(result.begin(), result.end(), g);
    return result;
}

}
