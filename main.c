/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edilson <edilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:12:39 by edilson           #+#    #+#             */
/*   Updated: 2023/12/11 13:36:20 by edilson          ###   ########.fr       */
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

	// if (ft_analyse(str))
	// 	str = get_newstr(str, env);
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
	if (check_com(str, "$?"))
		printf("minishell: command not found: %d\n", code_set);
	if (check_com(str, "cd"))
	{
		log = getenv("LOGNAME=");
		log = ft_strjoin("/Users/", log);
		printf("log = %s\n", log);
		chdir(log);
	}
}

void	other_com(char *str)
{
	char	**tab;
	char	*sstr;

	sstr = ft_strdup(str);
	tab = ft_split(sstr, ' ');
	if (check_com(tab[0], "echo") && check_com(tab[1], "-n"))
		print_echo(&tab[1], 1);
	else if (check_com(tab[0], "echo"))
		print_echo(tab, 1);
	else if (check_com(tab[0], "exit"))
		ft_exit(&tab[1]);
	
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
	else
	{
		other_com(cmd);
		check_unset(cmd, env);
		check_export(cmd, env);
	}
}

void print_ctl(int n)
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
	while(str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	**pars_com(char *str, char **env)
{
	char	**tab;

	tab = NULL;
	while (ft_analyse(str))
		str = get_newstr(str, env);
	if (str)
		str = check_sl(str);
	tab = ft_split(str, ';');
	return (tab);
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

void get_com(char **env)
{
	char	*str;
	char	**tab;
	int		i;

	tab = NULL;
	i = 0;
	print_ctl(1);
	signal(SIGINT, ft_ctrl);
	signal(SIGQUIT, ft_ctrl);
	str = readline("minishell$> ");
	if (str == NULL)
	{
		printf("quit\n");
		exit(0);
	}
	if (str[0])
	{
		add_history(str);
		tab = pars_com(str, env);
		while (tab[i])
		{
			exec_com(tab[i], env);
			i++;
		}
		if (tab)
			tab_free(tab);
	}
}

int main(int argc, char **argv, char **env)
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
	while(1)
	{
		get_com(env2);
	}
	return (0);
}
