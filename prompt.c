/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edilson <edilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 22:02:13 by edilson           #+#    #+#             */
/*   Updated: 2024/01/06 22:35:09 by edilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*pars_com(char *str, char **env)
{
	str = skip_space(str);
	while (ft_analyse(str))
		str = get_newstr(str, env);
	if (!str)
		return (NULL);
	//lexer avec qote//
	// if (find_quote(str))
	// 	str = quote(str, env);
	// if (!str)
	// 	return (NULL);
	return (str);
}

void	exec_com(char *str, char **env)
{
	if (exec_lilcom(str, env))
		return ;
	if (!str)
		return ;
	check_other(str, env);
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
		tab_free(env);
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
