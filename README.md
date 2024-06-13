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

# APL and Thrust algorithms

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
- find
- contains
- front / back
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
