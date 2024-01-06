/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultin_ex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edilson <edilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 16:08:47 by edilson           #+#    #+#             */
/*   Updated: 2023/12/31 16:09:07 by edilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_lilcom(char *str, char **env)
{
	char	*log;
	char	**path;

	path = get_path2(find_path(env));
	if (check_com(str, "pwd") && check_path_bult(str, path))
		printf("%s\n", getcwd(NULL, 10000000));
	if (check_com(str, "env") && check_path_bult(str, path))
		print_env(env);
	if (check_com(str, "echo") && check_path_bult(str, path))
	{
		printf("\n");
		tab_free(path);
		return (1);
	}
	if (check_com(str, "cd") && check_path_bult(str, path))
	{
		log = getenv("LOGNAME=");
		log = ft_strjoin("/Users/", log);
		chdir(log);
		tab_free(path);
		return (1);
	}
	tab_free(path);
	return (0);
}

int	other_com(char *str, char **env)
{
	char	**tab;

	tab = ft_split(str, ' ');
	if (check_com(tab[0], "echo") && tab[1] && check_com(tab[1], "-n"))
	{
		print_echo(&tab[1], 1, env, str);
		tab_free(tab);
		free(str);
		return (1);
	}
	else if (check_com(tab[0], "echo"))
	{
		print_echo(tab, 1, env, str);
		tab_free(tab);
		free(str);
		return (1);
	}
	else if (check_com(tab[0], "exit"))
	{
		if (!tab[1])
			ft_exit0(0);
		ft_exit(&tab[1]);
	}
	return (0);
}

void	check_other(char *cmd, char **env)
{
	int		i;
	char	**path;

	i = 0;
	while (cmd[i] == ' ' || cmd[i] == '	')
		i++;
	if (cmd[i] == 'c' && cmd[i + 1] == 'd')
	{
		i = i + 2;
		while (cmd[i] == ' ' || cmd[i] == '	')
			i++;
		path = get_path2(find_path(env));
		if (!check_path_bult("echo", path))
			return ;
		whereyougo(cmd, i);
	}
	else
	{
		if (other_com(cmd, env))
			return ;
		check_unset(cmd, env);
		check_export(cmd, env);
	}
}
