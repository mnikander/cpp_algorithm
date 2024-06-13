#pragma once

#include <vector>

namespace xpr {

template <typename E>
struct Expression{};

template<typename T, typename E>
auto operator|(std::vector<T> const& v, Expression<E> const& right) -> decltype((*static_cast<const E*>(&right))(v))
{
    const auto expression = *(static_cast<const E*>(&right)); // downcasting to the exact type of expression via CRTP
    return (expression.operator()(v));
}

}
