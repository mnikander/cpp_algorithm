#pragma once

#include <algorithm>
#include <cmath>
#include <numeric> // greatest_common_divisor, least_common_multiple

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
struct Multiply        { template <typename T> T operator()(T lhs, T rhs) const { return lhs * rhs; } };
struct Divide      { template <typename T> T operator()(T lhs, T rhs) const { return lhs / rhs; } };
struct Modulo       { template <typename T> T operator()(T lhs, T rhs) const { return lhs % rhs; } };
struct Power        { template <typename T> T operator()(T base, T exp) const { return std::pow(base, exp); } };
struct Minimum          { template <typename T> T operator()(T lhs, T rhs) const { return std::min(lhs, rhs); } };
struct Maximum          { template <typename T> T operator()(T lhs, T rhs) const { return std::max(lhs, rhs); } };
struct Equal        { template <typename T> bool operator()(T lhs, T rhs) const { return lhs == rhs; } };
struct NotEqual      { template <typename T> bool operator()(T lhs, T rhs) const { return lhs != rhs; } };
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

// functions which retrive the function object, see cpp file for implementation

// unary
nv::LogicalNot logical_not();
nv::Identity identity();
nv::Negate negate();

// binary
nv::LogicalAnd logical_and();
nv::LogicalOr logical_or();
nv::Plus plus();
nv::Minus minus();
nv::Multiply multipy();
nv::Divide divide();
nv::Modulo modulo();
nv::Power power();
nv::Minimum minimum();
nv::Maximum maximum();
nv::Equal equal() ;
nv::NotEqual not_equal();
nv::Less less();
nv::LessEqual less_equal();
nv::Greater greater();
nv::GreaterEqual greater_equal();
nv::LeastCommonMultiple least_common_multiple();
nv::GreatestCommonDivisor greatest_common_divisor();

// functions which retrieve and execute the function object

// unary
template <typename T> auto logical_not(T const& t) { return nv::LogicalNot{}(t); }
template <typename T> auto identity(T const& t) { return nv::Identity{}(t); }
template <typename T> auto negate(T const& t) { return nv::Negate{}(t); }

// binary
template <typename T> auto logical_and(T const& lhs, T const& rhs) { return nv::LogicalAnd{}(lhs, rhs); }
template <typename T> auto logical_or(T const& lhs, T const& rhs) { return nv::LogicalOr{}(lhs, rhs); }
template <typename T> auto plus(T const& lhs, T const& rhs) { return nv::Plus{}(lhs, rhs); }
template <typename T> auto minus(T const& lhs, T const& rhs) { return nv::Minus{}(lhs, rhs); }
template <typename T> auto multipy(T const& lhs, T const& rhs) { return nv::Multiply{}(lhs, rhs); }
template <typename T> auto divide(T const& lhs, T const& rhs) { return nv::Divide{}(lhs, rhs); }
template <typename T> auto modulo(T const& lhs, T const& rhs) { return nv::Modulo{}(lhs, rhs); }
template <typename T> auto power(T const& lhs, T const& rhs) { return nv::Power{}(lhs, rhs); }
template <typename T> auto minimum(T const& lhs, T const& rhs) { return nv::Minimum{}(lhs, rhs); }
template <typename T> auto maximum(T const& lhs, T const& rhs) { return nv::Maximum{}(lhs, rhs); }
template <typename T> auto equal(T const& lhs, T const& rhs) { return nv::Equal{}(lhs, rhs); }
template <typename T> auto not_equal(T const& lhs, T const& rhs) { return nv::NotEqual{}(lhs, rhs); }
template <typename T> auto less(T const& lhs, T const& rhs) { return nv::Less{}(lhs, rhs); }
template <typename T> auto less_equal(T const& lhs, T const& rhs) { return nv::LessEqual{}(lhs, rhs); }
template <typename T> auto greater(T const& lhs, T const& rhs) { return nv::Greater{}(lhs, rhs); }
template <typename T> auto greater_equal(T const& lhs, T const& rhs) { return nv::GreaterEqual{}(lhs, rhs); }
template <typename T> auto least_common_multiple(T const& lhs, T const& rhs) { return nv::LeastCommonMultiple{}(lhs, rhs); }
template <typename T> auto greatest_common_divisor(T const& lhs, T const& rhs) { return nv::GreatestCommonDivisor{}(lhs, rhs); }

}

// Unfortunately 'not' 'and' 'or' are reserved keywords in C++, so I cannot create functions with that name.
// This led me to introduce the postfix '_l' to all of the names.
