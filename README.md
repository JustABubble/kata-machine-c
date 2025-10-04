# C Kata Machine

A data structures and algorithms practice environment for C programmers.
Inspired by
[ThePrimeagen's kata-machine](https://github.com/ThePrimeagen/kata-machine),
this project provides a structured way to drill fundamental algorithms and data
structures through repetition and muscle memory.

## Prerequisites

- A C compiler (e.g., gcc, clang)
- Text editor
- Basic understanding of C and pointers
- Familiarity with manual memory management

## Building

```bash
git clone https://github.com/justabubble/kata-machine-c.git
cd kata-machine-c
cc -o nob nob.c
```

## Usage

### Generate a new day's worth of exercises

```bash
./nob generate
```

This creates a new directory with stub implementations of all algorithms and data structures.

### Run tests

```bash
./nob test
```

### Run specific algorithm tests

```bash
./nob test <algorithm_name>
```

## Exercises

Exercises live in the 'exercises/day%d' directories. Implement the the data
structure or algorithm and run the corresponding tests.

## Acknowledgments

- Inspired by [ThePrimeagen's kata-machine](https://github.com/ThePrimeagen/kata-machine)
