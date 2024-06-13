#pragma once

#include <algorithm>
#include <cassert>
#include <vector>
#include "meta/expression.hpp"
#include "size.hpp"

namespace nv {

template<typename T>
std::vector<T> drop(std::vector<T> const& v, int count)
{
    assert(0 <= count);
    assert(count <= size(v));
    
    std::vector<T> result(size(v) - count);
    std::copy(v.cbegin() + count, v.cend(), result.begin());
    return result;
}


template<typename T>
std::vector<T> drop_last(std::vector<T> const& v, int count)
{
    assert(0 <= count);
    assert(count <= size(v));

    std::vector<T> result(size(v) - count);
    std::copy(v.cbegin(), v.cend() - count, result.begin());
    return result;
}

}

namespace xpr {

struct drop : Expression<drop>
{
    drop(int count) : _count{count} {}

    template<typename T>
    std::vector<T> operator()(std::vector<T> const& v) const { return nv::drop(v, _count); }

    const int _count;
};

struct drop_last : Expression<drop_last>
{
    drop_last(int count) : _count{count} {}

    template<typename T>
    std::vector<T> operator()(std::vector<T> const& v) const { return nv::drop_last(v, _count); }

    const int _count;

};

}
