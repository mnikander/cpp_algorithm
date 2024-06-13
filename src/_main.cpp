#include <cstdlib> // exit_success
#include <iostream>
#include <iterator> // ostream_iterator
#include "reverse.hpp"
#include "size.hpp"
#include "meta/datatype_aliases.hpp"

int main()
{
    vi32 v = vi32{1, 2, 4, 8, 16} | xpr::reverse();
    std::cout << "( ";
    std::copy(v.cbegin(), v.cend(), std::ostream_iterator<i32>(std::cout, " "));
    std::cout << ")" << std::endl;

    return EXIT_SUCCESS;
}
