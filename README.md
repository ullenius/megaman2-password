# Mega Man 2 Password Generator #

## Overview

A Mega Man 2 password generator written in C. Implements the Shekleton algorithm.

The password can be represented as 25 bits stored in 5 [words](https://en.wikipedia.org/wiki/Word_(computer_architecture)#Word_size_choice) of 5 bits each. **A** is stored first. Then words **B-E** are stored in [little-endian](https://en.wikipedia.org/wiki/Endianness) format, that is:

    [ A, E, D, C, B ]

A password always has exactly 9 bits set.

The **A**-word represents the number of e-tanks. This word only has 1 bit set.

The other words (**E-B**) are used to represent the robot masters (alive/defeated).
The program then performs a [bit rotating left-shift
operation](https://en.wikipedia.org/wiki/Circular_shift) on the **E-B** words depending on how many etanks there are.

See Kevin Shekeltons excellent [original](https://github.com/kpshek/mm2pwd) Ruby-version for a more detailed explanation.

## Running

Simply run the executable.

```sh
$ ./mm2pwd

after rotation: 0x10162aa
A5
B2 B4
C1 C3 C5
D4 D5
E2
```

The above example displays the password for all robot masters beaten and 4 etanks (max).

## Build
A Makefile is provided. Simply run:
```sh
$ make
```

to build the binary `mm2pwd`.

## Requirements
1. C99
2. At least 32-bit `int` size.
3. A compiler that handles binary literals (such as `GCC` or `clang`).

## Credits
The [bitmasks](https://en.wikipedia.org/wiki/Mask_(computing)) for the bosses
are copied from the original Ruby version.The algorithm and the rest of the 
code is implemented manually through 
[clean-room design](https://en.wikipedia.org/wiki/Clean_room_design)
based on the original documentation. The original program was used for 
debugging the algorithm.

## Licence
Copyright 2020 Anosh D. Ullenius

Copyright 2013 Kevin Shekleton

Licensed under the Apache License, Version 2.0 (the "License"); you may not use
this file except in compliance with the License. You may obtain a copy of the
License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed
under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License.
