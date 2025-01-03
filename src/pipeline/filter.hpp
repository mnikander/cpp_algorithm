// Copyright (c) 2024, Marco Nikander

#pragma once

#include <algorithm>
#include <iterator>
#include <vector>
#include "../meta/expression.hpp"
#include "size.hpp"
#include "../simple/filter.hpp"

namespace xpr {

template <typename UnaryPred>
struct filter : Expression<filter<UnaryPred>>
{
    filter(UnaryPred pred) : _pred{pred} {}

    template<typename T>
    std::vector<T> operator()(std::vector<T> const& v) const { return nv::filter(v, _pred); }

    UnaryPred const _pred;
};

}
