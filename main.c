/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfabre <gfabre@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:12:39 by edilson           #+#    #+#             */
/*   Updated: 2023/09/22 16:57:42 by gfabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	char	**env2;

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