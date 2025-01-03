// Copyright (c) 2024, Marco Nikander

#pragma once

namespace xpr {

template <typename F, typename T>
auto operator<<=(F binaryFunction, T const& rightArg)
{
    return [&](auto leftArg){ return binaryFunction(leftArg, rightArg); };
}

template <typename T, typename F>
auto operator>>=(T const& leftArg, F binaryFunction)
{
    return [&](auto rightArg){ return binaryFunction(leftArg, rightArg); };
}

}
