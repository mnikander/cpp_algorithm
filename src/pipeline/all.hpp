// Copyright (c) 2024, Marco Nikander

#pragma once

#include <algorithm>
#include <functional>
#include <vector>
#include "../meta/expression.hpp"
#include "../simple/all.hpp"

namespace xpr {

// functors
template <typename UnaryPred>
struct UnaryAll : Expression<UnaryAll<UnaryPred>>
{
    UnaryAll(UnaryPred pred) : _pred{pred} {}

    template <typename T>
    bool operator()(std::vector<T> const& left) const { return nv::all(left, _pred); }

    UnaryPred const _pred;
};

template <typename BinaryPred, typename R>
struct BinaryAll : Expression<BinaryAll<BinaryPred, R>>
{
    BinaryAll(BinaryPred pred, std::vector<R> const& right) : _pred{pred}, _right{right} {}

    template <typename L>
    bool operator()(std::vector<L> const& left) const { return nv::all(left, _pred, _right); }

    BinaryPred const _pred;
    std::vector<R> const _right;
};

// overloaded functions to retrieve the correct function object
template <typename UnaryPred>
UnaryAll<UnaryPred> all(UnaryPred pred)
{
    return UnaryAll<UnaryPred>{pred};
}

template <typename BinaryPred, typename R>
BinaryAll<BinaryPred, R> all(BinaryPred pred, std::vector<R> const& right)
{
    return BinaryAll<BinaryPred, R>{pred, right};
}

}
