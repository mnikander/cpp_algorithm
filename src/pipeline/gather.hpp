// Copyright (c) 2024, Marco Nikander
// naive implementation of 'gather' from nvidia thrust library
// https://nvidia.github.io/cccl/thrust/api/groups/group__gathering.html

#pragma once

#include <cassert>
#include <vector>
#include "../meta/expression.hpp"
#include "size.hpp"
#include "../simple/gather.hpp"

namespace xpr {

struct gather : Expression<gather>
{
    gather(std::vector<int> const& order) : _order{order} {}

    template<typename T>
    std::vector<T> operator()(std::vector<T> const& v) const { return nv::gather(v, _order); }

    std::vector<int> const _order;
};

}
