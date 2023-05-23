#include "alx.h"


/**
 * blt_in_lst - a program that execute builtin
 * @nick: a pointer to struct
 *
 * Return: Return a function value,otherwise returns -1.
 **/

int blt_in_lst(_st *nick)
{
	int iterator;
	builtins options[] = {
		{"exit", blt_in_ext},
		{"help", blt_in_hlp},
		{"cd", blt_in_cd},
		{"alias", blt_in_alias},
		{"env", blt_in_env},
		{"setenv", blt_set_env},
		{"unsetenv", blt_in_unset_env},
		{NULL, NULL}
	};

	/*the structure*/

	for (iterator = 0; options[iterator].builtin != NULL; iterator++)
	{
		if (str_compare(options[iterator].builtin, nick->c, 0))
		{
			/* execute a function */

			return (options[iterator].function(nick));
		}
	}
	return (-1);
}
