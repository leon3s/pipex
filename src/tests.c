#include "my.h"

char	is_dir(char *str, t_list *args, int f)
{
	if (f)
	{
		if ((args->fd[f] = open(str, O_RDWR | O_CREAT | O_TRUNC, 0666)) == -1)
			return (0);
	}
	else
	{
		if ((args->fd[f] = open(str, O_RDONLY)) == -1)
			return (0);
	}
	return (1);
}

char	is_cmd(char *str, t_list *args, int w)
{
	char	*path;
	char	**tmp;
	char	*src;
	int 	i;

	i = -1;
	if (!(path = getenv("PATH")))
		return (0);
	if (!(tmp = ft_strsplit(path, ':')))
		return (0);
	if (!(args->cmd[w] = ft_strsplit(str, ' ')))
		return (0);
	while (tmp[++i])
	{
		if (!(src = concat_slash(tmp[i], args->cmd[w][0])))
			return (0);
		if (!(access(src, X_OK)))
		{
			args->src[w] = src;
			purge_strs(tmp);
			return (1);
		}
	}
	return (0);
}

char	is_good(char **av, t_list *args)
{
	if (!(is_dir(av[1], args, 0)))
	{
		ft_error(av[1]);
		ft_error(" : open error.\n");
		return (0);
	}
	if (!(is_cmd(av[2], args, 0)))
	{
		ft_error(av[2]);
		ft_error(" : command not found\n");
		return (0);
	}
	if (!(is_cmd(av[3], args, 1)))
	{
		ft_error(av[3]);
		ft_error(" : command not found\n");
		return (0);
	}
	if (!(is_dir(av[4], args, 1)))
	{
		ft_error(av[4]);
		ft_error(" : open error.\n");
		return (0);
	}
	return (1);
}
