#include "libc.h"

void	ft_myfree(void *ptr)
{
	free(ptr);
	ptr = NULL;
}
