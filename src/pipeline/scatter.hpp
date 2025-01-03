// naive implementation of 'scatter' from nvidia thrust library
// https://nvidia.github.io/cccl/thrust/api/groups/group__scattering.html

#pragma once

#include <cassert>
#include <vector>
#include "../meta/expression.hpp"
#include "size.hpp"
#include "../simple/scatter.hpp"

namespace xpr {

struct scatter : Expression<scatter>
{
    scatter(std::vector<int> const& order) : _order{order} {}

    template<typename T>
    std::vector<T> operator()(std::vector<T> const& v) const { return nv::scatter(v, _order); }

    std::vector<int> const _order;
};

}
