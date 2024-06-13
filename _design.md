# Design decisions
- hard-code to std::vector to simplify all interfaces
- implement the first version with hard-copies -- use views and expression templates in a later version

# Scope of the pipe operator

I will support the following:
- vector | f(vector)
- vector | f(scalar)
- scalar | f(vector)

I will NOT support:
- scalar | f(scalar)

The latter runs into problems because `operator|` is already defined for many primitive types.
I would have to disambiguate it somehow, perhaps by difining a scalar _class_ of my own.
Who knows what that would do for performance.
Supporting (scalar, scalar) would also force me to provide expression versions of everything in my functional header,which would be a lot of work.

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

`auto v = 1 | elementwise(sub(), vi32{1, 2, 3});`

`auto v = 1 | elementwise(subtract(), vi32{1, 2, 3});`

`auto v = 1 | element_wise(sub(), vi32{1, 2, 3});`

`auto v = 1 | element_wise(subtract(), vi32{1, 2, 3});`

`auto v = 1 | multi(subtract(), vi32{1, 2, 3});`

`auto v = 1 | each(subtract(), vi32{1, 2, 3});`

`auto v = 1 | poly(subtract(), vi32{1, 2, 3});`

`auto v = 1 | map(subtract(), vi32{1, 2, 3});`

`auto v = vi32{1, 2, 3} | map(subtract(), 1);`

`auto v = vi32{1, 2, 3} | map(subtract(1));`
