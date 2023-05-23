#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H


void kimba(_st *nick, int arc, char *argv[], char **env);
void muturi(char *prompt, _st *nick);
void ctrl_c_hndl(int opr UNUSED);
int lgc_ops(char *array_commands[], int i, char array_operators[]);
void var_exp(_st *nick);
void alias_exp(_st *nick);
int add_buf(char *buffer, char *str_to_add);
void _token(_st *nick);
int _execve(_st *nick);
int blt_in_lst(_st *nick);
int p_alias(_st *nick, char *alias);
char *alias_get(_st *nick, char *alias);
int set_alias(char *alias_string, _st *nick);
char **_tok(_st *nick);
int prog_fnd(_st *nick);


#endif
