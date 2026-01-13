
#include "ft_printf.h"

static int	ft_format_handler(char spec, va_list args)
{
	if (spec == 'c')
		return (ft_print_char(va_arg(args, int)));
	if (spec == 's')
		return (ft_print_str(va_arg(args, char *)));
	if (spec == 'p')
		return (ft_print_ptr(va_arg(args, void *)));
	if (spec == 'd' || spec == 'i')
		return (ft_print_decimal(va_arg(args, int)));
	if (spec == 'u')
		return (ft_print_unsigned_decimal(va_arg(args, unsigned int)));
	if (spec == 'x')
		return (ft_print_hex(va_arg(args, unsigned int), 0));
	if (spec == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), 1));
	if (spec == '%')
		return (ft_print_char('%'));
	return (0);
}

static int	is_valid_specifier(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%');
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total_len;

	if (!format || write(1, "", 0) == -1)
		return (-1);
	va_start(args, format);
	total_len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (va_end(args), -1);
			if (is_valid_specifier(*format))
				total_len += ft_format_handler(*format, args);
			else
				total_len += write(1, "%", 1) + write(1, format, 1);
		}
		else
			total_len += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (total_len);
}
