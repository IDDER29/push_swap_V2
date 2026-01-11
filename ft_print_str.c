
#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	len;

	if (!str)
	{
		return (write(1, "(null)", 6));
	}
	len = 0;
	len = ft_strlen(str);
	return (write(1, str, len));
}
