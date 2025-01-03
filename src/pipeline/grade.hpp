// Copyright (c) 2024, Marco Nikander

#pragma once

#include <algorithm>
#include <vector>
#include "../meta/expression.hpp"
#include "iota.hpp"
#include "size.hpp"
#include "../simple/grade.hpp"

namespace xpr {

template <typename BinaryOp>
struct grade : Expression<grade<BinaryOp>>
{
    grade(BinaryOp op) : _op{op} {}

    template<typename T>
    std::vector<int> operator()(std::vector<T> const& v) const { return nv::grade(v, _op); }

    BinaryOp const _op;
};

template <typename BinaryOp>
struct stable_grade : Expression<stable_grade<BinaryOp>>
{
    stable_grade(BinaryOp op) : _op{op} {}

    template<typename T>
    std::vector<int> operator()(std::vector<T> const& v) const { return nv::stable_grade(v, _op); }

    BinaryOp const _op;
};

}
