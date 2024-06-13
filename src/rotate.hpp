#pragma once

#include <algorithm>
#include <cassert>
#include <vector>
#include "reverse.hpp"
#include "size.hpp"

namespace nv {

template<typename T>
std::vector<T> rotate(std::vector<T> const& v, int count)
{
    assert(0 <= count);
    assert(count <= size(v));

    std::vector<T> result(v);
    std::rotate(result.begin(), result.begin() + count, result.end());
    return result;
}

template<typename T>
std::vector<T> rotate_last(std::vector<T> const& v, int count)
{
    assert(0 <= count);
    assert(count <= size(v));

    std::vector<T> result(v);
    std::rotate(result.rbegin(), result.rbegin() + count, result.rend());
    return result;
}

}

namespace xpr {

struct rotate : Expression<rotate>
{
    rotate(int count) : _count{count} {}

    template<typename T>
    std::vector<T> operator()(std::vector<T> const& v) const { return nv::rotate(v, _count); }

    const int _count;
};

struct rotate_last : Expression<rotate_last>
{
    rotate_last(int count) : _count{count} {}

    template<typename T>
    std::vector<T> operator()(std::vector<T> const& v) const { return nv::rotate_last(v, _count); }

    const int _count;

};

}
