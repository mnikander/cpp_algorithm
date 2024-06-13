#pragma once

#include <algorithm>
#include <cmath>
#include <numeric> // gcd, lcm

namespace nv {

// Logical operators
template <typename T> struct LogicalNot  { T operator()(T t) const { return !t; } };
template <typename T> struct LogicalAnd  { T operator()(T lhs, T rhs) const { return lhs && rhs; } };
template <typename T> struct LogicalOr   { T operator()(T lhs, T rhs) const { return lhs || rhs; } };

// unary ops, which are both: (1) a tag which represents the operation and (2) the implementation of that operation
template <typename T> struct Identity     { T operator()(T t) const { return t; } };
template <typename T> struct Negate       { T operator()(T t) const { return -t; } };
// TODO: abs, sqrt, crt, log, log_2, log_10, exp, exp_2, exp_10 ...

// binary ops, which are both: (1) a tag which represents the operation and (2) the implementation of that operation
template <typename T> struct Plus         { T operator()(T lhs, T rhs) const { return lhs + rhs; } };
template <typename T> struct Minus        { T operator()(T lhs, T rhs) const { return lhs - rhs; } };
template <typename T> struct Times        { T operator()(T lhs, T rhs) const { return lhs * rhs; } };
template <typename T> struct Divided      { T operator()(T lhs, T rhs) const { return lhs / rhs; } };
template <typename T> struct Power        { T operator()(T base, T exp) const { return std::pow(base, exp); } };
template <typename T> struct Min          { T operator()(T lhs, T rhs) const { return std::min(lhs, rhs); } };
template <typename T> struct Max          { T operator()(T lhs, T rhs) const { return std::max(lhs, rhs); } };
template <typename T> struct Equal        { bool operator()(T lhs, T rhs) const { return lhs == rhs; } };
template <typename T> struct Unequal      { bool operator()(T lhs, T rhs) const { return lhs != rhs; } };
template <typename T> struct Less         { bool operator()(T lhs, T rhs) const { return lhs < rhs; } };
template <typename T> struct LessEqual    { bool operator()(T lhs, T rhs) const { return lhs <= rhs; } };
template <typename T> struct Greater      { bool operator()(T lhs, T rhs) const { return lhs > rhs; } };
template <typename T> struct GreaterEqual { bool operator()(T lhs, T rhs) const { return lhs >= rhs; } };

template <typename T> struct LeastCommonMultiple { T operator()(T lhs, T rhs) const { return std::lcm(lhs,rhs); } };
template <> struct LeastCommonMultiple<bool> { bool operator()(bool lhs, bool rhs) const { return lhs && rhs; } };
// note that AND is a specialization of LCM for booleans

template <typename T> struct GreatestCommonDivisor { T operator()(T lhs, T rhs) const { return std::gcd(lhs,rhs); } };
template <> struct GreatestCommonDivisor<bool> { bool operator()(bool lhs, bool rhs) const { return lhs || rhs; } };
// note that OR is a specialization of GCD for booleans

}
