/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edilson <edilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:12:39 by edilson           #+#    #+#             */
/*   Updated: 2023/12/22 01:02:05 by edilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_ctrl(int sig)
{
	if (sig == SIGINT)
	{
		code_set = 130;
		ft_putendl_fd("", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	if (sig == SIGQUIT)
	{
		code_set = 127;
		rl_redisplay();
	}
}

void	exec_lilcom(char *str, char **env)
{
	char	*log;
	char	**path;

	path = get_path2(find_path(env));
	if (check_com(str, "exit") && check_path_bult(str, path))
	{
		printf("quit\n");
		exit(0);
	}
	if (check_com(str, "pwd") && check_path_bult(str, path))
		printf("%s\n", getcwd(NULL, 10000000));
	if (check_com(str, "env") && check_path_bult(str, path))
		print_env(env);
	if (check_com(str, "echo") && check_path_bult(str, path))
		printf("\n");
	if (check_com(str, "cd") && check_path_bult(str, path))
	{
		log = getenv("LOGNAME=");
		log = ft_strjoin("/Users/", log);
		printf("log = %s\n", log);
		chdir(log);
	}
}

void	other_com(char *str, char **env)
{
	char	**tab;
	char	*sstr;

	sstr = ft_strdup(str);
	tab = ft_split(sstr, ' ');
	if (check_com(tab[0], "echo") && check_com(tab[1], "-n"))
		print_echo(&tab[1], 1, env);
	else if (check_com(tab[0], "echo"))
		print_echo(tab, 1, env);
	else if (check_com(tab[0], "exit"))
		ft_exit(&tab[1], env);
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
		other_com(cmd, env);
		check_unset(cmd, env);
		check_export(cmd, env);
	}
}

void	print_ctl(int n)
{
	struct termios	termin;

	tcgetattr(STDIN_FILENO, &termin);
	if (n == 0)
		termin.c_lflag |= ECHOCTL;
	if (n == 1)
		termin.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &termin);
}

int	ft_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*pars_com(char *str, char **env)
{
	if (find_quote(str))
		str = quote(str, env);
	if (!str)
		return (NULL);
	while (ft_analyse(str))
		str = get_newstr(str, env);
	return (str);
}

void	exec_com(char *str, char **env)
{
	char	**tab;
	char	*sstr;

	sstr = ft_strdup(str);
	tab = ft_split(sstr, ' ');
	if (!tab[1])
	{
		exec_lilcom(tab[0], env);
		tab_free(tab);
		return ;
	}
	else
	{
		check_other(str, env);
		tab_free(tab);
		return ;
	}
}

void	get_com(char **env)
{
	char	*str;

	print_ctl(1);
	signal(SIGINT, ft_ctrl);
	signal(SIGQUIT, ft_ctrl);
	str = readline("minishell$> ");
	if (str == NULL)
	{
		printf("quit\n");
		exit(0);
	}
	print_ctl(0);
	if (str[0])
	{
		add_history(str);
		str = pars_com(str, env);
		if (!str)
			return ;
		exec_com(str, env);
	}
}

int	main(int argc, char **argv, char **env)
{
	char	**env2;

	code_set = 0;
	if (argc != 1)
	{
		ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
		exit(0);
	}
	if (argv)
		argv = &argv[1];
	env2 = get_env(env);
	while (1)
	{
		get_com(env2);
	}
	return (0);
}
