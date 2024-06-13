#pragma once

#include <vector>

namespace xpr {

template <typename E>
struct Expression{};

// element | expression()
template<typename T, typename E>
auto operator|(T const& element, Expression<E> const& right) -> decltype((*static_cast<const E*>(&right))(element))
{
    const auto expression = *(static_cast<const E*>(&right)); // downcasting to the exact type of expression via CRTP
    return (expression.operator()(element));
}

// vector | expression()
template<typename T, typename E>
auto operator|(std::vector<T> const& v, Expression<E> const& right) -> decltype((*static_cast<const E*>(&right))(v))
{
    const auto expression = *(static_cast<const E*>(&right)); // downcasting to the exact type of expression via CRTP
    return (expression.operator()(v));
}

}
