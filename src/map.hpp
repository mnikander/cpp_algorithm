#pragma once

#include <algorithm>
#include <vector>
#include "functional.hpp"
#include "size.hpp"

namespace nv {

template<typename T, typename UnaryOp>
auto map(std::vector<T> const& left, UnaryOp op)
    -> std::vector<decltype(op(T{}))>
{
    std::vector<decltype(op(T{}))> result(size(left));
    std::transform(left.cbegin(), left.cend(), result.begin(), op);
    return result;
}

template <typename T, typename BinaryOp>
auto map(T left, BinaryOp op, T right)
    -> decltype(op(T{}, T{}))
{
    return op(left, right);
}

template <typename T, typename BinaryOp>
auto map(T left, BinaryOp op, std::vector<T> const& right)
    -> std::vector<decltype(op(T{}, T{}))>
{
    std::vector<T> result(size(right));
    std::transform(right.cbegin(), right.cend(), result.begin(), [op, &left](T const& x){ return op(left, x); });
    return result;
}

template <typename T, typename BinaryOp>
auto map(std::vector<T> const& left, BinaryOp op, T right)
    -> std::vector<decltype(op(T{}, T{}))>
{
    std::vector<T> result(size(left));
    std::transform(left.cbegin(), left.cend(), result.begin(), [op, &right](T const& x){ return op(x, right); });
    return result;
}

template <typename T, typename BinaryOp>
auto map(std::vector<T> const& left, BinaryOp op, std::vector<T> const& right)
    -> std::vector<decltype(op(T{}, T{}))>
{
    assert(size(left) == size(right));
    std::vector<T> result(size(left));
    std::transform(left.cbegin(), left.cend(), right.cbegin(), result.begin(), op);
    return result;
}

}

namespace xpr {

template <typename Operation, typename R>
struct map : Expression<map<Operation, R>>
{
    map(Operation op, R const& right) : _op{op}, _right{right} {}

    template<typename T>
    std::vector<T> operator()(std::vector<T> const& left) const { return nv::map(left, _op, _right); }

    template<typename T>
    auto operator()(T const& left) const { return nv::map(left, _op, _right); }

    Operation const _op;
    R const& _right;
};

template <typename Operation>
struct map<Operation, NoRightArgument> : Expression<map<Operation, NoRightArgument>>
{
    map(Operation op) : _op{op} {}

    template<typename T>
    std::vector<T> operator()(std::vector<T> const& v) const { return nv::map(v, _op); }

    const Operation _op;
};

}
