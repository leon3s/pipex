#include "my.h"

char	exec_pipes(t_list *args)
{
	pid_t	child;
	int	fd[2];
	int	stat;

	xpipe(fd);
	child = fork();
	if (!child)
	{
		xwait(child, &stat);
		stat = 0;
		stat = stat;
		close(fd[1]);
		xdup2(&fd[0], 0);
		xdup2(&args->fd[1], 1);
		xexecv(args->src[1], args->cmd[1]);
	}
	else if (child)
	{
		close(fd[0]);
		xdup2(&args->fd[0], 0);
		xdup2(&fd[1], 1);
		xexecv(args->src[0], args->cmd[0]);
	}
	else if (child == -1)
		ft_error("FORK ERROR EXIT SORRY.\n");
	return (1);
}

char	pipex(char **av)
{
	t_list	*args;

	if (!(args = malloc(sizeof(*args))))
		return (0);
	if (!(is_good(av, args)))
	{
		clean_up(args);
		return (0);
	}
	if (!(exec_pipes(args)))
	{
		clean_up(args);
		return (0);
	}
	clean_up(args);
	return (1);
}

int	main(int ac, char **av)
{
	if (ac != 5)
	{
		ft_error("usage : ");
		ft_error(av[0]);
		ft_error(" \"file1\" \"cmd1\" \"cmd2\" \"file2\"\n");
		return (0);
	}
	if (!(pipex(av)))
		return (0);
	return (ac);
}
