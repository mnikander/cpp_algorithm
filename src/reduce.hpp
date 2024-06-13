#pragma once

#include <algorithm> // max
#include <functional> // plus
#include <limits>
#include <numeric> // reduce
#include <vector>
#include "arithmetic.hpp"

namespace { // anonymous namespace

template<typename T, typename OperatorTag> struct ReductionTraits{};
template<typename T> struct ReductionTraits<T, nv::Plus<T>> { static constexpr T init = T{0}; };
template<typename T> struct ReductionTraits<T, nv::Max<T>> { static constexpr T init = std::numeric_limits<T>::lowest(); };
template<typename T> struct ReductionTraits<T, nv::Min<T>> { static constexpr T init = std::numeric_limits<T>::max(); };

// TODO: do I want to implement alternating minus and division reductions? is that even possible with a normal reduction?
//       the alternating minus might be useful for calculating determinants

} // anonymous namespace

namespace nv {

// having 'op' as an argument, like the STL, and not just as a template argument, enables easy use of lambda expressions
template<typename T, typename BinaryOp>
T reduce(std::vector<T> v, BinaryOp op, T initialValue = ReductionTraits<T, BinaryOp>::init)
{
    return std::reduce(v.cbegin(), v.cend(), initialValue, op);
}

}