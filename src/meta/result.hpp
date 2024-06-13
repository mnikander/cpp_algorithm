#pragma once

#include <array>
#include <vector>

namespace meta {

template<typename O, typename I>
std::vector<O> makeContainer(std::vector<I> const& input)
{
    return std::vector<O>(input.size());
}

template<typename O, typename I, size_t N>
std::array<O, N> makeContainer(std::array<I, N> const& input)
{
    return std::array<O, N>();
}

// this stuff below does not work, since: `Result<O, std::vector<T>>` is not the same type as
// `std::vector<T>`, but is instead a subclass thereof. Inheriting from std::array may also cause problems,
// depending on the C++ version

// template<typename O, typename InputRange>
// struct Result{};

// template<typename O, typename T>
// struct Result<O, std::vector<T>> : public std::vector<O> {};

// template<typename O, typename T, size_t N>
// struct Result<std::array<T, N>, O> : public std::array<O, N> {};

// traits class solution to determine the type for the return value container
template<typename O, typename InputRange>
struct ResultTraits{};

template<typename O, typename I>
struct ResultTraits<O, std::vector<I>>
{
    using Type = std::vector<O>;
};

    template<typename O, typename I, size_t N>
struct ResultTraits<O, std::array<I, N>>
{
    using Type = std::array<O, N>;
};

}
