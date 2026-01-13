*This project has been created as part of the 42 curriculum by idait-el.*

# Push_swap

## Description

Push_swap is an algorithmic sorting challenge that involves sorting a stack of integers using a limited set of operations. The goal is to find the most efficient sequence of instructions to sort the data with the minimum number of moves possible.

This implementation features:
- **Optimized sorting algorithm** for various data sizes
- **Efficient cost calculation** using multiple rotation strategies
- **Performance targets achieved**: <700 operations for 100 numbers, <5500 for 500 numbers
- **Strict adherence** to 42 Norminette coding standards
- **Modular architecture** with 14 well-organized source files

The project demonstrates fundamental concepts in algorithm design, computational complexity, and optimized data structure manipulation.

## Instructions

### Compilation

To compile the project, run:

```bash
make
```

This will:
1. Compile the custom ft_printf library
2. Compile all push_swap source files
3. Link everything into the `push_swap` executable

The Makefile includes all required rules:
- `make` or `make all` - Build the executable
- `make clean` - Remove object files
- `make fclean` - Remove object files and executable
- `make re` - Clean and rebuild everything

### Usage

Run the program with a list of integers as arguments:

```bash
./push_swap 2 1 3 6 5 8
```

The program outputs the sequence of operations needed to sort the stack:

```
sa
pb
pb
pb
sa
pa
pa
pa
```

#### Valid Input
- Space-separated integers
- No duplicates
- Within INT_MIN to INT_MAX range

#### Error Handling
The program displays `Error` on stderr and exits for:
- Non-integer arguments
- Duplicate numbers
- Integer overflow/underflow
- Invalid input format

#### Edge Cases
- No arguments: Returns silently (exit code 0)
- Single number: Returns silently (already sorted)
- Already sorted: No operations output

### Performance Benchmarks

Average operations for random data:
- **3 numbers**: 0-2 operations (optimal)
- **5 numbers**: 5-8 operations
- **100 numbers**: ~565 operations (target <700, **19% better**)
- **500 numbers**: ~5000-5200 operations (target <5500, **9% better**)

## Available Operations

- `sa` - Swap first 2 elements of stack a
- `sb` - Swap first 2 elements of stack b
- `ss` - sa and sb simultaneously
- `pa` - Push top of b to a
- `pb` - Push top of a to b
- `ra` - Rotate a up (first becomes last)
- `rb` - Rotate b up
- `rr` - ra and rb simultaneously
- `rra` - Reverse rotate a down (last becomes first)
- `rrb` - Reverse rotate b down
- `rrr` - rra and rrb simultaneously

## Algorithm Overview

The sorting strategy adapts based on stack size:

1. **Size 2**: Single swap if needed
2. **Size 3**: Optimized 3-element sort (max 2 operations)
3. **Size > 3**: Hybrid approach:
   - Push all but 3 elements to stack B
   - Sort remaining 3 in stack A
   - Calculate insertion costs for each element in B
   - Move elements back using cheapest cost strategy
   - Final rotation to position minimum at top

### Cost Calculation Strategies

For each element in stack B, the algorithm evaluates 4 strategies:
- **RR**: Rotate both stacks forward
- **RRR**: Rotate both stacks backward
- **RB + RRA**: Rotate B forward, A backward
- **RRB + RA**: Rotate B backward, A forward

The strategy with minimum total cost is selected for each move.

## Project Structure

### Core Modules
- [main.c](main.c) - Entry point and argument parsing
- [input_validation.c](input_validation.c) - Input parsing and validation
- [push_swap_main.c](push_swap_main.c) - Main sorting orchestration

### Stack Operations
- [stack_operations.c](stack_operations.c) - Stack initialization and memory management
- [stack_push_operations.c](stack_push_operations.c) - Push operations (pa, pb)
- [stack_output.c](stack_output.c) - Output and display functions
- [swap_operations.c](swap_operations.c) - Swap operations (sa, sb, ss)
- [rotate_operations.c](rotate_operations.c) - Rotate operations (ra, rb, rr)
- [reverse_rotate_operations.c](reverse_rotate_operations.c) - Reverse rotate (rra, rrb, rrr)

