#include "libft.h"

int	ft_findchar(const char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == c)
			return (-1);
		i++;
	}
	return (0);
}
