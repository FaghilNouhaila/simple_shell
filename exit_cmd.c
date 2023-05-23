#include "alx.h"


/**
 * blt_in_ext - A func that quits the shell program
 * @nick: A pointer to struct
 * Return: 0 if successfull
 *
 */


int blt_in_ext(_st *nick)
{
	int i;

	if (nick->f[1] != NULL)
	{
		/*Check argument data type*/
		for (i = 0; nick->f[1][i]; i++)
			if ((nick->f[1][i] < '0' || nick->f[1][i] > '9')
				&& nick->f[1][i] != '+')
			{
				/*For non-numeric args*/
				errno = 2;
				return (2);
			}
		errno = _atoi(nick->f[1]);
	}
	free_all_data(nick);
	exit(errno);
}


/**
 * blt_in_cd - A func that changes current dir
 * @nick: A pointer to struct
 * Return: 0 if successfull
 *
 */


int blt_in_cd(_st *nick)
{
	char *dir_home = env_get_key("HOME", nick), *dir_old = NULL;
	char old_dir[128] = {0};
	int error_code = 0;

	if (nick->f[1])
	{
		if (str_compare(nick->f[1], "-", 0))
		{
			dir_old = env_get_key("OLDPWD", nick);
			if (dir_old)
				error_code = st_wk_dir(nick, dir_old);
			_print(env_get_key("PWD", nick));
			_print("\n");

			return (error_code);
		}
		else
		{
			return (st_wk_dir(nick, nick->f[1]));
		}
	}
	else
	{
		if (!dir_home)
			dir_home = getcwd(old_dir, 128);

		return (st_wk_dir(nick, dir_home));
	}
	return (0);
}


/**
 * st_wk_dir - Sets PWD
 * @nick: A pointer to struct
 * @new_dir: A pointer to the path of new_dir
 *
 * Return: 0 if successfull
 */


int st_wk_dir(_st *nick, char *new_dir)
{
	char old_dir[128] = {0};
	int err_code = 0;

	getcwd(old_dir, 128);

	if (!str_compare(old_dir, new_dir, 0))
	{
		err_code = chdir(new_dir);
		if (err_code == -1)
		{
			errno = 2;
			return (3);
		}
		env_set_key("PWD", new_dir, nick);
	}
	env_set_key("OLDPWD", old_dir, nick);
	return (0);
}


/**
 * blt_in_hlp - A func that displays env variables
 * @nick: A pointer to struct
 *
 * Return: 0 if successfull
 */


int blt_in_hlp(_st *nick)
{
	int i, length = 0;
	char *van[6] = {NULL};

	van[0] = HELP_INFO_SEARCH;
	if (nick->f[1] == NULL)
	{
		_print(van[0] + 6);
		return (1);
	}
	if (nick->f[2] != NULL)
	{
		errno = E2BIG;
		perror(nick->c);
		return (5);
	}
	van[1] = EXIT_HELP_INFO;
	van[2] = ENVIRONMENT_HELP_INFO;
	van[3] = SETENV_HELP_INFO;
	van[4] = UNSETENV_HELP_INFO;
	van[5] = CD_HELP_INFO;

	for (i = 0; van[i]; i++)
	{
		length = str_length(nick->f[1]);
		if (str_compare(nick->f[1], van[i], length))
		{
			_print(van[i] + length + 1);
			return (1);
		}
	}
	errno = EINVAL;
	perror(nick->c);
	return (0);
}


/**
 * blt_in_alias - A func that sets aliases
 * @nick: A pointer to struct
 *
 * Return: 0 for successfull code
 */


int blt_in_alias(_st *nick)
{
	int i = 0;

	/*print env variables*/
	if (nick->f[1] == NULL)
		return (p_alias(nick, NULL));

	while (nick->f[++i])
	{
		/*Set env variables*/
		if (count_characters(nick->f[i], "="))
			set_alias(nick->f[i], nick);
		else
			p_alias(nick, nick->f[i]);
	}

	return (0);
}
