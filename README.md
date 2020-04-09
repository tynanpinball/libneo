# libneo

Matrix manipulation library in C.
This is a collection of C functions for manipulating matrices.
It's not particularly fast and could be optimized quite a bit.
The intent here is to eventually try and push some of this
code out to a GPU.

Data format in memory:

| x | c1 | c2 | c3 |
| - | -- | -- | -- |
| r1 | 1 | 2 | 3 |
| r2 | 4 | 5 | 6 |
| r3 | 7 | 8 | 9 |

