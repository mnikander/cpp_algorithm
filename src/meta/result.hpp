// Copyright (c) 2024, Marco Nikander

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

}
