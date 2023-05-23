#include "alx.h"


/**
 * _print - Writes a sring to the stdout
 * @string: A pointer to the string
 *
 * Return: String bytes
 */


int _print(char *string)
{
	return (write(STDOUT_FILENO, string, str_length(string)));
}


/**
 * _printe - Write a string to the stdout
 * @string: A pointer to the string
 *
 * Return: String bytes
 */


int _printe(char *string)
{
	return (write(STDERR_FILENO, string, str_length(string)));
}


/**
 * _print_error - Write a string to the stdout
 * @nick: a pointer to struct
 * @errorcode: code error
 *
 * Return: the number of bytes written
 */

int _print_error(int errorcode, _st *nick)
{
	char n_as_string[10] = {'\0'};

	long_to_string((long) nick->d, n_as_string, 10);

	if (errorcode == 2 || errorcode == 3)
	{
		_printe(nick->a);
		_printe(": ");
		_printe(n_as_string);
		_printe(": ");
		_printe(nick->f[0]);
		if (errorcode == 2)
			_printe(": Illegal number: ");
		else
			_printe(": can't cd to ");
		_printe(nick->f[1]);
		_printe("\n");
	}
	else if (errorcode == 127)
	{
		_printe(nick->a);
		_printe(": ");
		_printe(n_as_string);
		_printe(": ");
		_printe(nick->c);
		_printe(": not found\n");
	}
	else if (errorcode == 126)
	{
		_printe(nick->a);
		_printe(": ");
		_printe(n_as_string);
		_printe(": ");
		_printe(nick->c);
		_printe(": Permission denied\n");
	}
	return (0);
}
