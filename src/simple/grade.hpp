// implementation of APL algorithm 'grade'

#pragma once

#include <algorithm>
#include <vector>
#include "../meta/expression.hpp"
#include "iota.hpp"
#include "size.hpp"

namespace nv {

template<typename T, typename BinaryOp>
std::vector<int> grade(std::vector<T> const& data, BinaryOp op)
{
    std::vector<int> indices = iota(size(data));
    std::sort(indices.begin(), indices.end(), [&data, op](int l, int r){ return op(data[l], data[r]); });
    return indices;
}

template<typename T, typename BinaryOp>
std::vector<int> stable_grade(std::vector<T> const& data, BinaryOp op)
{
    std::vector<int> indices = iota(size(data));
    std::stable_sort(indices.begin(), indices.end(), [&data, op](int l, int r){ return op(data[l], data[r]); });
    return indices;
}

}
