# cpp_algorithm
A loose collection of algorithms inspired by C++ Ranges, Thrust, APL/BQN, Haskell, Lisp, and others.

## Getting started

1. Install dependencies
```bash
sudo apt get install _libgtest-dev_ cmake g++
```

2. Clone the repo

3. Build and run:
```bash
cd cpp_algorithm
mkdir out
cd out
cmake ..
cd ..
cmake --build out/ # out-of-source build
./out/unit_tests
./out/main
```

# Algorithms

These algorithm implementations are designed for ease-of-use, but are hard-coded to std::vector and do copy-by-value, which makes them slow.
It does allow playing around with the algorithms early on, and are a first step on the road to the faster implementations.

## Creation and insertion
- iota
- repeat        (C++: fill)
- catenate

## Element retrieval
- use vector::operator[] as normal

## Permutation and selection
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
- each / map -- for element-wise (arithmetic) operations
    - return vector
    - binary overloads of each replace `nv::plus` -- adapt the code from there :)
    - each(vector, op) -- replaces `nv::map`
    - each(vector, op, scalar)
    - each(vector, op, vector)
    - each(scalar, op, vector)
- any, all, none
    - return boolean
    - all replaces `nv::equal` -- adapt the code from there :)
    - early exit behavior (do NOT use reduce!)
    - {any, all, none}(vector, pred)
    - {any, all, none}(vector, pred, scalar)
    - {any, all, none}(vector, pred, vector)
    - {any, all, none}(scalar, pred, vector)
- find
- something to search for the largest/smallest etc element
- front / back
- at / get -- with and without bounds checking respectively (C++ convention 'at')
- contains
- slice / stencil
- inner_product / map_reduce
- scan -- pick one, maybe the inclusive scan
- sort
- any
- all
- none

## Arithmetic and boolean functions

### Nilary functions
- e  -- a bit short for a function name, it could collide with all sorts of stuff, maybe `constant_e`?
- pi -- less likely, but might collide with stuff as well, maybe `constant_pi`?

Or make a namespace `math` which contains them as constexpr values, i.e. `math::pi` and `math::e`

### Unary functions
- id : identity                        ( ??? )
- neg: negate                          (available in functional)
- not: not                             (available in functional)
- sqrt: square root
- crt: cube root
- exp | exp_e: exponential e -- maybe with a default value of 1 so it's easy to get 'e'
- exp_2:       exponential 2
- exp_10:      exponential 10
- log | log_e: logarithm e
- log_2:       logarithm 2
- log_10:      logarithm 10
- deg: degree
- rad: radian
- sin:  sine
- asin: arcus_sine
- cos:  cosine
- acos: arcus_cosine
- tan:  tangent
- atan: arcus_tangent
- abs:  absolute
- ceil: ceiling
- floor: floor
- round: round

### Binary functions

- add: add, addition, plus             (available in functional)
- sub: subtract, subtraction, minus    (available in functional)
- mul: multiply, multiplication, times (available in functional)
- div: divide, division                (available in functional)
- mod: modulo, remainder               (available in functional)
- eq : equal, equality                 (available in functional)
- neq: not-equal, unequal, inequality  (available in functional)
- max: maximum / or
- min: minimum / and
- gcd: greatest common divisor / or
- lcm: lowest common multiple / and
- le : less                            (available in functional)
- leq: less_equal                      (available in functional)
- gr : greater                         (available in functional)
- geq: greater_equal                   (available in functional)
- pow: power

## Future work on sequences
- take_while
- drop_while
- encode
- decode
- zip
- zip with next
- alternating reduction for minus and division (or some way of doing this)
- union (?) -- using DSU perhaps, or a hashmap
- difference (?)
- intersection (?)
- group by (returns a map of lists)
- chunk (returns list of lists)
- refactor to fold (manually specify init) vs. reduce (init = first element)
- fold_left, fold_right (see Haskell)
- roll
- deal
- binomial
- factorial

## Future work on tensors with rank > 1

- implement a strided range / tensor datatype similar to mdspan or cv::mat
- outer product
- stencil
- view to apply any algorithm around one specified axis (i.e. column-wise plus-reduce)
- flatten
- transpose
- (re)shape (rename repeat to shape, and extend the 'count' to be an n-entry vector describing the desired n-dimensional shape)
- ravel (flatten)

## Future work on intervals (TBD if I will do this)
- templated interval type with support for
    - scalars, to reason about numbers
    - iterators, to create and manipulate a 'view' on data
- union
- intersection
- difference
- overload other functions to take an interval as their [first, last) values
    - iota
    - stencil
    - roll (generate a random number in the interval)
