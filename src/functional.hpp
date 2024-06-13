#pragma once

#include <algorithm>
#include <numeric> // gcd, lcm

namespace xpr {

// unary ops, which are both: (1) a tag which represents the operation and (2) the implementation of that operation
struct Identity     { template <typename T> T operator()(T t) const { return t; } };
struct Not          { template <typename T> T operator()(T t) const { return !t; } };
struct Negate       { template <typename T> T operator()(T t) const { return -t; } };

// binary ops, which are both: (1) a tag which represents the operation and (2) the implementation of that operation
struct Plus         { template <typename T> T operator()(T lhs, T rhs) const { return lhs + rhs; }};
struct Minus        { template <typename T> T operator()(T lhs, T rhs) const { return lhs - rhs; }};
struct Times        { template <typename T> T operator()(T lhs, T rhs) const { return lhs * rhs; }};
struct Divides      { template <typename T> T operator()(T lhs, T rhs) const { return lhs / rhs; }};
struct Power        { template <typename T> T operator()(T base, T exp) const { return std::pow(base, exp); }};
struct Min          { template <typename T> T operator()(T lhs, T rhs) const { return std::min(lhs, rhs); }};
struct Max          { template <typename T> T operator()(T lhs, T rhs) const { return std::max(lhs, rhs); }};
struct Equal        { template <typename T> bool operator()(T lhs, T rhs) const { return lhs == rhs; }};
struct NotEqual     { template <typename T> bool operator()(T lhs, T rhs) const { return lhs != rhs; }};
struct Less         { template <typename T> bool operator()(T lhs, T rhs) const { return lhs < rhs; }};
struct LessEqual    { template <typename T> bool operator()(T lhs, T rhs) const { return lhs <= rhs; }};
struct Greater      { template <typename T> bool operator()(T lhs, T rhs) const { return lhs > rhs; }};
struct GreaterEqual { template <typename T> bool operator()(T lhs, T rhs) const { return lhs >= rhs; }};
struct GreatestCommonDivisor { template <typename T> T operator()(T lhs, T rhs) const { return std::gcd(lhs,rhs); }};
struct Or : GreatestCommonDivisor { bool operator()(bool lhs, bool rhs) const { return lhs || rhs; }}; // OR is a specialization of GCD for booleans
struct LeastCommonMultiple   { template <typename T> T operator()(T lhs, T rhs) const { return std::lcm(lhs,rhs); }};
struct And : LeastCommonMultiple  { bool operator()(bool lhs, bool rhs) const { return lhs && rhs; }}; // AND is a specialization of LCM for booleans

// combinators
// TODO flip (i.e. C combinator)

}
