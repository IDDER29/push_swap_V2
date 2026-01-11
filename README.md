*This project has been created as part of the 42 curriculum by idait-el.*

# ft_printf

## Description
`ft_printf` is a custom implementation of the standard C library function `printf`. This project mimics the behavior of the original function, allowing for formatted output to the standard output (stdout).

The goal of this project is to learn about:
- **Variadic functions:** Handling an undefined number of arguments in C.
- **Data types:** Formatting and printing various types (integers, strings, pointers, hex).
- **Library creation:** Structuring code into a reusable `.a` library.

Supported conversions:
- `%c`: Prints a single character.
- `%s`: Prints a string.
- `%p`: Prints a void * pointer argument in hexadecimal format.
- `%d`: Prints a decimal (base 10) number.
- `%i`: Prints an integer in base 10.
- `%u`: Prints an unsigned decimal (base 10) number.
- `%x`: Prints a number in hexadecimal (base 16) lowercase format.
- `%X`: Prints a number in hexadecimal (base 16) uppercase format.
- `%%`: Prints a percent sign.

## Instructions

### Compilation
To compile the library, run the following command in the root of the repository:
```bash
make
```
This will generate the `libftprintf.a` library file.

**Other make rules:**
- `make clean`: Removes the object files (`.o`).
- `make fclean`: Removes the object files and the library (`.a`).
- `make re`: Performs a `fclean` followed by a `make`.

### Usage
To use `ft_printf` in your own code:
1. Include the header file: `#include "ft_printf.h"`
2. Compile your file with the library:
   ```bash
   cc main.c libftprintf.a -o my_program
   ```

**Example:**
```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s\n", "World");
    ft_printf("Number: %d\n", 42);
    ft_printf("Pointer: %p\n", &main);
    return (0);
}
```

## Algorithm & Implementation
The implementation relies on `va_list` from `<stdarg.h>` to traverse the variable arguments.

### 1. Data Structure & Logic
The function does not use a complex struct for the mandatory part. Instead, it uses a linear parsing approach:
- **Main Loop:** The function iterates through the format string `const char *format` one character at a time.
- **Parsing:**
    - If the current character is **not** `%`, it is written immediately to `stdout`.
    - If the character **is** `%`, the function looks at the *next* character to identify the type (e.g., `s`, `d`, `x`).
- **Dispatching:** A helper function `ft_format_handler` acts as a dispatcher (using `if/else` checks) to route the argument to the specific printing function (e.g., `ft_print_hex`, `ft_print_str`).

### 2. Justification
This "direct write" approach was chosen for simplicity and reliability. Since the mandatory part forbids standard buffer management, writing directly to file descriptor 1 ensures the output is immediate.
- **Recursion for Numbers:** Helper functions like `ft_print_decimal` or `ft_print_hex` use recursion (or iteration with a buffer) to process numbers. This is efficient for small bases (10 and 16).
- **Return Value:** A counter `total_len` tracks every byte written. This is returned at the end to match `printf`'s standard behavior.

## Resources
- **Manuals:** `man printf`, `man stdarg`.
- **AI Usage:**
    - AI was consulted to understand the concept of **Variadic Functions** (`va_start`, `va_arg`, `va_end`) and how the stack handles undefined arguments in C.
    - AI helped explain the logic behind argument parsing and structure.