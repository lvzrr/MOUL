char	*libft_strncat(char *dest, char *src, unsigned int n)
{
	char	*origin;

	origin = dest;
	while (*dest)
		dest++;
	while (*src && n--)
		*dest++ = *src++;
	*dest = '\0';
	return (origin);
}
