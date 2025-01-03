// Copyright (c) 2024, Marco Nikander

#pragma once

#include <algorithm>
#include <vector>
#include "../meta/expression.hpp"
#include "../functional.hpp"
#include "size.hpp"
#include "../simple/map.hpp"

namespace xpr {
namespace {

template <typename Operation>
struct UnaryMap : Expression<UnaryMap<Operation>>
{
    explicit UnaryMap(Operation op, NoRightArgument = NoRightArgument{}) : _op{op} {}

    template<typename T>
    std::vector<T> operator()(std::vector<T> const& v) const { return nv::map(v, _op); }

    Operation const _op;
};

template <typename Operation, typename R>
struct BinaryMap : Expression<BinaryMap<Operation, R>>
{
    BinaryMap(Operation op, R const& right) : _op{op}, _right{right} {}

    template<typename T>
    std::vector<T> operator()(std::vector<T> const& left) const { return nv::map(left, _op, _right); }

    template<typename T>
    auto operator()(T const& left) const { return nv::map(left, _op, _right); }

    Operation const _op;
    R const& _right;
};
}

template <typename Operation>
UnaryMap<Operation> map(Operation op) { return UnaryMap(op); }

template <typename Operation, typename R>
BinaryMap<Operation, R> map(Operation op, R const& right) { return BinaryMap(op, right); }

}
