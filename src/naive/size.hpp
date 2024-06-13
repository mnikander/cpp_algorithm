#pragma once

#include <vector>
#include "../common.hpp"

namespace naive {

template<typename T>
i64 size(std::vector<T> const& v)
{
    return static_cast<i64>(v.size());
}

}
