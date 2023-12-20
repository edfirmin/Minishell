/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfabre <gfabre@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:54:44 by edilson           #+#    #+#             */
/*   Updated: 2023/12/18 17:34:19 by gfabre           ###   ########.fr       */
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

void	print_echo(char **tab, int fd);
void	ft_exit(char **tab);
void	bad_expres(char *str);
long long int	long_nbr(char *nbr, int i);
char	*ft_truncat(char *str, int i);
char	*check_sl(char *str);
void	whereyougo(char *str, int index);
int	check_dblpnt(char *str, int index);
int	get_index(char *str, int index, char *pwd);
void	print_error(int checkpoint);
void	make_absolute(char *str, int index, int n);
void	print_noway(char *str);
int	check_com(char *s1, char *s2);
void	print_env(char **env);
char	**get_env(char **env);
char	**pars_com(char *str, char **env);

void	get_com(char **env);
void	exec_lilcom(char *str, char **env);
void	exec_com(char *str, char **env);
int		check_com(char *s1, char *s2);
void	ft_ctrl(int sig);
void	check_other(char *cmd, char **env);
void	check_unset(char *cmd, char **env);
int		ft_unset(char *str, char **env);
int		find_line_unset(char *str, char **env);
int		get_j(char *str, char **env, int i);
int		get_len(char *str, char *env, int i);
int		check_word(char *str, char *env, int i);
void	check_export(char *cmd, char **env);
void	ft_export(char *str, char **env);
int		check_if_alrdy(char *str, char **env);
char	*get_word(char *str);
void	ft_export2(char *str, char **env);
int		ft_analyse(char *str);
char	*get_newstr(char *str, char **env);
char	*get_newstr2(char *str, char *replace);
char	*get_str(char *str);
char	*get_inpath(char *replace, char **env);
int		get_size(char *str, char *replace);
int		ft_strstr2(const char *haystack, const char *needle);
char	*get_newstr3(char *str, char *newstr, int i, int j);
int		single(char *str);
char	*get_newstrsingle(char *str);
char	*no_env(char *str, char *newstr);
char	*get_sgl_quote(t_int *val, char *str, char *newstr, char *replace);
int		go_nextsgl(int i, char *str);
char	*get_newstrsingle2(char *str, char *replace);
char	*get_newstrsgl(char *str);
int		dbl(char *str);
char	*get_newstrdbl(char *str);
char	*get_newstrdouble(char *str);
char	*get_dbl_quote(t_int *val, char *str, char *newstr, char *replace);
int		go_nextdbl(int i, char *str);
char	*get_newstrdbl2(char *str, char *replace);
int		check_quote(char *str);

#endif