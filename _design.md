# Design decisions
- hard-code to std::vector to simplify all interfaces
- implement the first version with hard-copies -- use views and expression templates in a later version

# Scope of the pipe operator

I will support the following:
- vector | f(vector)
- vector | f(scalar)
- scalar | f(vector)
- scalar | f(scalar)

I will NOT support:

The latter might run into problems because `operator|` is already defined for many primitive types.
If that happens, I would have to disambiguate it somehow, perhaps by difining a scalar _class_ of my own.

# Tensor support
How do I want to support tensors? Some options:

## Activate C++23 and use std::mdspan
- could save a lot of time
- I am unfamiliar with it
- not sure how good the C++23 support is with this compiler version

## My own flat vector implementation
- easy operations on all elements
- coordinate-based access is easy to implement (it's just the 'decode' algorithm which I will implement anyway)

## My own nested vector implementation
- allow efficient iteration along axes in the order given by the memory layout (but not any other orders)

## My own StridedRange implementation
- holds a shared_ptr to a templated container type
- has shape and axis order
- supports free functions rank(t), shape(t), order(t), size(t)
- support for std::array and vector (array could be a challenge for axis-wise operations or catenate for example, requires some meta-programming to manipulate the shape, order, and array-size)
- would allow axis-wise operations (using a strided iterator) on the range

# Mutable vs. immutable
Do I want to make all data immutable, like the functional languages and BQN do it? With views and expression templates this could still be fine from a performance standpoint. Alternatively I could let the programmer decide what he wants.

# Naming and capabilities of arithmetic, trigonometric, and boolean operations

Once I have `each`, `any`, `all`, and `none` with their full overload sets I will not need to overload any arithmetic operations for vector input. Unfortunately, the _functional_ header is some stuff, so I will have to implement my own if I want consistent namespaces, naming, and the ability to consistently plug them all into algorithms such as map.

Do I want to give these functions partial evaluation capability?
Then I could do `vi32{2, 8} | each(add(2));`
Alternatively: `vi32{2, 8} | each(add(), 2);` does not require partial evaluation capabilities and is just as concise
What about operations where the order matters, such as subtract?
`vi32{2, 8} | each(sub(1));` or `vi32{2, 8} | each(sub(), 1);` both work for subtracting from the right, but what about 1-n?
`1 | each(sub(vi32{2, 8}))` is a bit messy...
`1 | each(sub(), vi32{2, 8})` is much better

So no partial evaluation needed then? :) It's also less work to implement!

Could I somehow achieve this syntax: `1 | sub(each(), vi32{2, 8})` ?
-- I would probably have to overload _every single function_ to get that syntax, instead of just implementing 'each' once.

# Naming of the map/transform operation

Alternative names:
- map
- transform
- each
- each_element
- for_each
- multi
- poly
- element_wise / elementwise

Which looks best?

```cpp
auto v = 1 | elementwise(sub(), vi32{1, 2, 3});

auto v = 1 | elementwise(subtract(), vi32{1, 2, 3});

auto v = 1 | element_wise(sub(), vi32{1, 2, 3});

auto v = 1 | element_wise(subtract(), vi32{1, 2, 3});

auto v = 1 | multi(subtract(), vi32{1, 2, 3});

auto v = 1 | each(subtract(), vi32{1, 2, 3});

auto v = 1 | poly(subtract(), vi32{1, 2, 3});

auto v = 1 | map(subtract(), vi32{1, 2, 3});

auto v = vi32{1, 2, 3} | map(subtract(), 1);

auto v = vi32{1, 2, 3} | map(subtract(1));

auto result = vi32{0, 1, 2} | xpr::catenate() | vi32{2, 1, 0}; // ok-ish

auto result = vi32{0, 1, 2} | xpr::map(std::Plus<int>) | vi32{2, 1, 0};

auto result = vi32{0, 1, 2} | xpr::map(Plus{}) | vi32{2, 1, 0};

auto result = vi32{0, 1, 2} | xpr::map(Plus{}, vi32{2, 1, 0});

auto result = xpr::zip(vi32{0, 1, 2}, vi32{2, 1, 0}) | xpr::map(Plus{}); // shit

auto result = xpr::map(Plus{}, xpr::zip(vi32{0, 1, 2}, vi32{2, 1, 0})); // shit

auto result = {0, 1, 2} + {2, 1, 0};

auto result = map (+) (0, 1, 2) (2, 1, 0);             // ok/good, the two arrays back to back are weird

auto result = map (+) (iota 3) (2, 1, 0);              // haskell-like, pretty good

auto result = map [+] (1:3) (2:0);

auto result = map (+) iota(3) reverse(iota(3));

auto result = map (+) iota(3) iota(3).reverse();      // not so good, the '.' looks like a space

auto result = map (+) iota(3) (iota(3)|reverse());    // a bit better

auto result = map max iota(3) reverse(iota(3));

auto result = (map, +, iota(3), iota(3)|reverse());

auto result = map, +, iota(3), iota(3)|reverse();

auto result = 2 + reduce (+) map (+) iota(3) (2, 1, 0);

auto result = 2 + reduce (+) (map (+) iota(3) (2, 1, 0));

auto result = 2 + reduce plus map plus iota(3) (2, 1, 0);

auto result = 2 + (reduce (+) (map (+) iota(3) (2, 1, 0)));

auto result = (+ 2 (reduce + (map + (iota 3) (2, 1, 0))));      // lisp-like

auto result = (plus 2 (reduce max (map + (iota 3) (2, 1, 0)))); // lisp-like, but verbose operators
```

