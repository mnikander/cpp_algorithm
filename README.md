# cpp_algorithm
A loose collection of algorithms inspired by C++ Ranges, Thrust, APL/BQN, Lisp, and others.

## Getting started
1. Clone the repo
2. cd cpp_algorithm
3. mkdir out
4. cmake out/
5. cmake --build out/ # out-of-source build
6. ./out/unit_tests

# APL and Thrust algorithms
- iota (std::iota)
- repeat (similar to std::fill)
- reverse (std::reverse)
- rotate
- reduce (with an easier interface)
- catenate (resize + std::copy or just std::copy)
- take, take_last
- drop, drop_last
- tally / size
- rank
- gather (i.e. index operator[] in APL)
- scatter
- grade
- filter
- map

# TODO
- catenate individual element -- or just let the coder put curly braces around it, instead of providing an extra overload? the overload would be better for performance though
- inner product (std::transform_reduce)
- scan (with an easier interface)
- any, all, none
- match (equal)
- not match
- not
- front / back
- find
- contains
- greatest common divisor / or
- lowest common multiple / and
- alternating reduction for minus and division (or some way of doing this)
- encode
- decode
- zip
- zip with next
- roll
- deal
- binomial
- factorial
- union (?) -- using DSU perhaps, or a hashmap
- difference (?)
- intersection (?)
- group by (returns a map of lists)
- chunk (returns list of lists)
- reduce (init = first element) vs. fold (manually specify init)

# TODO: Tensor algorithms for rank > 1
- flatten
- stencil
- transpose
- outer product
- reshape
- ravel (flatten)
- view to apply any algorithm around one specified axis (i.e. column-wise plus-reduce)
