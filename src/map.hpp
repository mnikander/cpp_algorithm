#pragma once

#include <algorithm>
#include <vector>
#include "functional_tags.hpp"
#include "functional_dispatch.hpp"
#include "size.hpp"

namespace nv {

template<typename T, typename UnaryOp>
auto map(std::vector<T> const& left, UnaryOp op) -> std::vector<decltype(op(T{}))>
{
    std::vector<decltype(op(T{}))> result(size(left));
    std::transform(left.cbegin(), left.cend(), result.begin(), op);
    return result;
}

template <typename T, typename BinaryOp>
auto map(T left, BinaryOp op, std::vector<T> const& right) -> std::vector<decltype(op(T{}, T{}))>
{
    std::vector<T> result(size(right));
    std::transform(right.cbegin(), right.cend(), result.begin(), [op, &left](T const& x){ return op(left, x); });
    return result;
}

template <typename T, typename BinaryOp>
auto map(std::vector<T> const& left, BinaryOp op, T right) -> std::vector<decltype(op(T{}, T{}))>
{
    std::vector<T> result(size(left));
    std::transform(left.cbegin(), left.cend(), result.begin(), [op, &right](T const& x){ return op(x, right); });
    return result;
}

template <typename T, typename BinaryOp>
auto map(std::vector<T> const& left, BinaryOp op, std::vector<T> const& right) -> std::vector<decltype(op(T{}, T{}))>
{
    assert(size(left) == size(right));
    std::vector<T> result(size(left));
    std::transform(left.cbegin(), left.cend(), right.cbegin(), result.begin(), op);
    return result;
}

template <typename T, typename BinaryOp>
auto map(std::vector<T> const& left, meta::Tag<BinaryOp> tag, std::vector<T> const& right) -> std::vector<decltype(meta::dispatch(*(static_cast<const BinaryOp*>(&tag)), T{})(T{}, T{}))>
{
    assert(size(left) == size(right));
    std::vector<T> result(size(left));
    std::transform(left.cbegin(), left.cend(), right.cbegin(), result.begin(), meta::dispatch(*(static_cast<const BinaryOp*>(&tag)), T{}));
    return result;
}

}

namespace xpr {

// TODO

}
