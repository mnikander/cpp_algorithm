# Meta-programming utilities

## Return types

For the return values, I need an initialized container with:

- same container type and size as the input
- specified value type
- a very convenient way to get the container type, for the return type of functions

There are several options for the syntax:

```cpp
template<typename Range>
typename ResultFactory<Range, bool>::Container doStuff1(Range const& range)
{
    return ResultFactory<Range, bool>{}(range);
}

auto doStuff2(Range const& range) -> decltype(makeContainer<bool>(range)) // this notation is less familiar to me
{
    return makeContainer<bool>(range);
}

template<typename Range>
typename ResultTraits<bool, Range>::Type doStuff3(Range const& range)     // very compact
{
    return makeContainer<bool>(range);
}
```

Options 2 and 3 are better that 1, because they separate the concerns more strongly, whereas the ResultFactory in approach 1 ends up being quite difficult to read, even though it is not that long.
I chose option 2 instead of 3 because it is easier to use the decltype specifier than to create and maintain a separate traits class.
It's less code overall, and there is a single source of truth: the overloads of the `makeContainer` function.

## Copyright

Copyright (c) 2024, Marco Nikander