### Algorithm Components
- [algorithm_sort.c](algorithm_sort.c) - Sorting logic and initialization
- [algorithm_target.c](algorithm_target.c) - Target position assignment
- [algorithm_cost.c](algorithm_cost.c) - Cost calculation and strategy selection
- [algorithm_execute.c](algorithm_execute.c) - Move execution

### Utilities
- [utilities.c](utilities.c) - Helper functions (find min, check sorted, print stack)

### Headers
- [push_swap.h](push_swap.h) - Main header with structures and function prototypes
- [ft_printf.h](ft_printf.h) - Custom printf implementation header

### Library
- ft_printf implementation (4 source files) - Custom printf for output

## Norminette Compliance

This project strictly adheres to 42 Norminette standards:
- **Maximum 5 functions per file**
- **Maximum 25 lines per function**
- **Tab indentation** (not spaces)
- **No global variables**
- **Proper function and variable naming**
- **Comment style**: `/* */` only

All source files have been verified for compliance.

## Resources

### Classic References
- **Introduction to Algorithms** (CLRS) - Chapter on Sorting Algorithms
- **Big-O Notation** - Understanding algorithmic complexity
- **Stack Data Structure** - Fundamental concepts
- [Sorting Algorithm Visualizations](https://visualgo.net/en/sorting)
- [42 Push_swap Guide](https://github.com/topics/push-swap)

### Algorithm Design
- Greedy algorithms for optimization
- Cost-based decision making
- Rotation optimization strategies

### AI Usage

AI tools were used in this project for:

1. **Code Refactoring**: Restructuring monolithic code into modular components
2. **Norminette Compliance**: Ensuring adherence to 42 coding standards
3. **Function Splitting**: Breaking down long functions to meet line limits
4. **Documentation**: Generating comprehensive comments and this README
5. **Testing Strategy**: Developing test cases for edge cases and performance
6. **Algorithm Discussion**: Exploring cost calculation approaches and optimization

**Areas where AI assistance was critical:**
- Organizing 843 lines of monolithic code into 14 logical modules
- Ensuring each function stays under 25 lines while maintaining readability
- Merging similar functions (4 strategy setters → 1 parametric function)
- Generating comprehensive test scripts for manual verification

**Human validation performed:**
- All AI-generated code was reviewed, tested, and often modified
- Manual verification of sorting correctness through Python simulation
- Performance testing with various data sizes
- Memory leak checking and error handling validation
- Peer review of algorithm efficiency and code organization

The final implementation represents a collaboration between AI assistance for code organization and human expertise for algorithm design, optimization, and validation.

## Testing

### Manual Testing

Test with various input sizes:

```bash
# Edge cases
./push_swap                    # No output (no arguments)
./push_swap 42                 # No output (single number)
./push_swap 1 2 3              # No output (already sorted)

# Error cases
./push_swap 1 2 2              # Error (duplicates)
./push_swap 1 abc 3            # Error (non-integer)
./push_swap 2147483648         # Error (overflow)

# Small sets
./push_swap 2 1
./push_swap 3 2 1

# Performance testing
ARG=$(seq 1 100 | shuf); ./push_swap $ARG | wc -l
```

### Checker Verification

If you have access to the official checker:

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
```

Expected output: `OK`

### Python Simulation

The project includes Python scripts for manual verification:

```python
# Simulate operations and verify sorting
python3 test_verification.py
```

This script:
1. Generates random test data
2. Runs push_swap with the data
3. Simulates each operation step-by-step
4. Verifies the final sorted state

## Author

**42 Login**: developer  
**Project**: Push_swap  
**Completion Date**: January 2026

## License

This project is part of the 42 School curriculum and follows the school's academic policies.
