*This project has been created as part of the 42 curriculum by idait-el.*

# Push_swap

## Description

Push_swap is an algorithmic sorting challenge that involves sorting a stack of integers using a limited set of operations. The goal is to find the most efficient sequence of instructions to sort the data with the minimum number of moves possible.

This implementation features:
- **Optimized sorting algorithm** for various data sizes
- **Efficient cost calculation** using multiple rotation strategies
- **Performance targets achieved**: <700 operations for 100 numbers, <5500 for 500 numbers
- **Bonus checker implementation** - reads and validates operations from stdin
- **Strict adherence** to 42 Norminette coding standards
- **Robust error handling** - proper integer overflow detection using `long long`
- **Modular architecture** with clean separation between mandatory and bonus parts

The project demonstrates fundamental concepts in algorithm design, computational complexity, and optimized data structure manipulation.

## Instructions

### Compilation

**Mandatory Part:**
```bash
make
```

This builds the `push_swap` executable.

**Bonus Part:**
```bash
make bonus
```

This builds the `checker` program (bonus part).

**Available Make Rules:**
- `make` or `make all` - Build push_swap
- `make bonus` - Build checker (bonus)
- `make clean` - Remove object files
- `make fclean` - Remove objects and executables
- `make re` - Rebuild everything

### Usage

**Mandatory - push_swap:**

Run the program with integers as arguments:

```bash
./push_swap 2 1 3 6 5 8
```

Output (sequence of operations to sort):
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

**Bonus - checker:**

Reads operations from stdin and validates if they correctly sort the stack:

```bash
# Pipe push_swap output to checker
./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23
# Output: OK

# Manual input
echo -e "sa\npb\npa" | ./checker 3 2 1
# Output: KO (not sorted)

# Subject example
echo -e "rra\npb\nsa\nrra\npa" | ./checker 3 2 1 0
# Output: OK
```

Checker outputs:
- `OK` - Stack A is sorted, Stack B is empty
- `KO` - Not properly sorted
- `Error` - Invalid input or instructions

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

### Mandatory Part

**Core Modules:**
- [main.c](main.c) - Entry point and argument parsing
- [input_validation.c](input_validation.c) - Input parsing and validation with overflow detection
- [push_swap_main.c](push_swap_main.c) - Main sorting orchestration

**Stack Operations:**
- [stack_operations.c](stack_operations.c) - Stack initialization and memory management
- [stack_push_operations.c](stack_push_operations.c) - Push operations (pa, pb)
- [swap_operations.c](swap_operations.c) - Swap operations (sa, sb, ss)
- [rotate_operations.c](rotate_operations.c) - Rotate operations (ra, rb, rr)
- [reverse_rotate_operations.c](reverse_rotate_operations.c) - Reverse rotate (rra, rrb, rrr)

**Algorithm Components:**
- [algorithm_sort.c](algorithm_sort.c) - Sorting logic and initialization
- [algorithm_target.c](algorithm_target.c) - Target position assignment
- [algorithm_cost.c](algorithm_cost.c) - Cost calculation and strategy selection
- [algorithm_execute.c](algorithm_execute.c) - Move execution

**Utilities:**
- [utilities.c](utilities.c) - Helper functions (find min, check sorted)

**Input Parsing:**
- [input_parse_args.c](input_parse_args.c) - Argument parsing
- [input_parse_string.c](input_parse_string.c) - String parsing
- [input_parse_utils.c](input_parse_utils.c) - Parsing utilities

### Bonus Part

**Checker Program:**
- [checker_bonus.c](checker_bonus.c) - Main checker entry point
- [checker_utils_bonus.c](checker_utils_bonus.c) - Instruction parser and executor
- [get_next_line_bonus.c](get_next_line_bonus.c) - Read instructions from stdin
- [operations_bonus.c](operations_bonus.c) - Silent push operations
- [operations_swap_bonus.c](operations_swap_bonus.c) - Silent swap operations
- [operations_rotate_bonus.c](operations_rotate_bonus.c) - Silent rotate operations
- [operations_reverse_rotate_bonus.c](operations_reverse_rotate_bonus.c) - Silent reverse rotate

**Bonus Features:**
- Reads instructions from standard input
- Executes all 11 operations silently (no output)
- Validates instruction format
- Checks final sorting state
- Error handling for invalid instructions

### Headers & Library

**Headers:**
- [push_swap.h](push_swap.h) - Main header with structures and function prototypes
- [push_swap_bonus.h](push_swap_bonus.h) - Bonus checker header
- [ft_printf.h](ft_printf.h) - Custom printf implementation

**Custom Library:**
- ft_printf implementation (4 source files) - Custom formatted output

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

AI tools were used minimally in this project for:

- **Documentation**: Assistance with README structure and formatting
- **Testing Strategy**: Suggestions for edge case scenarios and test organization

All core algorithm design, implementation, and optimization were done manually. The sorting algorithm, cost calculation strategies, and code structure are original work.

## Testing

### Manual Testing - Mandatory

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
./push_swap -2147483649        # Error (underflow)

# Small sets
./push_swap 2 1                # Output: sa
./push_swap 3 2 1              # Various operations

# Performance testing
ARG=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l
ARG=$(seq 1 500 | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l
```

### Manual Testing - Bonus (Checker)

```bash
# Subject examples
echo -e "rra\npb\nsa\nrra\npa" | ./checker 3 2 1 0   # OK
echo -e "sa\nrra\npb" | ./checker 3 2 1 0            # KO

# Integration tests
./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23   # OK
./push_swap 2 1 | ./checker 2 1                      # OK

# Error handling
./checker 3 2 one 0                                  # Error
echo "wrong" | ./checker 2 1                         # Error
./checker 3 2 3 1                                    # Error (duplicates)

# All operations test
echo -e "sa\npb\npa" | ./checker 3 2 1              # Test specific ops
```

## Author

**Project**: Push_swap (Mandatory + Bonus)  
**Completion Date**: January 2026  
**School**: 42 Network

## Key Features Implemented

✅ **Mandatory:**
- Optimized sorting algorithm
- All 11 stack operations
- Integer overflow/underflow detection (`long long` validation)
- Performance: ~565 ops for 100 numbers, ~5200 for 500

✅ **Bonus:**
- Complete checker implementation
- Reads operations from stdin
- Validates all 11 operations
- Proper error handling
- Integration with push_swap

## License

This project is part of the 42 School curriculum and follows the school's academic policies.
