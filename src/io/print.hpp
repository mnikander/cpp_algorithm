// Copyright (c) 2024, Marco Nikander

#pragma once

#include <algorithm>
#include <iostream>
#include <iterator> // ostream_iterator
#include <ostream>
#include <vector>

namespace io {

template <typename T>
void print(std::vector<T> const& v)
{
    std::cout << "( ";
    std::copy(v.cbegin(), v.cend(), std::ostream_iterator<T>(std::cout, " "));
    std::cout << ")" << std::endl;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> const& v)
{
    std::copy(v.cbegin(), v.cend(), std::ostream_iterator<T>(os, " "));
    return os;
}

}