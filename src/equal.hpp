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

template<typename T, typename U, typename BinaryPred>
bool equal(std::vector<T> const& left, std::vector<U> const& right, BinaryPred op)
{
    return std::equal(left.cbegin(), left.cend(), right.cbegin(), right.cend(), op);
}

}

namespace xpr {

// functors
template <typename T, typename BinaryPred>
struct EqualPred : Expression<EqualPred<T, BinaryPred>>
{
    EqualPred(std::vector<T> const& right, BinaryPred pred) : _right{right}, _pred{pred} {}

    bool operator()(std::vector<T> const& left) const { return nv::equal(left, _right, _pred); }

    std::vector<T> const _right;
    BinaryPred const _pred;
};

template <typename T>
struct EqualSimple : Expression<EqualSimple<T>>
{
    EqualSimple(std::vector<T> const& right) : _right{right} {}

    bool operator()(std::vector<T> const& left) const { return nv::equal(left, _right); }

    std::vector<T> const _right;
};

// overloaded functions to retrieve the correct Functor
template <typename T, typename BinaryPred>
EqualPred<T, BinaryPred> equal(std::vector<T> const& right, BinaryPred pred)
{
    return EqualPred<T, BinaryPred>{right, pred};
}

template <typename T>
EqualSimple<T> equal(std::vector<T> const& right)
{
    return EqualSimple<T>{right};
}


}
