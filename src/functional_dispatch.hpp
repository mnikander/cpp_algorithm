#pragma once

#include "functional_tags.hpp"
#include "functional.hpp"

namespace meta {

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