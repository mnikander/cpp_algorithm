#pragma once

#include <algorithm>
#include <utility>
#include <vector>
#include "size.hpp"

namespace nv {

template<typename L, typename R>
auto zip(std::vector<L> const& left, std::vector<R> const& right) -> std::vector<std::pair<L, R>> 
{
    uint64_t count = std::min(size(left), size(right));

    std::vector<std::pair<L, R>> result(count);
    std::transform(left.cbegin(), left.cbegin() + count, right.cbegin(), result.begin(), [](L const& l, R const& r) { return std::make_pair(l, r); });
    return result;
}

}
