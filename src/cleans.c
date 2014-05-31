#include "my.h"

void	purge_strs(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		ft_myfree(str[i]);
	ft_myfree(str);
}

void	clean_up(t_list *args)
{
	close(args->fd[0]);
	close(args->fd[1]);
	if (args->src[0])
		ft_myfree(args->src[0]);
	if (args->src[1])
		ft_myfree(args->src[1]);
	if (args->cmd[0])
		purge_strs(args->cmd[0]);
	if (args->cmd[1])
		purge_strs(args->cmd[1]);
	ft_myfree(args);
}
