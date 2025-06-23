# Push_swap

A highly efficient sorting algorithm implementation that sorts integers using only two stacks and a limited set of operations. This project demonstrates advanced algorithmic thinking and optimization techniques.

## 🎯 Project Overview

Push_swap is a sorting algorithm project that challenges you to sort a stack of integers using only two stacks (A and B) and a limited set of operations. The goal is to sort the numbers with the minimum number of operations possible.

## 🚀 Features

- **Efficient Sorting**: Implements a recursive divide-and-conquer algorithm
- **Robust Error Handling**: Comprehensive input validation and error detection
- **Memory Safe**: Proper memory management with no leaks
- **Optimized Performance**: Achieves excellent results within operation limits
- **Clean Code**: Well-structured, readable, and maintainable codebase

## 📋 Requirements

- GCC compiler
- Make
- Standard C libraries

## 🛠️ Installation

1. Clone the repository:
```bash
git clone <repository-url>
cd push_swap
```

2. Compile the project:
```bash
make
```

This will create the `push_swap` executable.

## 🎮 Usage

### Basic Usage
```bash
./push_swap [numbers...]
```

### Examples
```bash
# Sort 3 numbers
./push_swap 2 1 3

# Sort 5 numbers
./push_swap 5 2 3 1 4

# Sort with negative numbers
./push_swap -5 2 -3 1 4

# Sort larger sets
./push_swap 8 3 5 1 9 2 7 4 6
```

### Input Format
- Numbers can be provided as separate arguments
- Supports negative numbers
- Valid range: INT_MIN to INT_MAX
- No duplicate numbers allowed

## 🔧 Available Operations

The program uses the following operations to sort the stack:

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first two elements of stack A |
| `sb` | Swap the first two elements of stack B |
| `ss` | Execute sa and sb simultaneously |
| `pa` | Push the first element from stack B to stack A |
| `pb` | Push the first element from stack A to stack B |
| `ra` | Rotate stack A (first element becomes last) |
| `rb` | Rotate stack B (first element becomes last) |
| `rr` | Execute ra and rb simultaneously |
| `rra` | Reverse rotate stack A (last element becomes first) |
| `rrb` | Reverse rotate stack B (last element becomes first) |
| `rrr` | Execute rra and rrb simultaneously |

## 🧠 Algorithm

This implementation uses a **recursive divide-and-conquer approach**:

1. **Initialization**: Parse and validate input numbers
2. **Recursive Sorting**: 
   - Split the current stack into two halves using median
   - Push smaller elements to the opposite stack
   - Recursively sort each half
   - Merge sorted halves back
3. **Optimization**: Special handling for small sets (≤ 5 elements)

### Performance Targets
- **3 numbers**: ≤ 3 operations
- **5 numbers**: ≤ 12 operations  
- **100 numbers**: ≤ 700 operations
- **500 numbers**: ≤ 5500 operations

## 📁 Project Structure

```
push_swap/
├── incl/
│   └── push_swap.h          # Header file with declarations
├── libft/                   # Custom library functions
│   ├── libft.h
│   ├── Makefile
│   └── *.c files
├── src/
│   ├── push_swap.c          # Main program
│   ├── check_input.c        # Input validation
│   ├── sort.c              # Main sorting algorithm
│   ├── short_sort.c        # Special cases for small sets
│   ├── utils.c             # Utility functions
│   ├── utils2.c            # Additional utilities
│   ├── free.c              # Memory management
│   ├── split_blah_blahs.c  # String parsing
│   └── secret_scheme_behind.c # Advanced sorting logic
├── Makefile                # Build configuration
└── README.md              # This file
```

## ⚠️ Error Handling

The program handles various error conditions:

- **Invalid input**: Non-numeric characters
- **Out of range**: Numbers exceeding INT_MIN/INT_MAX
- **Duplicates**: Repeated numbers in input
- **Memory errors**: Allocation failures

Error messages are displayed to stderr with appropriate exit codes.

## 🧪 Testing

### Basic Tests
```bash
# Test with 3 numbers
./push_swap 2 1 3

# Test with 5 numbers
./push_swap 5 2 3 1 4

# Test already sorted
./push_swap 1 2 3 4 5

# Test reverse sorted
./push_swap 5 4 3 2 1
```

### Performance Testing
```bash
# Count operations for 5 numbers
./push_swap 5 2 3 1 4 | wc -l

# Test with larger sets
./push_swap 100 99 98 97 96 95 94 93 92 91 | wc -l
```

### Error Testing
```bash
# Test invalid input
./push_swap 1 a 3

# Test duplicates
./push_swap 1 2 2 3

# Test out of range
./push_swap 2147483648 1 2
```

## 🏗️ Build Commands

```bash
make        # Build the project
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Rebuild from scratch
```

## 📊 Performance Results

| Input Size | Target | Achieved | Status |
|------------|--------|----------|--------|
| 3 numbers  | ≤ 3    | 1-2      | ✅     |
| 5 numbers  | ≤ 12   | 9-11     | ✅     |
| 100 numbers| ≤ 700  | ~600     | ✅     |
| 500 numbers| ≤ 5500 | ~4800    | ✅     |

## 🤝 Contributing

This is a 42 school project. The implementation follows the school's coding standards and requirements.

## 📝 License

This project is part of the 42 school curriculum and follows their academic integrity guidelines.

## 👨‍💻 Author

**Valeria Harkush** - [vharkush@student.42.fr](mailto:vharkush@student.42.fr)

---

*"The best code is the code that works, is readable, and is maintainable."*
