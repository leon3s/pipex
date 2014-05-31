#include "libc.h"

void	ft_error(char *msg)
{
	int	count;

	count = -1;
	while (msg[++count])
		;
	write(2, msg, count);
}
