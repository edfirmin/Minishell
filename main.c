/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edilson <edilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:12:39 by edilson           #+#    #+#             */
/*   Updated: 2023/09/21 12:01:21 by edilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	print_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
}

void	exec_com(char *str, char **env)
{
	char	*log;

	if (check_com(str, "exit"))
	{
		printf("quit\n");
		error = 0;
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

void	print_echo(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_putstr_fd(tab[i], 1);
		if (tab[i + 1])
			ft_putchar_fd(' ', 1);
		i++;
	}
}

void	check_other(char *cmd)
{
	int		i;
	char	**tab;

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
	else
	{
		tab = ft_split(cmd, ' ');
		if (check_com(tab[0], "echo") && check_com(tab[1], "-n"))
		{
			print_echo(&tab[2]);
		}
	}
}

void get_com(char **env)
{
	char	*str;
	char	**tab;

	tab = NULL;
	signal(SIGINT, ft_ctrl);
	signal(SIGQUIT, ft_ctrl);
	str = readline("minishell$> ");
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
		else
			check_other(str);
	}
}

int main(int argc, char **argv, char **env)
{
	if (argc != 1)
	{
		ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
		exit(0);
	}
	if (argv)
		argv = &argv[1];
	while(1)
	{
		get_com(env);
	}
	return (0);
}
