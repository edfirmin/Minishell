/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edilson <edilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:32:34 by edilson           #+#    #+#             */
/*   Updated: 2023/11/17 14:15:43 by edilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
