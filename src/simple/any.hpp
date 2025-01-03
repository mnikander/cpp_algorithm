// Copyright (c) 2024, Marco Nikander

#pragma once

#include <algorithm>
#include <cstdint>
#include <functional>
#include <vector>
#include "../meta/expression.hpp"
#include "size.hpp"

namespace nv {

template<typename L, typename UnaryPred>
bool any(std::vector<L> const& left, UnaryPred pred)
{
    return std::any_of(left.cbegin(), left.cend(), pred);
}

template<typename L, typename BinaryPred, typename R>
bool any(std::vector<L> const& left, BinaryPred pred, std::vector<R> const& right)
{
    int32_t count = std::min(size(left), size(right));
    return !std::equal(left.cbegin(), left.cbegin()+count, right.cbegin(), right.cbegin()+count, [pred](auto l, auto r){ return !pred(l, r); });
}

}
