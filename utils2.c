/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edilson <edilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:14:46 by gfabre            #+#    #+#             */
/*   Updated: 2023/12/28 16:20:39 by edilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	*ft_free(char *str1, char *str2)
{
	if (str1)
		free(str1);
	if (str2)
		free(str2);
	return (NULL);
}
