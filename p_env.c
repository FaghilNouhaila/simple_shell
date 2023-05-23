#include "alx.h"


/**
 * env_get_key - A function that gets env variables
 * @key: A pointer to target env variable
 * @nick: A pointer to struct
 *
 * Return: a pointer to the value of env variable
 */


char *env_get_key(char *key, _st *nick)
{
	int i, key_length = 0;

	if (key == NULL || nick->env == NULL)
		return (NULL);
	key_length = str_length(key);
	for (i = 0; nick->env[i]; i++)
	{
		/*Transverses through the environ*/
		if (str_compare(key, nick->env[i], key_length) &&
		 nick->env[i][key_length] == '=')
		{
			return (nick->env[i] + key_length + 1);
		}
	}
	return (NULL);
}


/**
 * env_set_key - A func that  overwrites env var
 * @key: A pointer to env var
 * @value: new value
 * @nick: A pointer to struct
 *
 * Return: 1 if the parameters are NULL
 */


int env_set_key(char *key, char *value, _st *nick)
{
	int i, key_length = 0, is_new_key = 1;

	if (key == NULL || value == NULL || nick->env == NULL)
		return (1);
	key_length = str_length(key);
	for (i = 0; nick->env[i]; i++)
	{
		if (str_compare(key, nick->env[i], key_length) &&
		 nick->env[i][key_length] == '=')
		{
			is_new_key = 0;
			free(nick->env[i]);
			break;
		}
	}
	nick->env[i] = str_concat(str_duplicate(key), "=");
	nick->env[i] = str_concat(nick->env[i], value);

	if (is_new_key)
	{
		nick->env[i + 1] = NULL;
	}
	return (0);
}


/**
 * env_remove_key - A func that remove a key from the env
 * @key: A pointer to the key to remove
 * @nick: A pointer to struct
 * Return: 1 if the key was removed
 */


int env_remove_key(char *key, _st *nick)
{
	int i, key_length = 0;

	if (key == NULL || nick->env == NULL)
		return (0);

	/* obtains the leng of the variable requested */
	key_length = str_length(key);

	for (i = 0; nick->env[i]; i++)
	{
		if (str_compare(key, nick->env[i], key_length) &&
		 nick->env[i][key_length] == '=')
		{
			/* if key already exists, remove them */
			free(nick->env[i]);

			/* move the others keys one position down */
			i++;
			for (; nick->env[i]; i++)
			{
				nick->env[i - 1] = nick->env[i];
			}
			nick->env[i - 1] = NULL;
			return (1);
		}
	}
	return (0);
}


/**
 * print_environ - prints the current env variables
 * @nick: A pointer to struct
 *
 * Return: void
 */


void print_environ(_st *nick)
{
	int j;

	for (j = 0; nick->env[j]; j++)
	{
		_print(nick->env[j]);
		_print("\n");
	}
}
