#pragma once

#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>
#include "size.hpp"

namespace nv {

template<typename L, typename R>
auto zip(std::vector<L> const& left, std::vector<R> const& right) -> std::vector<std::pair<L, R>> 
{
    assert(size(left) <= size(right));

    std::vector<std::pair<L, R>> result(size(left));
    std::transform(left.cbegin(), left.cend(), right.cbegin(), result.begin(), [](L const& l, R const& r) { return std::make_pair(l, r); });
    return result;
}

}
