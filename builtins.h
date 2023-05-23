#ifndef BUILTINS_H
#define BUILTINS_H


/* Builtin prototypes */
int blt_in_ext(_st *nick);
int blt_in_cd(_st *nick);
int st_wk_dir(_st *nick, char *new_dir);
int blt_in_hlp(_st *nick);
int blt_in_alias(_st *nick);
int blt_in_env(_st *nick);
int blt_set_env(_st *nick);
int blt_in_unset_env(_st *nick);
int blt_in_lst(_st *nick);

#endif /* BUILTINS_H */
