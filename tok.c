#include "alx.h"

/**
 * _token - A func that splits strings using delimiter
 * @nick: a pointer to struct
 *
 * Return: Tokens
 */


void _token(_st *nick)
{
	char *delimiter = " \t";
	int i, j, counter = 2, length;

	length = str_length(nick->b);
	if (length)
	{
		if (nick->b[length - 1] == '\n')
			nick->b[length - 1] = '\0';
	}

	for (i = 0; nick->b[i]; i++)
	{
		for (j = 0; delimiter[j]; j++)
		{
			if (nick->b[i] == delimiter[j])
				counter++;
		}
	}

	nick->f = malloc(counter * sizeof(char *));
	if (nick->f == NULL)
	{
		perror(nick->a);
		exit(errno);
	}
	i = 0;
	nick->f[i] = str_duplicate(_strtok(nick->b, delimiter));
	nick->c = str_duplicate(nick->f[0]);
	while (nick->f[i++])
	{
		nick->f[i] = str_duplicate(_strtok(NULL, delimiter));
	}
}
