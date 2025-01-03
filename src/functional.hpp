// Copyright (c) 2024, Marco Nikander

#pragma once

#include <algorithm>
#include <cmath>
#include <numeric> // greatest_common_divisor, least_common_multiple

namespace nv {

// Logical operators
struct Not          { template <typename T> T operator()(T t) const { return !t; } };
struct And          { template <typename T> T operator()(T lhs, T rhs) const { return lhs && rhs; } };
struct Or           { template <typename T> T operator()(T lhs, T rhs) const { return lhs || rhs; } };

// unary ops, which are both: (1) a tag which represents the operation and (2) the implementation of that operation
struct Identity     { template <typename T> T operator()(T t) const { return t; } };
struct Negate       { template <typename T> T operator()(T t) const { return -t; } };
// TODO: abs, sqrt, crt, log, log_2, log_10, exp, exp_2, exp_10 ...

// binary ops, which are both: (1) a tag which represents the operation and (2) the implementation of that operation
struct Plus         { template <typename T> T operator()(T lhs, T rhs) const { return lhs + rhs; } };
struct Minus        { template <typename T> T operator()(T lhs, T rhs) const { return lhs - rhs; } };
struct Multiply     { template <typename T> T operator()(T lhs, T rhs) const { return lhs * rhs; } };
struct Divide       { template <typename T> T operator()(T lhs, T rhs) const { return lhs / rhs; } };
struct Modulo       { template <typename T> T operator()(T lhs, T rhs) const { return lhs % rhs; } };
struct Power        { template <typename T> T operator()(T base, T exp) const { return std::pow(base, exp); } };
struct Minimum      { template <typename T> T operator()(T lhs, T rhs) const { return std::min(lhs, rhs); } };
struct Maximum      { template <typename T> T operator()(T lhs, T rhs) const { return std::max(lhs, rhs); } };
struct Equal        { template <typename T> bool operator()(T lhs, T rhs) const { return lhs == rhs; } };
struct NotEqual     { template <typename T> bool operator()(T lhs, T rhs) const { return lhs != rhs; } };
struct Less         { template <typename T> bool operator()(T lhs, T rhs) const { return lhs < rhs; } };
struct LessEqual    { template <typename T> bool operator()(T lhs, T rhs) const { return lhs <= rhs; } };
struct Greater      { template <typename T> bool operator()(T lhs, T rhs) const { return lhs > rhs; } };
struct GreaterEqual { template <typename T> bool operator()(T lhs, T rhs) const { return lhs >= rhs; } };

struct LeastCommonMultiple { template <typename T> T operator()(T lhs, T rhs) const { return std::lcm(lhs,rhs); }
                                                bool operator()(bool lhs, bool rhs) const { return lhs && rhs; } };
// note that AND is a specialization of LCM for booleans

struct GreatestCommonDivisor { template <typename T> T operator()(T lhs, T rhs) const { return std::gcd(lhs,rhs); }
                                                  bool operator()(bool lhs, bool rhs) const { return lhs || rhs; } };
// note that OR is a specialization of GCD for booleans

}
