#include "alx.h"

int prog_fnd(_st *nick);
char **_tok(_st *nick);
int check_file(char *full_path);

/**
 * prog_fnd - find path
 * @nick: a pointer to struct.
 *
 * Return: 0 if successfull.
 */

int prog_fnd(_st *nick)
{
	/*Variable declaration*/
	int i = 0, ret_code = 0;
	char **directories;

	if (!nick->c)/*Check if input is NULL*/
		return (2);
	/*Check if input is '/' || '.'(PATH)*/
	if (nick->c[0] == '/' || nick->c[0] == '.')
		return (check_file(nick->c));
	free(nick->f[0]);/*If not a PATH*/
	nick->f[0] = str_concat(str_duplicate("/"), nick->c);
	if (!nick->f[0])
		return (2);
	directories = _tok(nick);/*Tokenize to find X_OK*/
	if (!directories || !directories[0])
	{
		errno = 127;
		return (127);
	}
	for (i = 0; directories[i]; i++)/*Check every dir for X_OK*/
	{
		directories[i] = str_concat(directories[i], nick->f[0]);
		ret_code = check_file(directories[i]);
		if (ret_code == 0 || ret_code == 126)
		{
			errno = 0;/*If file is found*/
			free(nick->f[0]);
			nick->f[0] = str_duplicate(directories[i]);
			free_array_of_pointers(directories);
			return (ret_code);/*If file is not found*/
		}
	}
	free(nick->f[0]);/*Free memory*/
	nick->f[0] = NULL;
	free_array_of_pointers(directories);
	return (ret_code);
}


/**
 * _tok - tokenize the path.
 * @nick: a pointer to struct
 *
 * Return: array of the  path
 */

char **_tok(_st *nick)
{
	/*Variable declaration*/
	int i = 0;
	int counter_directories = 2;/*1st & last tkn*/
	char **tokens = NULL;
	char *PATH;

	/* get the PATH*/
	PATH = env_get_key("PATH", nick);
	if ((PATH == NULL) || PATH[0] == '\0')
	{
		return (NULL);/*Error statements*/
	}

	PATH = str_duplicate(PATH);/*Duplicate PATH*/

	for (i = 0; PATH[i]; i++)/*Iterate through PATH*/
	{
		if (PATH[i] == ':')/*Delimeter*/
			counter_directories++;
	}

	/* reserve space for tokens*/
	tokens = malloc(sizeof(char *) * counter_directories);

	/*tokenize and duplicate each token of PATH*/
	i = 0;
	tokens[i] = str_duplicate(_strtok(PATH, ":"));
	while (tokens[i++])
	{
		tokens[i] = str_duplicate(_strtok(NULL, ":"));
	}
	/*Free memory*/
	free(PATH);
	PATH = NULL;
	return (tokens);

}

/**
 * check_file - checks if executable file exists
 * @full_path: pointer to the full file name
 *
 * Return: 0 on successfull
 */

int check_file(char *full_path)
{
	/*Structure declare*/
	struct stat sb;

	/*Obtain info about file spcfd by user-arg*/
	if (stat(full_path, &sb) != -1)
	{
		/*Check if file is a dir*/
		/*Check if file has user execute permission*/
		if (S_ISDIR(sb.st_mode) ||  access(full_path, X_OK))
		{
			errno = 126;
			return (126);
		}
		return (0);
	}
	/*if file does not exist*/
	errno = 127;
	return (127);
}
