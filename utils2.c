/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfabre <gfabre@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:14:46 by gfabre            #+#    #+#             */
/*   Updated: 2023/10/02 19:43:16 by gfabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_env(char **env)
{
	char	**env2;
	int		j;

	j = 0;
	while (env[j])
		j++;
	env2 = malloc(sizeof (char **) * (j + 1));
	j = 0;
	while (env[j])
	{
		env2[j] = ft_strdup(env[j]);
		j++;
	}
	env2[j] = NULL;
	return (env2);
}

void	check_unset(char *cmd, char **env)
{
	int	i;

	i = 0;
	while (cmd[i] == ' ' || cmd[i] == '	')
		i++;
	if (cmd[i] == 'u' && cmd[i + 1] == 'n' && cmd[i + 2] == 's'
		&& cmd[i + 3] == 'e' && cmd[i + 4] == 't')
		ft_unset(cmd, env);
	return ;
}

void	check_export(char *cmd, char **env)
{
	int	i;

	i = 0;
	while (cmd[i] == ' ' || cmd[i] == '	')
		i++;
	if (cmd[i] == 'e' && cmd[i + 1] == 'x' && cmd[i + 2] == 'p'
		&& cmd[i + 3] == 'o' && cmd[i + 4] == 'r' && cmd[i + 5] == 't')
		ft_export(cmd, env);
	return ;
}
