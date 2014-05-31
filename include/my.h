#ifndef MY_H
# define MY_H

# include <libc.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct	s_list	t_list;

struct	s_list
{
	int	fd[2];
	char	*src[2];
	char	**cmd[2];
};

void	clean_up(t_list *args);
char	is_dir(char *str, t_list *args, int f);
char	is_cmd(char *str, t_list *args, int w);
char	is_good(char **av, t_list *args);
char	*concat_slash(char *path, char *name);
void	purge_strs(char **str);
void	clean_up(t_list *args);
void	xdup2(int *fd, int i);
void	xpipe(int fd[2]);
void	xwait(int pid, int *stat);
void	xexecv(char *cmd, char **arv);

#endif
