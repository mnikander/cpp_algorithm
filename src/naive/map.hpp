#pragma once

#include <algorithm>
#include <vector>
#include "size.hpp"

namespace nv {

template<typename T, typename UnaryOp>
auto map(std::vector<T> const& data, UnaryOp op) -> std::vector<decltype(op(T{}))>
{
    std::vector<decltype(op(T{}))> result(size(data));
    std::transform(data.cbegin(), data.cend(), result.begin(), op);
    return result;
}

}