# In search of a better syntax

```apl
result ← 2 + ⌈/ (⍳2) + (2 1)
result ← 2 + ⌈/ (⍳2) + (⌽⍳2)
result ← 2 + (⍳3) ⌈.+ (⌽⍳3)
result ← 2 + (⍳3) ⌈.+ ⌽⍳3
```

```cpp
auto result = map(plus, iota(3), reverse(iota(3)));   // doable in C++
auto result = map("plus", iota(3), reverse(iota(3))); // slow, switch-case
```

```cpp
int result = (iota 3) max inner_product plus rotate iota 3;
int result = inner_product (max) (plus) (iota(3)) (rotate(iota(3)));
int result = inner_product<max,plus>(iota(3), {2, 1, 0}); // C++, actually OK, predefined ops only
int result = inner_product(max, plus, iota(3), {2, 1, 0}); // C++, not as good, but allows lambdas
int result = inner_product(max<int>{}, plus<int>{}, iota(3), {2, 1, 0}); // C++, bad
int result = inner_product(max<int>{}, plus<int>{})(iota(3), {2, 1, 0}); // C++ functor, bad
int result = inner_product(max{}, plus{})(iota(3), {2, 1, 0}); // C++ functor, not much better

int dot_product = reduce{multiply()}(map{plus()}(zip(iota(3), reverse(iota(3)))));
int dot_product = iota(3) | zip(iota(3) | reverse()) | map(plus()) | reduce(multiply());
int dot_product = (iota(3) >> zip() << (iota(3) >> reverse())) >> element_wise(plus()) >> reduce(multiply());
int dot_product = (iota(3) >> zip() << reverse() << iota(3)) >> element_wise(plus()) >> reduce(multiply()); // enable streaming arguments to the left AND right for ALL function-like objects
int dot_product = (iota(3) >> zip << reverse << iota(3)) >> element_wise(plus()) >> reduce(multiply()); // perhaps some parenthesis could be dropped, if the streaming operations on functions directly (instead of function-like objects)
int dot_product = ((iota(3) >> zip << reverse << iota(3)) >> (element_wise << plus)) >> (reduce << multiply); // APL-style order of execution (the right argument is everything to the right of a function), with corresponding parentheses
int dot_product = iota(3) | (map_reduce(multiply(), plus(), 0)(iota(3) | reverse())); // a function to construct a dedicated map_reduce function-object cleans the code up a lot
int dot_product = iota(3) | map_reduce(multiply(), plus(), 0, (iota(3) | reverse())); // direct construction is easier to implement, especially the overload resolution
int dot_product = iota(3) | map_reduce(multiply, plus, 0, (iota(3) | reverse()));     // perhaps the parethesis can be dropped, if 'multiply' and 'plus' are functions (not function objects) and 'map_reduce' has an overload which recognizes this and calls the functions to retrieve the actual function objects

// GOOD SYNTAX:
int dot_product = iota(3) | map_reduce(multiply, plus, 0, iota(3) | reverse);         // we might be able to push that a little farther still, by modifying the pipe-operator to do the same, for 'reverse' for example

// If we predefine the left and right sequence the dot_product expression becomes shorter:
vi32 A = iota(3);
vi32 B = A | reverse;
int dot_product = A | map_reduce(multiply, plus, 0, B);
int dot_product = A | (map_reduce(multiply, plus, 0)(B)); // alternative syntax, where overload resolution, order of execution, and the implementation of operator| could be a bit more challenging

vi32 A = {0, 1, 2, 3, 4};
vi32 B = A | reverse;
int dot_product = (A | map(multiply)(B)) | reduce(0, plus); // break map-reduce into individual functions, preferably with a binary transform-view implementation to avoid copies

// BEST SYNTAX:
vi32 A = {0, 1, 2, 3, 4};
vi32 B = A | reverse;
int dot_product = (A | map(multiply, B)) | reduce(0, plus); // make overload resolution of 'map' a little easier
```

## Using a DSL
```cpp
vi32 A = {0, 1, 2, 3, 4};
vi32 B = A | reverse;
int dot_product = (A map<times> B) reduce<0, add>; // a DSL could do better
int dot_product = (A times B) reduce<0, add>;      // a DSL with automatic function-lifting could do even better
int dot_product = 0 reduce<add> (A times B);       // different syntax for accumulator of reduce -- probably the best syntax overall
int dot_product = 0 add (A times B);               // automatic reduction, similar to automatic lifting, is problematic because we may also want to put 'plus' into a scan or some other algorithm
```
