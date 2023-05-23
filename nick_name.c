#include "alx.h"

/**
 * var_exp - A function that expands special characters
 * @nick: a pointer to struct
 *
 * Return: void
 */


void var_exp(_st *nick)
{
	int i, j;
	char line[B_SIZ] = {0}, expansion[B_SIZ] = {'\0'}, *temp;

	if (nick->b == NULL)
		return;
	add_buf(line, nick->b);
	for (i = 0; line[i]; i++)
		if (line[i] == '#')
			line[i--] = '\0';
		else if (line[i] == '$' && line[i + 1] == '?')
		{
			line[i] = '\0';
			long_to_string(errno, expansion, 10);
			add_buf(line, expansion);
			add_buf(line, nick->b + i + 2);
		}
		else if (line[i] == '$' && line[i + 1] == '$')
		{
			line[i] = '\0';
			long_to_string(getpid(), expansion, 10);
			add_buf(line, expansion);
			add_buf(line, nick->b + i + 2);
		}
		else if (line[i] == '$' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
			continue;
		else if (line[i] == '$')
		{
			for (j = 1; line[i + j] && line[i + j] != ' '; j++)
				expansion[j - 1] = line[i + j];
			temp = env_get_key(expansion, nick);
			line[i] = '\0', expansion[0] = '\0';
			add_buf(expansion, line + i + j);
			temp ? add_buf(line, temp) : 1;
			add_buf(line, expansion);
		}
	if (!str_compare(nick->b, line, 0))
	{
		free(nick->b);
		nick->b = str_duplicate(line);
	}
}


/**
 * alias_exp - A functionthat expands aliases
 * @nick: a pointer to struct
 *
 * Return: void
 */


void alias_exp(_st *nick)
{
	int i, j, was_expanded = 0;
	char line[B_SIZ] = {0}, expansion[B_SIZ] = {'\0'}, *temp;

	if (nick->b == NULL)
		return;

	add_buf(line, nick->b);

	for (i = 0; line[i]; i++)
	{
		for (j = 0; line[i + j] && line[i + j] != ' '; j++)
			expansion[j] = line[i + j];
		expansion[j] = '\0';

		temp = alias_get(nick, expansion);
		if (temp)
		{
			expansion[0] = '\0';
			add_buf(expansion, line + i + j);
			line[i] = '\0';
			add_buf(line, temp);
			line[str_length(line)] = '\0';
			add_buf(line, expansion);
			was_expanded = 1;
		}
		break;
	}
	if (was_expanded)
	{
		free(nick->b);
		nick->b = str_duplicate(line);
	}
}


/**
 * add_buf - A function appends strings
 * @buffer: A pointer to buffer
 * @str_to_add: string to append to buffer
 *
 * Return: void
 */


int add_buf(char *buffer, char *str_to_add)
{
	int length, i;

	length = str_length(buffer);
	for (i = 0; str_to_add[i]; i++)
	{
		buffer[length + i] = str_to_add[i];
	}
	buffer[length + i] = '\0';
	return (length + i);
}
