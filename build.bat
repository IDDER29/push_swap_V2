@echo off
echo Compiling push_swap...

gcc -Wall -Wextra -Werror -c ft_printf.c ft_printf_utils.c ft_print_str.c ft_strlen.c
if %errorlevel% neq 0 (
    echo Compilation failed!
    exit /b 1
)

ar rcs libftprintf.a ft_printf.o ft_printf_utils.o ft_print_str.o ft_strlen.o
if %errorlevel% neq 0 (
    echo Library creation failed!
    exit /b 1
)

gcc -Wall -Wextra -Werror -c main.c
if %errorlevel% neq 0 (
    echo Main compilation failed!
    exit /b 1
)

gcc -o push_swap main.o libftprintf.a
if %errorlevel% neq 0 (
    echo Linking failed!
    exit /b 1
)

echo.
echo ✓ Compilation successful!
echo ✓ Executable: push_swap.exe
