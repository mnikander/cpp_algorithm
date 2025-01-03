# Pipeline adapters

This folder contains a set of function objects.
They serve as adapters which allow the simple functions to be used in a pipeline using the bash-style `|` operator.
Due to the various function signatures and function overloads, these adapters are non-trivial and have to be written by hand to achieve a clean syntax for the pipelines.
