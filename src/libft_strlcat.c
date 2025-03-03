#include "libft.h"

int libft_strlcat(char *dst, char *src, unsigned int size) {
	unsigned int d_len;
	unsigned int s_len;
	unsigned int d2_len;

	d_len = libft_strlen(dst);
	s_len = libft_strlen(src);
	d2_len = d_len;
	if (size <= d_len)
		return (s_len + size);
	while (*dst)
		dst++;
	while (*src && d_len++ < size - 1)
		*dst++ = *src++;
	*dst = '\0';
	return d2_len + s_len;
}
