#pragma once

#include <algorithm>
#include <vector>

namespace naive {

template<typename T>
std::vector<T> reverse(std::vector<T> v)
{    
    std::vector<T> result(v); // copy-constructor call
    std::reverse(result.begin(), result.end());
    return result;
}

}
