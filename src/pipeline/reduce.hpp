#pragma once

#include <algorithm> // maximum
#include <functional> // plus
#include <limits>
#include <numeric> // reduce
#include <vector>
#include "../functional.hpp"
#include "../simple/reduce.hpp"

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
