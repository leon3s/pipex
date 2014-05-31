#include "my.h"

char	*concat_slash(char *path, char *name)
{
	size_t	len;
	char	*new;
	size_t	count;

	len = ft_strlen(path) + ft_strlen(name);
	if (!(new = malloc(sizeof(*new) * (len + 2))))
		return (0);
	len = -1;
	count = -1;
	while (*(path + ++count))
		*(new + ++len) = *(path + count);
	*(new + ++len) = '/';
	count = -1;
	while (*(name + ++count))
		*(new + ++len) = *(name + count);
	*(new + ++len) = 0;
	return (new);
}
