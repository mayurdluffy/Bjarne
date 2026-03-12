# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is a C++ learning codebase containing 59 standalone example files demonstrating various STL (Standard Template Library) features and C++ concepts. Each `.cpp` file is self-contained and can be compiled and run independently.

## Commands

**Compile a single file:**
```bash
g++ -std=c++17 -o output_name input_file.cpp
```

**Compile and run:**
```bash
g++ -std=c++17 input_file.cpp -o input_file && ./input_file
```

**With C++20 features (if needed):**
```bash
g++ -std=c++20 input_file.cpp -o input_file && ./input_file
```

## Code Architecture

The codebase is organized into topic-based folders:

```
├── algorithms/      # STL algorithm examples (transform, find, sort, etc.)
├── containers/
│   ├── sequential/  # vector, deque, list, forward_list
│   ├── associative/ # map, set, unordered_map, unordered_set
│   └── adapters/   # stack, queue, priority_queue
├── strings/        # String operations and string_view
├── templates/      # Template functions and classes
├── functional/     # Functors, predicates, lambda expressions
└── utilities/      # tuple, mmap, find_substring
```
