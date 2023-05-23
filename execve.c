#include "alx.h"

/**
 * _execve - executes a command.
 * @nick: a pointer to struct
 * Return: 0 if successfull.
 */
int _execve(_st *nick)
{
	/*variable declaration*/
	int retval = 0, status;
	pid_t pidd;

	retval = blt_in_lst(nick);
	if (retval != -1)/*checks if the cmd is a blt-in*/
		return (retval);

	retval = prog_fnd(nick);
	if (retval)/*checks if cmd is execve file*/
	{
		return (retval);
	}
	else
	{
		/* create a child process */
		pidd = fork();
		if (pidd == -1)
		{
			perror(nick->c);
			exit(EXIT_FAILURE);
		}
		if (pidd == 0)
		{
			/* execute the program*/
			retval = execve(nick->f[0], nick->f, nick->env);
			if (retval == -1)
				perror(nick->c), exit(EXIT_FAILURE);
		}
		else
		{
			/* wait then check exit status of the child */
			wait(&status);
			if (WIFEXITED(status))
				errno = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				errno = 128 + WTERMSIG(status);
		}
	}
	return (0);
}
