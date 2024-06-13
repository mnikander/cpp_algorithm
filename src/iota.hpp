#pragma once

#include <cassert>
#include <vector>
#include <numeric>
#include "meta/expression.hpp"

namespace nv {

template<typename T>
std::vector<T> iota(T firstValue, T lastValue)
{
    assert(lastValue >= firstValue);

    const size_t count = static_cast<size_t>(lastValue - firstValue);
    std::vector<T> result(count);
    std::iota(result.begin(), result.end(), firstValue);
    return result; // I hope copy-elision optimizes this out
    // TODO: how can I verify this? Perhaps with a wrapper around std::vector which prints in the copy-constructor?
}

template<typename T>
std::vector<T> iota(T lastValue)
{
    assert(lastValue >= 0);
    return iota(T{0}, lastValue);
}

}

namespace xpr {

// Since both arguments are of type T, there is no way to have a unary and binary version in xpr, because the free
// function call would take a single T as a parameter, and the free function which forwards to the constructor call
// would also take a single T as a parameter. Technically, I could enable both function overloads of nv::iota in xpr,
// with `using nv::iota;`, but the binary notation would be inconsistent with everything else in the xpr namespace,
// which would cause confusion, so I will stay consistent, and choose either the unary-only or binary-only notation.
//
// Since creating indices is a common use-case, I will stick to the APL convention of having iota as a single-argument
// function, which starts counting at 0. I could overload this later to take a single 'interval' and solve the problem
// that way, or switch to a binary-only implementation.

template <typename T>
std::vector<T> iota(T lastValue) { return nv::iota(lastValue); }

}
