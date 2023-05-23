#include "alx.h"

/**
 * free_recurrent_data - free fields needed at each loop
 * @nick: a pointer to struct
 *
 * Return:(void)
 */

void free_recurrent_data(_st *nick)
{
	if (nick->f)
		free_array_of_pointers(nick->f);
	if (nick->b)
		free(nick->b);
	if (nick->c)
		free(nick->c);

	nick->b = NULL;
	nick->c = NULL;
	nick->f = NULL;
}

/**
 * free_all_data - free field of data
 * @nick: a pointer to struct
 *
 * Return:(void)
 */
void free_all_data(_st *nick)
{
	if (nick->e != 0)
	{
		if (close(nick->e))
			perror(nick->a);
	}
	free_recurrent_data(nick);
	free_array_of_pointers(nick->env);
	free_array_of_pointers(nick->h);
}

/**
 * free_array_of_pointers - free a pointer of an array
 * @array: array of pointers
 *
 * Return: (void)
 */
void free_array_of_pointers(char **array)
{
	int i;

	if (array != NULL)
	{
		for (i = 0; array[i]; i++)
			free(array[i]);

		free(array);
		array = NULL;
	}
}
