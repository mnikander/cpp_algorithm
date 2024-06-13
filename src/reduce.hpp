#pragma once

#include <algorithm> // max
#include <functional> // plus
#include <limits>
#include <numeric> // reduce
#include <vector>
#include "functional.hpp"

namespace { // anonymous namespace

template<typename T, typename BinaryOp> struct ReductionTraits{};
template<typename T>                    struct ReductionTraits<T, nv::Plus>  { static constexpr T init = T{0}; };
template<typename T>                    struct ReductionTraits<T, nv::Times> { static constexpr T init = T{1}; };
template<typename T>                    struct ReductionTraits<T, nv::Max>   { static constexpr T init = std::numeric_limits<T>::lowest(); };
template<typename T>                    struct ReductionTraits<T, nv::Min>   { static constexpr T init = std::numeric_limits<T>::max(); };

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

namespace xpr {
namespace {

template <typename Operation, typename A>
struct ReduceWithManualAccumulator : Expression<ReduceWithManualAccumulator<Operation, A>>
{
    ReduceWithManualAccumulator(Operation op, A const& init) : _op{op}, _init{init} {}

    template<typename T>
    auto operator()(std::vector<T> const& left) const { return nv::reduce(left, _op, _init); }

    Operation const _op;
    A const& _init;
};

template <typename Operation>
struct ReduceWithDefaultAccumulator : Expression<ReduceWithDefaultAccumulator<Operation>>
{
    ReduceWithDefaultAccumulator(Operation op) : _op{op} {}

    template<typename T>
    auto operator()(std::vector<T> const& v) const { return nv::reduce(v, _op); }

    Operation const _op;
};
}

template <typename Operation>
ReduceWithDefaultAccumulator<Operation> reduce(Operation op) { return ReduceWithDefaultAccumulator(op); }

template <typename Operation, typename R>
ReduceWithManualAccumulator<Operation, R> reduce(Operation op, R const& right) { return ReduceWithManualAccumulator(op, right); }

}
