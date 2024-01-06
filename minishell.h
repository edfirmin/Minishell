/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edilson <edilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:54:44 by edilson           #+#    #+#             */
/*   Updated: 2024/01/06 22:34:32 by edilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "lib/libft.h"
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <dirent.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <termios.h>

int	code_set;

typedef struct s_lexer
{
	char			*str;
	int				token;
	struct s_lexer	*next;
	struct s_lexer	*prev;
}			t_lexer;


typedef struct s_cmds
{
	char			**tab;
	char			*builtin;
	int				num_redir; // comment definir la valeur ?//
	char			*hd_file_name; // c'est quoi ca//
	t_lexer			*redir; //quoi exact. ?//
	struct s_cmds	*next;
	struct s_cmds	*prev;
}				t_cmds;

void			skip_quote(char c, char *s2, char *str, t_int *val);
void			skip_space_2(char *str, char *s2, t_int *val);
char			*skip_space(char *str);

char			*doub_quote(char *copy, char *str, t_int *val, char **env);
char			*sim_quote(char *copy, char *str, t_int *val);
int				quote_aloc(char *str);
char			*quote(char *str, char **env);
int				find_quote(char *str);

void			ft_exit(char **tab);
void			ft_exit0(int n);

void			print_echo(char **tab, int fd, char **env, char *str);

char			**get_path2(char *env);
char			*find_path(char **env);

void			bad_expres(char *str);
long long int	long_nbr(char *nbr, int i);
char			*ft_truncat(char *str, int i);

void			whereyougo(char *str, int index);
void			make_absolute(char *str, int index, int n);
int				check_dblpnt(char *str, int index);
int				get_index(char *str, int index, char *pwd);

void			print_error(int checkpoint);
void			print_noway(char *str);

void			print_env(char **env);
char			**get_env(char **env);

void			get_com(char **env);
int				exec_lilcom(char *str, char **env);
int				other_com(char *str, char **env);
void			check_other(char *cmd, char **env);
void			exec_com(char *str, char **env);
char			*pars_com(char *str, char **env);

void			ft_ctrl(int sig);
void			print_ctl(int n);

void			check_unset(char *cmd, char **env);
int				ft_unset(char *str, char **env);
int				find_line_unset(char *str, char **env);
int				get_j(char *str, char **env, int i);
int				get_len(char *str, char *env, int i);
int				check_word(char *str, char *env, int i);

void			check_export(char *cmd, char **env);
void			ft_export(char *str, char **env);
int				check_if_alrdy(char *str, char **env);
char			*get_word(char *str);
void			ft_export2(char *str, char **env);

int				ft_analyse(char *str);
char			*get_newstr(char *str, char **env);
char			*get_newstr2(char *str, char *replace);
char			*get_str(char *str);
int				isenvchar(char c);
int				go_next(int i, char *str);
int				dol_aloc(char *str);
char			*get_dol(t_int *val, char *str, char *newstr, char *replace);
char			*get_inpath(char *replace, char **env);
int				get_size(char *str, char *replace);
int				ft_strstr2(const char *haystack, const char *needle);
char			*get_newstr3(char *str, char *newstr, int i, int j);

void			*ft_free(char *str1, char *str2);
int				check_com(char *s1, char *s2);
int				check_path_bult(char *com, char **env);

#endif