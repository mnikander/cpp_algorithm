#pragma once

#include <vector>

namespace pn {

template <typename E>
struct Expression{};

// template <typename T>
// class Vector : public Expression<Vector<T>>
// {
// public:    
//     Vector(std::vector<T> const& v) : _data(v) {}

//     template<typename E>
//     Vector(const Expression<E>& expr) {}

//     decltype(auto) operator()() const {return _data; }

// private:
//     std::vector<T> _data{0};
// };

// TODO: get this working for vector-valued results as well -- I may have to distinguish 2 kinds of expressions here
// template<typename T, typename E>
// std::vector<T> operator|(std::vector<T> const& v, Expression<E> const& right)
// {
//     const auto expression = *(static_cast<const E*>(&right)); // downcasting to the exact type of expression via CRTP
//     return (expression.operator()(v));
// }

template<typename T, typename E>
auto operator|(std::vector<T> const& v, Expression<E> const& right) -> decltype((*static_cast<const E*>(&right))(v))
{
    const auto expression = *(static_cast<const E*>(&right)); // downcasting to the exact type of expression via CRTP
    return (expression.operator()(v));
}

}
