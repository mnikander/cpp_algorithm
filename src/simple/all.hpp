// Copyright (c) 2024, Marco Nikander

#pragma once

#include <algorithm>
#include <functional>
#include <vector>
#include "../meta/expression.hpp"
#include "size.hpp"

namespace nv {

template<typename L, typename UnaryPred>
bool all(std::vector<L> const& left, UnaryPred pred)
{
    return std::all_of(left.cbegin(), left.cend(), pred);
}

template<typename L, typename BinaryPred, typename R>
bool all(std::vector<L> const& left, BinaryPred pred, std::vector<R> const& right)
{
    return std::equal(left.cbegin(), left.cend(), right.cbegin(), right.cend(), pred);
}

}
