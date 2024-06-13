# cpp_algorithm
A loose collection of algorithms inspired by C++ Ranges, Thrust, APL/BQN, Haskell, Lisp, and others.

## Getting started
1. Clone the repo
2. cd cpp_algorithm
3. mkdir out
4. cd out
5. cmake ..
6. cd ..
7. cmake --build out/ # out-of-source build
8. ./out/unit_tests

# Algorithms

Naive implementations of several useful algorithms are available.
These are designed for ease-of-use, but are hard-coded to std::vector and do copy-by-value, which makes them slow.

## Creation and insertion
- iota
- repeat        (C++: fill)
- catenate

## Order and selection
- reverse
- rotate
- rotate_last
- take
- take_last
- drop
- drop_last
- gather        (APL: postfix-operator [])
- scatter
- filter        (C++: copy_if)
- grade

## Element retrieval
- 

## Computation
- reduce
- map           (C++: transform)

## Comparison
- equal         (APL: match)

## Arithmetic
- plus

## Properties
- size          (APL: tally)
- rank

# TODO
- front / back
- find
- at / get (?) -- do I want to follow the C++ convention of checking bounds, or just use it as a synonym for operator[]?
- something to search for the largest/smallest etc element
- contains
- slice / stencil
- inner product (similar to std::transform_reduce)
- scan
- sort
- any, all, none
- not
- min / max
- greatest common divisor / or
- lowest common multiple / and
- alternating reduction for minus and division (or some way of doing this)
- encode
- decode
- zip
- zip with next
- union (?) -- using DSU perhaps, or a hashmap
- difference (?)
- intersection (?)
- group by (returns a map of lists)
- chunk (returns list of lists)
- reduce (init = first element) vs. fold (manually specify init)
- fold_left, fold_right (see Haskell)
- roll
- deal
- binomial
- factorial

# TODO: Tensor algorithms for rank > 1
- flatten
- stencil
- transpose
- outer product
- reshape
- ravel (flatten)
- view to apply any algorithm around one specified axis (i.e. column-wise plus-reduce)
