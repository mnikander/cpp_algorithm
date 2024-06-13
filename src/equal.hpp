#pragma once

#include <algorithm>
#include <functional>
#include <vector>
#include "meta/expression.hpp"
#include "size.hpp"

namespace nv {

template<typename T, typename U>
bool equal(std::vector<T> const& left, std::vector<U> const& right)
{
    return std::equal(left.cbegin(), left.cend(), right.cbegin(), right.cend());
}

template<typename T, typename BinaryPred, typename U>
bool equal(std::vector<T> const& left, BinaryPred op, std::vector<U> const& right)
{
    return std::equal(left.cbegin(), left.cend(), right.cbegin(), right.cend(), op);
}

}

namespace xpr {

// functors
template <typename BinaryPred, typename T>
struct EqualPred : Expression<EqualPred<BinaryPred, T>>
{
    EqualPred(BinaryPred pred, std::vector<T> const& right) : _pred{pred}, _right{right} {}

    bool operator()(std::vector<T> const& left) const { return nv::equal(left, _pred, _right); }

    BinaryPred const _pred;
    std::vector<T> const _right;
};

template <typename T>
struct EqualSimple : Expression<EqualSimple<T>>
{
    EqualSimple(std::vector<T> const& right) : _right{right} {}

    bool operator()(std::vector<T> const& left) const { return nv::equal(left, _right); }

    std::vector<T> const _right;
};

// overloaded functions to retrieve the correct Functor
template <typename BinaryPred, typename T>
EqualPred<BinaryPred, T> equal(BinaryPred pred, std::vector<T> const& right)
{
    return EqualPred<BinaryPred, T>{pred, right};
}

template <typename T>
EqualSimple<T> equal(std::vector<T> const& right)
{
    return EqualSimple<T>{right};
}


}
