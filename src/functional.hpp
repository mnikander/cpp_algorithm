#pragma once

#include <algorithm>
#include <cmath>
#include <numeric> // gcd, lcm

namespace nv {

// unary ops, which are both: (1) a tag which represents the operation and (2) the implementation of that operation
template <typename T> struct Identity     { T operator()(T t) const { return t; } };
template <typename T> struct Not          { T operator()(T t) const { return !t; } };
template <typename T> struct Negate       { T operator()(T t) const { return -t; } };

// binary ops, which are both: (1) a tag which represents the operation and (2) the implementation of that operation
template <typename T> struct Plus         { T operator()(T lhs, T rhs) const { return lhs + rhs; } };
template <typename T> struct Minus        { T operator()(T lhs, T rhs) const { return lhs - rhs; } };
template <typename T> struct Times        { T operator()(T lhs, T rhs) const { return lhs * rhs; } };
template <typename T> struct Divides      { T operator()(T lhs, T rhs) const { return lhs / rhs; } };
template <typename T> struct Power        { T operator()(T base, T exp) const { return std::pow(base, exp); } };
template <typename T> struct Min          { T operator()(T lhs, T rhs) const { return std::min(lhs, rhs); } };
template <typename T> struct Max          { T operator()(T lhs, T rhs) const { return std::max(lhs, rhs); } };
template <typename T> struct Equal        { bool operator()(T lhs, T rhs) const { return lhs == rhs; } };
template <typename T> struct NotEqual     { bool operator()(T lhs, T rhs) const { return lhs != rhs; } };
template <typename T> struct Less         { bool operator()(T lhs, T rhs) const { return lhs < rhs; } };
template <typename T> struct LessEqual    { bool operator()(T lhs, T rhs) const { return lhs <= rhs; } };
template <typename T> struct Greater      { bool operator()(T lhs, T rhs) const { return lhs > rhs; } };
template <typename T> struct GreaterEqual { bool operator()(T lhs, T rhs) const { return lhs >= rhs; } };

template <typename T> struct GreatestCommonDivisor { T operator()(T lhs, T rhs) const { return std::gcd(lhs,rhs); } };
template <> struct GreatestCommonDivisor<bool> { bool operator()(bool lhs, bool rhs) const { return lhs || rhs; } };
using Or = GreatestCommonDivisor<bool>; // OR is a specialization of GCD for booleans

template <typename T> struct LeastCommonMultiple { T operator()(T lhs, T rhs) const { return std::lcm(lhs,rhs); } };
template <> struct LeastCommonMultiple<bool> { bool operator()(bool lhs, bool rhs) const { return lhs && rhs; } };
using And = LeastCommonMultiple<bool>; // AND is a specialization of LCM for booleans

// combinators
// TODO flip (i.e. C combinator) -- without function composition this is probably not that useful, since you'd be using
// a lamdbda expression anyway, in the context of a map or map_reduce, for example

}

namespace xpr {

// tags (without template parameters) which correspond to the above functors
struct Identity{};
struct Not{};
struct Negate{};
struct Plus{};
struct Minus{};
struct Times{};
struct Divides{};
struct Power{};
struct Min{};
struct Max{};
struct Equal{};
struct NotEqual{};
struct Less{};
struct LessEqual{};
struct Greater{};
struct GreaterEqual{};
struct GreatestCommonDivisor{};
struct Or{};
struct LeastCommonMultiple{};
struct And{};

}

namespace meta {

// NEVER use these meta-programming functions in client code
// dispatch function which converts the tag to the correct functor and sets the template T
// intended to simplify the signatures of algorithms such as 'map'
template <typename T> auto dispatch(xpr::Identity tag, T) { return nv::Identity<T>{}; }
template <typename T> auto dispatch(xpr::Not tag, T) { return nv::Not<T>{}; }
template <typename T> auto dispatch(xpr::Negate tag, T) { return nv::Negate<T>{}; }
template <typename T> auto dispatch(xpr::Plus tag, T) { return nv::Plus<T>{}; }
template <typename T> auto dispatch(xpr::Minus tag, T) { return nv::Minus<T>{}; }
template <typename T> auto dispatch(xpr::Times tag, T) { return nv::Times<T>{}; }
template <typename T> auto dispatch(xpr::Divides tag, T) { return nv::Divides<T>{}; }
template <typename T> auto dispatch(xpr::Power tag, T) { return nv::Power<T>{}; }
template <typename T> auto dispatch(xpr::Min tag, T) { return nv::Min<T>{}; }
template <typename T> auto dispatch(xpr::Max tag, T) { return nv::Max<T>{}; }
template <typename T> auto dispatch(xpr::Equal tag, T) { return nv::Equal<T>{}; }
template <typename T> auto dispatch(xpr::NotEqual tag, T) { return nv::NotEqual<T>{}; }
template <typename T> auto dispatch(xpr::Less tag, T) { return nv::Less<T>{}; }
template <typename T> auto dispatch(xpr::LessEqual tag, T) { return nv::LessEqual<T>{}; }
template <typename T> auto dispatch(xpr::Greater tag, T) { return nv::Greater<T>{}; }
template <typename T> auto dispatch(xpr::GreaterEqual tag, T) { return nv::GreaterEqual<T>{}; }
template <typename T> auto dispatch(xpr::GreatestCommonDivisor tag, T) { return nv::GreatestCommonDivisor<T>{}; }
template <typename T> auto dispatch(xpr::LeastCommonMultiple tag, T) { return nv::LeastCommonMultiple<T>{}; }
template <typename T> auto dispatch(xpr::And tag, T) { return nv::And{}; }
template <typename T> auto dispatch(xpr::Or tag, T) { return nv::Or{}; }

}
