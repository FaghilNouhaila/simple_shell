#include "alx.h"


/**
 * main - Entry point of the shell program
 * @argc: Number of CL arguments
 * @argv: Command line arguments
 * @env: Environment variables
 *
 * Return: 0 is successfull
 */


int main(int argc, char *argv[], char *env[])
{
	/*Variable and structure declaration*/
	_st file_stat = {NULL}, *nick = &file_stat;
	char *prompt = "";

	/*Initialize the file structure fields*/
	kimba(nick, argc, argv, env);

	/*Handle Ctrl+C*/
	signal(SIGINT, ctrl_c_hndl);

	/*Check if the program is connected to a terminal*/
	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO) && argc == 1)
	{
		/*Command prompt*/
		errno = 2;
		prompt = COMMAND_PROMPT;
	}
	errno = 0;

	/*Display prompt and process the user-input*/
	muturi(prompt, nick);

	return (0);
}


/**
 * ctrl_c_hndl - A function that prints the CMD PROMPT
 * @UNUSED: option of the prototype
 *
 */

void ctrl_c_hndl(int opr UNUSED)
{
	/*Do not exit, instead:*/
	/*Display prompt when user-input is Ctrl+c*/
	_print("\n");
	_print(COMMAND_PROMPT);
}


/**
 * kimba - A func that initializes the struct
 * @nick: pointer to struct data
 * @argv: Array pointer to user input
 * @env: env variables
 * @argc: Number of arguments for the CLI
 *
 */


void kimba(_st *nick, int argc, char *argv[], char **env)
{
	int i = 0;

	nick->a = argv[0];/*hsh*/
	nick->b = NULL;/*Read user-input*/
	nick->c = NULL;/*First cmd*/
	nick->d = 0;/*Number of executed cmd*/

	if (argc == 1)/*hsh*/
		nick->e = STDIN_FILENO;/*File descriptors*/
	else
	{
		nick->e = open(argv[1], O_RDONLY);
		if (nick->e == -1)
		{
			_printe(nick->a);
			_printe(": 0: Can't open ");
			_printe(argv[1]);
			_printe("\n");
			exit(127);
		}
	}
	nick->f = NULL;/*Tokenized input*/
	nick->env = malloc(sizeof(char *) * 50);/*Pointer to env*/
	if (env)
	{
		for (; env[i]; i++)/*Duplicate env var(path)*/
		{
			nick->env[i] = str_duplicate(env[i]);
		}
	}
	nick->env[i] = NULL;
	env = nick->env;

	nick->h = malloc(sizeof(char *) * 20);
	for (i = 0; i < 20; i++)
	{
		nick->h[i] = NULL;/*Pointer to aliases*/
	}
}



/**
 * muturi - A func that reads and execute user-input
 * @prompt: A pointer to Shell prompt
 * @nick: A pointer to struct
 *
 */


void muturi(char *prompt, _st *nick)
{
	/*Variable declaration*/
	int error_code = 0, string_len = 0;

	while (++(nick->d))/*Whenever executing*/
	{
		_print(prompt);/*Display prompt*/
		/*Read user-input*/
		error_code = string_len = _getline(nick);

		if (error_code == EOF)/*Check length of cmd*/
		{
			free_all_data(nick);
			exit(errno);
		}
		if (string_len >= 1)/*If cmd is in range*/
		{
			alias_exp(nick);/*Execute alias*/
			var_exp(nick);/*Execute special char*/
			_token(nick);/*Tokenize user-cmd*/
			if (nick->f[0])
			{
				/*Execute user-cmd*/
				error_code = _execve(nick);
				if (error_code != 0)
					_print_error(error_code, nick);
			}
			free_recurrent_data(nick);/*free memory*/
		}
	}
}
