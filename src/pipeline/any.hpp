#pragma once

#include <algorithm>
#include <cstdint>
#include <functional>
#include <vector>
#include "../meta/expression.hpp"
#include "size.hpp"
#include "../simple/any.hpp"

namespace xpr {

// functors
template <typename UnaryPred>
struct UnaryAny : Expression<UnaryAny<UnaryPred>>
{
    UnaryAny(UnaryPred pred) : _pred{pred} {}

    template <typename T>
    bool operator()(std::vector<T> const& left) const { return nv::any(left, _pred); }

    UnaryPred const _pred;
};

template <typename BinaryPred, typename R>
struct BinaryAny : Expression<BinaryAny<BinaryPred, R>>
{
    BinaryAny(BinaryPred pred, std::vector<R> const& right) : _pred{pred}, _right{right} {}

    template <typename L>
    bool operator()(std::vector<L> const& left) const { return nv::any(left, _pred, _right); }

    BinaryPred const _pred;
    std::vector<R> const _right;
};

// overloaded functions to retrieve the correct function object
template <typename UnaryPred>
UnaryAny<UnaryPred> any(UnaryPred pred)
{
    return UnaryAny<UnaryPred>{pred};
}

template <typename BinaryPred, typename R>
BinaryAny<BinaryPred, R> any(BinaryPred pred, std::vector<R> const& right)
{
    return BinaryAny<BinaryPred, R>{pred, right};
}

}
