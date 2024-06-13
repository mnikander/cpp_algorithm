#pragma once

#include <algorithm>
#include <vector>
#include "meta/expression.hpp"

namespace nv {

template<typename T>
std::vector<T> reverse(std::vector<T> v)
{    
    std::vector<T> result(v); // copy-constructor call
    std::reverse(result.begin(), result.end());
    return result;
}

}

namespace xpr {

struct reverse : Expression<reverse>
{
    template <typename T>
    std::vector<int> operator()(std::vector<T> const& v) const { return nv::reverse(v); }
};

}
