#pragma once

#include <array>
#include <vector>

namespace meta {

template<typename InputRange, typename O>
struct ResultFactory{};

template<typename I, typename O>
struct ResultFactory<std::vector<I>, O>
{
    using Container = std::vector<O>;

    std::vector<O> operator()(std::vector<I> const& input)
    {
        return std::vector<O>(input.size());
    }
};

template<typename I, size_t N, typename O>
struct ResultFactory<std::array<I, N>, O>
{
    using Container = std::array<O, N>;

    std::array<O, N> operator()(std::array<I, N> const& input)
    {
        return std::array<O, N>();
    }
};

}
