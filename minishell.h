/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfabre <gfabre@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:54:44 by edilson           #+#    #+#             */
/*   Updated: 2023/11/08 14:11:18 by gfabre           ###   ########.fr       */
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

int		g_error;
void	whereyougo(char *str, int index);
int		check_dblpnt(char *str, int index);
int		get_index(char *str, int index, char *pwd);
void	print_error(int checkpoint);
void	make_absolute(char *str, int index, int n);
void	print_noway(char *str);
void	get_com(char **env);
void	print_env(char **env);
void	print_echo(char **tab);
void	exec_com(char *str, char **env);
int		check_com(char *s1, char *s2);
void	ft_ctrl(int sig);
void	check_other(char *cmd, char **env);
char	**get_env(char **env);
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
int		exist(char *word, char *env);
void	ft_export2(char *str, char **env);
int		ft_analyse(char *str);
char	*get_newstr(char *str, char **env);
char	*get_newstr2(char *str, char *replace);
char	*get_str(char *str);
char	*get_inpath(char *replace, char **env);
int		get_size(char *str, char *replace);

#endif