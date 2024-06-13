#pragma once

#include <cstdint>
#include <vector>

namespace nv {

template<typename T>
int32_t size(std::vector<T> const& v)
{
    return static_cast<int32_t>(v.size());
}

}
