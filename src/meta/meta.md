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
    return ResultFactory<Range, bool>();
}

template<typename Range>
auto doStuff2(Range const& range) -> decltype(result<bool>(range)) // this notation is less familiar to me
{
    return result<bool>(range);
}

template<typename Range>
Result<bool, Range> doStuff3(Range const& range)                   // very compact
{
    return result<bool>(range);
}
```
