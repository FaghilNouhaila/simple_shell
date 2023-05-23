#include "alx.h"

/**
 * blt_in_env - displays environment variables
 * @nick: a pointer to struct
 * Return: 0 if sucessful, or otherwise if fails.
 */
int blt_in_env(_st *nick)
{
	int i;
	char cpname[50] = {'\0'};
	char *var_copy = NULL;

	/* check if it a NULL argument */
	if (nick->f[1] == NULL)
		print_environ(nick);
	else
	{
		for (i = 0; nick->f[1][i]; i++)
		{
			if (nick->f[1][i] == '=')
			{
				var_copy = str_duplicate(env_get_key(cpname, nick));
				if (var_copy != NULL)
					env_set_key(cpname, nick->f[1] + i + 1, nick);

				/* print the environ */
				print_environ(nick);
				if (env_get_key(cpname, nick) == NULL)
				{
					_print(nick->f[1]);
					_print("\n");
				}
				else
				{
					env_set_key(cpname, var_copy, nick);
					free(var_copy);
				}
				return (0);
			}
			cpname[i] = nick->f[1][i];
		}
		errno = 2;
		perror(nick->c);
		errno = 127;
	}
	return (0);
}

/**
 * blt_set_env - a function that set env variables.
 * @nick:a pointer to struct.
 * Return: 0 if sucessfull.
 */

int blt_set_env(_st *nick)
{
	if (nick->f[1] == NULL || nick->f[2] == NULL)
		return (0);
	if (nick->f[3] != NULL)
	{
		errno = E2BIG;
		perror(nick->c);
		return (5);
	}

	env_set_key(nick->f[1], nick->f[2], nick);

	return (0);
}

/**
 * blt_in_unset_env - a function that unsets env variables.
 * @nick: a pointer to struct
 * Return: 0 if successfull.
 */
int blt_in_unset_env(_st *nick)
{
	if (nick->f[1] == NULL)
		return (0);
	if (nick->f[2] != NULL)
	{
		errno = E2BIG;
		perror(nick->c);
		return (5);
	}
	env_remove_key(nick->f[1], nick);

	return (0);
}
