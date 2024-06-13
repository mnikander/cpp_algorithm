#pragma once

#include <vector>
#include "../common.hpp"

namespace nv {

template<typename T>
i32 size(std::vector<T> const& v)
{
    return static_cast<i32>(v.size());
}

}
