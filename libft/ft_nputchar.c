#include "libft.h"

void			ft_nputchar(int n, char c)
{
	while (n)
	{
		write(1, &c, 1);
		n--;
	}
}