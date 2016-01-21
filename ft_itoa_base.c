#include "libft.h"
#include <stdio.h>

char	*ft_itoa_base(intmax_t n, char const *base)
{
	intmax_t	len;
	intmax_t	div;
	char		*output;
	intmax_t	i;
	intmax_t	base_val;
	char		neg;

	neg = 0;
	base_val = ft_strlen(base);
	div = 1;
	len = 1;
	if (n < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	if (n < 0)
	{
		n = n * -1;
		neg = 1;		
	}
	while (n / div > base_val - 1)
	{
		len++;
		div *= base_val;
	}
	if ((output = ft_strnew(len + neg)) == NULL)
		return (NULL);
	i = 0;
	if (neg == 1)
	{
		i = 1;
		output[0] = '-';
	}
	while (div)
	{
		output[i++] = base[(n / div) % base_val];
		div /= base_val;
	}
	return (output);
}
