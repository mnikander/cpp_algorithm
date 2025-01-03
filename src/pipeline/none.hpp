// Copyright (c) 2024, Marco Nikander

#pragma once

#include <algorithm>
#include <cstdint>
#include <functional>
#include <vector>
#include "../meta/expression.hpp"
#include "size.hpp"
#include "../simple/none.hpp"

namespace xpr {

// functors
template <typename UnaryPred>
struct UnaryNone : Expression<UnaryNone<UnaryPred>>
{
    UnaryNone(UnaryPred pred) : _pred{pred} {}

    template <typename T>
    bool operator()(std::vector<T> const& left) const { return nv::none(left, _pred); }

    UnaryPred const _pred;
};

template <typename BinaryPred, typename R>
struct BinaryNone : Expression<BinaryNone<BinaryPred, R>>
{
    BinaryNone(BinaryPred pred, std::vector<R> const& right) : _pred{pred}, _right{right} {}

    template <typename L>
    bool operator()(std::vector<L> const& left) const { return nv::none(left, _pred, _right); }

    BinaryPred const _pred;
    std::vector<R> const _right;
};

// overloaded functions to retrieve the correct function object
template <typename UnaryPred>
UnaryNone<UnaryPred> none(UnaryPred pred)
{
    return UnaryNone<UnaryPred>{pred};
}

template <typename BinaryPred, typename R>
BinaryNone<BinaryPred, R> none(BinaryPred pred, std::vector<R> const& right)
{
    return BinaryNone<BinaryPred, R>{pred, right};
}

}
