/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfabre <gfabre@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:48:14 by gfabre            #+#    #+#             */
/*   Updated: 2023/09/28 12:01:53 by gfabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_com(char *str, char **env)
{
	char	*log;

	if (check_com(str, "exit"))
	{
		printf("quit\n");
		exit(0);
	}
	if (check_com(str, "pwd"))
		printf("%s\n", getcwd(NULL, 10000000));
	if (check_com(str, "env"))
		print_env(env);
	if (check_com(str, "echo"))
		printf("\n");
	if (check_com(str, "cd"))
	{
		log = getenv("LOGNAME=");
		log = ft_strjoin("/Users/", log);
		chdir(log);
	}
}

int	check_com(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	while (s1[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (0);
	}
	return (1);
}

void	get_com(char **env)
{
	char	*str;
	char	**tab;

	tab = NULL;
	signal(SIGINT, ft_ctrl);
	signal(SIGQUIT, ft_ctrl);
	str = readline("minishell$> ");
	check_other(str, env);
	if (str == NULL)
	{
		printf("quit\n");
		exit(0);
	}
	else if (str[0])
	{
		add_history(str);
		tab = ft_split(str, ' ');
		if (!tab[1])
		{
			exec_com(tab[0], env);
			if (tab)
				tab_free(tab);
		}
	}
}

void	ft_ctrl(int sig)
{
	if (sig == SIGINT)
	{
		rl_replace_line("", 0);
		printf("\n");
		rl_on_new_line();
		rl_redisplay();
	}
	if (sig == SIGQUIT)
	{
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	check_other(char *cmd, char **env)
{
	int		i;

	i = 0;
	while (cmd[i] == ' ' || cmd[i] == '	')
		i++;
	if (cmd[i] == 'c' && cmd[i + 1] == 'd')
	{
		i = i + 2;
		while (cmd[i] == ' ' || cmd[i] == '	')
			i++;
		whereyougo(cmd, i);
	}
	check_unset(cmd, env);
	check_export(cmd, env);
}
