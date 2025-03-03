#include "libft.h"

void	libft_printf_err(const char *fmt, ...)
{
	int		n;
	char	*str;
	va_list	args;
	va_start(args, fmt);
	char buffer[1024];
	int offset = 0;
	while (*fmt)
	{
		if (*fmt != '%')
		{
			write(2, fmt, 1);  // Change to stderr (fd = 2)
			if (offset < 1023) buffer[offset++] = *fmt;
			fmt++;
		}
		else
		{
			fmt++;
			if (*fmt == 's')
			{
				str = va_arg(args, char *);
				libft_putstr_err(str);
				if (offset < 1023) offset += snprintf(buffer + offset, 1023 - offset, "%s", str);
			}
			else if (*fmt == 'd')
			{
				n = va_arg(args, int);
				libft_putnbr_err(n);
				if (offset < 1023) offset += snprintf(buffer + offset, 1023 - offset, "%d", n);
			}
			fmt++;
		}
	}
	va_end(args);
	buffer[offset] = '\0';
	w_trace("%s", buffer);
}
