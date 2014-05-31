#include "my.h"

void		xpipe(int fd[2])
{
   if (pipe(fd) == -1)
	  exit(-1);
}

void		xdup2(int *fd, int i)
{
   if (dup2(*fd, i) == -1)
	  exit(-1);
}

void		xwait(int pid, int *stat)
{
   waitpid(pid, stat, 0);
   if (*stat != 0)
	  exit(-1);
}

void		xexecv(char *cmd, char **arv)
{
   execv(cmd, arv);
   exit(-1);
}
