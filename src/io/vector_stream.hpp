// Copyright (c) 2024, Marco Nikander

#pragma once

#include <algorithm>
#include <iostream>
#include <iterator> // ostream_iterator
#include <ostream>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> const& v)
{
    os << "( ";
    std::copy(v.cbegin(), v.cend(), std::ostream_iterator<T>(os, " "));
    os << ")";
    return os;
}
