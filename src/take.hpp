#pragma once

#include <algorithm>
#include <cassert>
#include <vector>
#include "size.hpp"

namespace nv {

template<typename T>
std::vector<T> take(std::vector<T> const& v, int count)
{
    assert(0 <= count);
    assert(count <= size(v));

    std::vector<T> result(count);
    std::copy(v.cbegin(), v.cbegin() + count, result.begin());
    return result;
}

template<typename T>
std::vector<T> take_last(std::vector<T> const& v, int count)
{
    assert(0 <= count);
    assert(count <= size(v));

    std::vector<T> result(count);
    std::copy(v.cend() - count, v.cend(), result.begin());
    return result;
}

}

namespace xpr {

struct take : Expression<take>
{
    take(int count) : _count{count} {}

    template<typename T>
    std::vector<T> operator()(std::vector<T> const& v) const { return nv::take(v, _count); }

    const int _count;
};

struct take_last : Expression<take_last>
{
    take_last(int count) : _count{count} {}

    template<typename T>
    std::vector<T> operator()(std::vector<T> const& v) const { return nv::take_last(v, _count); }

    const int _count;
};

}
