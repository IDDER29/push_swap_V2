
#include "ft_printf.h"

int	ft_print_char(int c)
{
	return (write(1, &c, 1));
}

int	ft_print_hex(unsigned int num, int is_upper)
{
	char		buffer[12];
	char		*ptr;
	const char	*digits;
	int			len;

	if (is_upper)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	if (num == 0)
		return (write(1, "0", 1));
	ptr = &buffer[11];
	*ptr = '\0';
	while (num > 0)
	{
		ptr--;
		*ptr = digits[num % 16];
		num /= 16;
	}
	len = &buffer[11] - ptr;
	write(1, ptr, len);
	return (len);
}

int	ft_print_ptr(void *ptr_val)
{
	char			buffer[20];
	char			*p;
	unsigned long	num;
	int				len;

	if (ptr_val == NULL)
		return (write(1, "(nil)", 5));
	num = (unsigned long)ptr_val;
	write(1, "0x", 2);
	if (num == 0)
		return (2 + write(1, "0", 1));
	p = &buffer[19];
	*p = '\0';
	while (num > 0)
	{
		p--;
		*p = "0123456789abcdef"[num % 16];
		num /= 16;
	}
	len = &buffer[19] - p;
	write(1, p, len);
	return (len + 2);
}

int	ft_print_unsigned_decimal(unsigned int n)
{
	char	buffer[12];
	char	*ptr;
	int		len;

	if (n == 0)
		return (write(1, "0", 1));
	ptr = &buffer[11];
	*ptr = '\0';
	while (n > 0)
	{
		ptr--;
		*ptr = (n % 10) + '0';
		n /= 10;
	}
	len = &buffer[11] - ptr;
	write(1, ptr, len);
	return (len);
}

int	ft_print_decimal(int n)
{
	long	num;
	int		count;

	num = n;
	count = 0;
	if (num < 0)
	{
		count += write(1, "-", 1);
		num = -num;
	}
	count += ft_print_unsigned_decimal(num);
	return (count);
}
