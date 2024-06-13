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

namespace meta {

// NEVER use these meta-programming tags and functions in client code

template <typename T> struct Tag{};

struct LogicalNot : Tag<LogicalNot> {};
struct LogicalOr : Tag<LogicalOr> {};
struct LogicalAnd : Tag<LogicalAnd> {};
struct Identity : Tag<Identity> {};
struct Negate : Tag<Negate> {};
struct Plus : Tag<Plus>{};
struct Minus : Tag<Minus> {};
struct Times : Tag<Times> {};
struct Divided : Tag<Divided> {};
struct Power : Tag<Power> {};
struct Min : Tag<Min> {};
struct Max : Tag<Max> {};
struct Equal : Tag<Equal> {};
struct Unequal : Tag<Unequal> {};
struct Less : Tag<Less> {};
struct LessEqual : Tag<LessEqual> {};
struct Greater : Tag<Greater> {};
struct GreaterEqual : Tag<GreaterEqual> {};
struct LeastCommonMultiple : Tag<LeastCommonMultiple> {};
struct GreatestCommonDivisor : Tag<GreatestCommonDivisor> {};

// NEVER use these meta-programming tags and functions in client code

// dispatch function which converts the tag to the correct functor and sets the template T
// intended to simplify the signatures of algorithms such as 'map'
template <typename T> auto dispatch(meta::LogicalNot tag, T) { return nv::LogicalNot<T>{}; }
template <typename T> auto dispatch(meta::LogicalAnd tag, T) { return nv::LogicalAnd<T>{}; }
template <typename T> auto dispatch(meta::LogicalOr tag, T) { return nv::LogicalOr<T>{}; }
template <typename T> auto dispatch(meta::Identity tag, T) { return nv::Identity<T>{}; }
template <typename T> auto dispatch(meta::Negate tag, T) { return nv::Negate<T>{}; }
template <typename T> auto dispatch(meta::Plus tag, T) { return nv::Plus<T>{}; }
template <typename T> auto dispatch(meta::Minus tag, T) { return nv::Minus<T>{}; }
template <typename T> auto dispatch(meta::Times tag, T) { return nv::Times<T>{}; }
template <typename T> auto dispatch(meta::Divided tag, T) { return nv::Divided<T>{}; }
template <typename T> auto dispatch(meta::Power tag, T) { return nv::Power<T>{}; }
template <typename T> auto dispatch(meta::Min tag, T) { return nv::Min<T>{}; }
template <typename T> auto dispatch(meta::Max tag, T) { return nv::Max<T>{}; }
template <typename T> auto dispatch(meta::Equal tag, T) { return nv::Equal<T>{}; }
template <typename T> auto dispatch(meta::Unequal tag, T) { return nv::Unequal<T>{}; }
template <typename T> auto dispatch(meta::Less tag, T) { return nv::Less<T>{}; }
template <typename T> auto dispatch(meta::LessEqual tag, T) { return nv::LessEqual<T>{}; }
template <typename T> auto dispatch(meta::Greater tag, T) { return nv::Greater<T>{}; }
template <typename T> auto dispatch(meta::GreaterEqual tag, T) { return nv::GreaterEqual<T>{}; }
template <typename T> auto dispatch(meta::LeastCommonMultiple tag, T) { return nv::LeastCommonMultiple<T>{}; }
template <typename T> auto dispatch(meta::GreatestCommonDivisor tag, T) { return nv::GreatestCommonDivisor<T>{}; }

}

namespace xpr {


// function overloads which just retrieve a tag, see cpp file for implementation

// logical
// Unfortunately 'not' 'and' 'or' are reserved keywords in C++, so I cannot create functions with that name.
// This led me to introduce the prefix 'logical' to all of the names. 
meta::LogicalNot logical_not();
meta::LogicalAnd logical_and();
meta::LogicalOr logical_or();

// unary
meta::Identity identity();
meta::Negate negate();

// binary
meta::Plus plus();
meta::Minus minus();
meta::Times times();
meta::Divided divided();
meta::Power power();
meta::Min min();
meta::Max max();
meta::Equal equal();
meta::Unequal unequal();
meta::Less less();
meta::LessEqual less_equal();
meta::Greater greater();
meta::GreaterEqual greater_equal();
meta::LeastCommonMultiple least_common_multiple();
meta::GreatestCommonDivisor greatest_common_divisor();

// function overloads which execute the actual function

// logical
template <typename T> auto logical_not(T const& t) { return nv::LogicalNot<T>{}(t); }                        // execute function
template <typename T> auto logical_and(T const& lhs, T const& rhs) { return nv::LogicalAnd<T>{}(lhs, rhs); } // execute function
template <typename T> auto logical_or(T const& lhs, T const& rhs) { return nv::LogicalOr<T>{}(lhs, rhs); }   // execute function

// unary
template <typename T> auto identity(T const& t) { return nv::Identity<T>{}(t); }                      // execute function
template <typename T> auto negate(T const& t) { return nv::Negate<T>{}(t); }                          // execute function

// binary
template <typename T> auto plus(T const& lhs, T const& rhs) { return nv::Plus<T>{}(lhs, rhs); }       // execute function
template <typename T> auto minus(T const& lhs, T const& rhs) { return nv::Minus<T>{}(lhs, rhs); }     // execute function
template <typename T> auto times(T const& lhs, T const& rhs) { return nv::Times<T>{}(lhs, rhs); }     // execute function
template <typename T> auto divided(T const& lhs, T const& rhs) { return nv::Divided<T>{}(lhs, rhs); } // execute function
template <typename T> auto power(T const& lhs, T const& rhs) { return nv::Power<T>{}(lhs, rhs); }     // execute function
template <typename T> auto min(T const& lhs, T const& rhs) { return nv::Min<T>{}(lhs, rhs); }         // execute function
template <typename T> auto max(T const& lhs, T const& rhs) { return nv::Max<T>{}(lhs, rhs); }         // execute function
template <typename T> auto equal(T const& lhs, T const& rhs) { return nv::Equal<T>{}(lhs, rhs); }     // execute function
template <typename T> auto unequal(T const& lhs, T const& rhs) { return nv::Unequal<T>{}(lhs, rhs); } // execute function
template <typename T> auto less(T const& lhs, T const& rhs) { return nv::Less<T>{}(lhs, rhs); }       // execute function
template <typename T> auto less_equal(T const& lhs, T const& rhs) { return nv::LessEqual<T>{}(lhs, rhs); }       // execute function
template <typename T> auto greater(T const& lhs, T const& rhs) { return nv::Greater<T>{}(lhs, rhs); }            // execute function
template <typename T> auto greater_equal(T const& lhs, T const& rhs) { return nv::GreaterEqual<T>{}(lhs, rhs); } // execute function
template <typename T> auto least_common_multiple(T const& lhs, T const& rhs) { return nv::LeastCommonMultiple<T>{}(lhs, rhs); }     // execute function
template <typename T> auto greatest_common_divisor(T const& lhs, T const& rhs) { return nv::GreatestCommonDivisor<T>{}(lhs, rhs); } // execute function


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
