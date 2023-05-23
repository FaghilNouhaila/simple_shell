#ifndef ALX_H
#define ALX_H

/**
 * Authour: Nick and Ann
 * File drp: Contains macros, func prototypes and structers
 */


/*File inclusion*/

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>
#include <stdio.h>

#define COMMAND_PROMPT "#KIMBA_REBEL$ "

#define UNUSED __attribute__((unused))

#define B_SIZ 1024

/*===== include structures =====*/

#include "data_handling.h"


/*===== include builtins =====*/

#include "builtins.h"


/*==== include helper functions =====*/

#include "func_library.h"


/*===== include simple_shell functions =====*/

#include "simple_shell.h"


/* Help information display macros */

#define CD_HELP_INFO "cd=\n"\
"cd: cd [dir]"\
"\n\tChange the pwd"\
"\n\tNULL arguments to be treated as cd HOME"\
"\n\tif argument is \"-\", the command changes the pwd"\
"\n\tto previous pwd"

#define EXIT_HELP_INFO "exit=\n"\
"exit: exit [STATUS]"\
"\n\tQuit the shell with a specified status code"\
"\n\tIf no status code is provided, the exit status code"\
"\n\twill be the same as that of the last executed command"

#define ENVIRONMENT_HELP_INFO "env=\n"\
"env: env"\
"\n\tDisplay a complete list of environment variables"\
"\n\tthat are currently set"

#define SETENV_HELP_INFO "setenv=\n"\
"setenv: setenv [VARIABLE VALUE]"\
"\n\tAdd or modify an environment variable"\
"\n\tIf an incorrect number of arguments is provided"\
"\n\tan error message will be displayed"

#define UNSETENV_HELP_INFO "unsetenv=\n"\
"unsetenv: unsetenv [VARIABLE]"\
"\n\tRemove an environment variable"\
"\n\tIf an incorrect number of arguments is provided,"\
"\n\tan error message will be displayed."

#define HELP_INFO_SEARCH "help=\n"\
"help: help [BUILTIN_CMD]"\
"\n\tDisplay information about built-in commands"\
"\n\tIf a specific command name is provided as an argument"\
"\n\tdetailed help for that command will be displayed"\
"\n\tIf no argument is provided, a list of available built-in commands will be displayed"


#endif /* ALX_H */
