@echo off
echo Compiling push_swap...

echo Compiling printf library...
gcc -Wall -Wextra -Werror -c ft_printf.c ft_printf_utils.c ft_print_str.c ft_strlen.c
if %errorlevel% neq 0 (
    echo Printf library compilation failed!
    exit /b 1
)

echo Creating library archive...
ar rcs libftprintf.a ft_printf.o ft_printf_utils.o ft_print_str.o ft_strlen.o
if %errorlevel% neq 0 (
    echo Library creation failed!
    exit /b 1
)

echo Compiling push_swap modules...
gcc -Wall -Wextra -Werror -c main.c input_validation.c input_parse_utils.c input_parse_string.c input_parse_args.c push_swap_main.c stack_operations.c stack_push_operations.c swap_operations.c rotate_operations.c reverse_rotate_operations.c algorithm_sort.c algorithm_target.c algorithm_cost.c algorithm_execute.c utilities.c stack_output.c
if %errorlevel% neq 0 (
    echo Push_swap modules compilation failed!
    exit /b 1
)

echo Linking executable...
gcc -o push_swap main.o input_validation.o input_parse_utils.o input_parse_string.o input_parse_args.o push_swap_main.o stack_operations.o stack_push_operations.o swap_operations.o rotate_operations.o reverse_rotate_operations.o algorithm_sort.o algorithm_target.o algorithm_cost.o algorithm_execute.o utilities.o stack_output.o libftprintf.a
if %errorlevel% neq 0 (
    echo Linking failed!
    exit /b 1
)

echo.
echo ✓ Compilation successful!
echo ✓ Executable: push_swap.exe
