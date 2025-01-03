// Copyright (c) 2024, Marco Nikander

#pragma once

#include <algorithm>
#include <vector>
#include "../meta/expression.hpp"
#include "size.hpp"
#include "../simple/catenate.hpp"

namespace xpr {

template <typename T>
struct catenate : Expression<catenate<T>>
{
    catenate(T const& right) : _right{right} {}

    std::vector<T> operator()(std::vector<T> const& left) const { return nv::catenate(left, _right); }
    std::vector<T> operator()(T const& left) const { return nv::catenate(left, _right); }

    const T _right;
};

// template specialization for std::vector
template <typename T>
struct catenate<std::vector<T>> : Expression<catenate<std::vector<T>>>
{
    catenate(std::vector<T> const& right) : _right{right} {}

    std::vector<T> operator()(std::vector<T> const& left) const { return nv::catenate(left, _right); }
    std::vector<T> operator()(T const& left) const { return nv::catenate(left, _right); }

    const std::vector<T> _right;
};

}
