// Copyright (c) 2024, Marco Nikander

#pragma once

#include <algorithm> // maximum
#include <functional> // plus
#include <limits>
#include <numeric> // reduce
#include <vector>
#include "../functional.hpp"

namespace { // anonymous namespace

template<typename T, typename BinaryOp> struct ReductionTraits{};
template<typename T>                    struct ReductionTraits<T, nv::Plus>  { static constexpr T init = T{0}; };
template<typename T>                    struct ReductionTraits<T, nv::Multiply> { static constexpr T init = T{1}; };
template<typename T>                    struct ReductionTraits<T, nv::Maximum>   { static constexpr T init = std::numeric_limits<T>::lowest(); };
template<typename T>                    struct ReductionTraits<T, nv::Minimum>   { static constexpr T init = std::numeric_limits<T>::maximum(); };

// TODO: do I want to implement alternating minus and division reductions? is that even possible with a normal reduction?
//       the alternating minus might be useful for calculating determinants

struct DefaultAccumulator{};

} // anonymous namespace

namespace nv {

// having 'op' as an argument, like the STL, and not just as a template argument, enables easy use of lambda expressions
template<typename T, typename BinaryOp>
T reduce(std::vector<T> v, BinaryOp op)
{
    return std::reduce(v.cbegin(), v.cend(), ReductionTraits<T, BinaryOp>::init, op);
}

template<typename T, typename BinaryOp, typename Accumulator>
T reduce(std::vector<T> v, BinaryOp op, Accumulator initialValue)
{
    return std::reduce(v.cbegin(), v.cend(), initialValue, op);
}

}
