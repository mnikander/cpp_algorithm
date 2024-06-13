#pragma once

#include <algorithm>
#include <iterator>
#include <vector>
#include "meta/expression.hpp"
#include "size.hpp"

namespace nv {

template<typename T, typename UnaryPred>
std::vector<T> filter(std::vector<T> const& v, UnaryPred op)
{
    std::vector<T> result{};
    std::copy_if(v.cbegin(), v.cend(), std::back_inserter(result), op);
    return result;
}

}

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
