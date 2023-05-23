#ifndef STRUCTURES_H
#define STRUCTURES_H

/**
 * struct info- struct for the program's data
 * @a: the name of the executable
 * @b: pointer to the input read for _getline
 * @c: pointer to the first command typed by the user
 * @d: number of excecuted comands
 * @e: file descriptor to the input of commands
 * @f: pointer to array of tokenized input
 * @g: copy of the environ
 * @h: array of pointers with aliases.
 */
typedef struct file
{
	char *a;
	char *b;
	char *c;
	int d;
	int e;
	char **f;
	char **env;
	char **h;
} _st;

/**
 * struct builtins - struct for the builtins
 * @builtin: the name of the builtin
 * @function: the associated function to be called for each builtin
 */
typedef struct builtins
{
	char *builtin;
	int (*function)(_st *nick);
} builtins;

#endif /* STRUCTURES */
