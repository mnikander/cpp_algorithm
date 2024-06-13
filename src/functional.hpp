#pragma once

#include <algorithm>
#include <cmath>
#include <numeric> // gcd, lcm

namespace nv {

// Logical operators
struct LogicalNot   { template <typename T> T operator()(T t) const { return !t; } };
struct LogicalAnd   { template <typename T> T operator()(T lhs, T rhs) const { return lhs && rhs; } };
struct LogicalOr    { template <typename T> T operator()(T lhs, T rhs) const { return lhs || rhs; } };

// unary ops, which are both: (1) a tag which represents the operation and (2) the implementation of that operation
struct Identity     { template <typename T> T operator()(T t) const { return t; } };
struct Negate       { template <typename T> T operator()(T t) const { return -t; } };
// TODO: abs, sqrt, crt, log, log_2, log_10, exp, exp_2, exp_10 ...

// binary ops, which are both: (1) a tag which represents the operation and (2) the implementation of that operation
struct Plus         { template <typename T> T operator()(T lhs, T rhs) const { return lhs + rhs; } };
struct Minus        { template <typename T> T operator()(T lhs, T rhs) const { return lhs - rhs; } };
struct Times        { template <typename T> T operator()(T lhs, T rhs) const { return lhs * rhs; } };
struct Divided      { template <typename T> T operator()(T lhs, T rhs) const { return lhs / rhs; } };
struct Power        { template <typename T> T operator()(T base, T exp) const { return std::pow(base, exp); } };
struct Min          { template <typename T> T operator()(T lhs, T rhs) const { return std::min(lhs, rhs); } };
struct Max          { template <typename T> T operator()(T lhs, T rhs) const { return std::max(lhs, rhs); } };
struct Equal        { template <typename T> bool operator()(T lhs, T rhs) const { return lhs == rhs; } };
struct Unequal      { template <typename T> bool operator()(T lhs, T rhs) const { return lhs != rhs; } };
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

namespace xpr {

// functions which just execute the actual function object

// logical
// Unfortunately 'not' 'and' 'or' are reserved keywords in C++, so I cannot create functions with that name.
// This led me to introduce the prefix 'logical' to all of the names.

// unary
template <typename T> auto logical_not(T const& t) { return nv::LogicalNot{}(t); }
template <typename T> auto identity(T const& t) { return nv::Identity{}(t); }
template <typename T> auto negate(T const& t) { return nv::Negate{}(t); }

// binary
template <typename T> auto logical_and(T const& lhs, T const& rhs) { return nv::LogicalAnd{}(lhs, rhs); }
template <typename T> auto logical_or(T const& lhs, T const& rhs) { return nv::LogicalOr{}(lhs, rhs); }
template <typename T> auto plus(T const& lhs, T const& rhs) { return nv::Plus{}(lhs, rhs); }
template <typename T> auto minus(T const& lhs, T const& rhs) { return nv::Minus{}(lhs, rhs); }
template <typename T> auto times(T const& lhs, T const& rhs) { return nv::Times{}(lhs, rhs); }
template <typename T> auto divided(T const& lhs, T const& rhs) { return nv::Divided{}(lhs, rhs); }
template <typename T> auto power(T const& lhs, T const& rhs) { return nv::Power{}(lhs, rhs); }
template <typename T> auto min(T const& lhs, T const& rhs) { return nv::Min{}(lhs, rhs); }
template <typename T> auto max(T const& lhs, T const& rhs) { return nv::Max{}(lhs, rhs); }
template <typename T> auto equal(T const& lhs, T const& rhs) { return nv::Equal{}(lhs, rhs); }
template <typename T> auto unequal(T const& lhs, T const& rhs) { return nv::Unequal{}(lhs, rhs); }
template <typename T> auto less(T const& lhs, T const& rhs) { return nv::Less{}(lhs, rhs); }
template <typename T> auto less_equal(T const& lhs, T const& rhs) { return nv::LessEqual{}(lhs, rhs); }
template <typename T> auto greater(T const& lhs, T const& rhs) { return nv::Greater{}(lhs, rhs); }
template <typename T> auto greater_equal(T const& lhs, T const& rhs) { return nv::GreaterEqual{}(lhs, rhs); }
template <typename T> auto least_common_multiple(T const& lhs, T const& rhs) { return nv::LeastCommonMultiple{}(lhs, rhs); }
template <typename T> auto greatest_common_divisor(T const& lhs, T const& rhs) { return nv::GreatestCommonDivisor{}(lhs, rhs); }


}

// Unfortunately 'not' 'and' 'or' are reserved keywords in C++, so I cannot create functions with that name.
// Uppercase names would work.
// To be consistent, I would have to give all my functors and functions uppercase names...
// Or I force the user to differentiate between the tag 'Not' and the function 'Not'... that still doesn't change the
// fact it cannot be lowercase though. :(
// Another option would be to give them a special name by prefixing or postfixing something:
// _not, not_f, f_not, not_, 

// Specializing the the original functors to have zero-argument versions which are the tag, does not seem to work:
//
//     struct EmptyType {};
//     template <typename T> struct Not  { T operator()(T t) const { return !t; } };
//     template <> struct Not<EmptyType> {};
//
// results in compilation errors:
//
//     const auto t = Not<>{}; // error: wrong number of template arguments (0, should be 1)
//     const auto t = Not{};   // error: class template argument deduction failed
//
