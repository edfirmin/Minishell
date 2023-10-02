/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfabre <gfabre@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:13:48 by gfabre            #+#    #+#             */
/*   Updated: 2023/09/25 18:01:12 by gfabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_unset(char *str, char **env)
{
	int	j;

	j = find_line_unset(str, env);
	if (j != -1)
	{
		while (env[j])
		{
			env[j] = env[j + 1];
			j++;
		}
		env[j] = NULL;
		return (1);
	}
	return (j);
}

int	find_line_unset(char *str, char **env)
{
	int	j;
	int	i;

	i = 5;
	while (str[i] == ' ' || str[i] == '	')
		i++;
	j = get_j(str, env, i);
	return (j);
}

int	get_j(char *str, char **env, int i)
{
	int	j;

	j = 0;
	while (env[j])
	{
		if (get_len(str, env[j], i) == 1)
		{
			return (j);
		}
		j++;
	}
	return (j);
}

int	get_len(char *str, char *env, int i)
{
	size_t	k;

	k = 0;
	while (env[k] != '=')
		k++;
	if (ft_strlen(&str[i]) == k)
	{
		if (check_word(str, env, i) == 1)
			return (1);
		return (-1);
	}
	return (-1);
}

int	check_word(char *str, char *env, int i)
{
	int		j;
	char	*str2;

	j = 0;
	while (env[j] != '=')
		j++;
	str2 = malloc(sizeof(char) * (j));
	j = 0;
	while (env[j] != '=')
	{
		str2[j] = env[j];
		j++;
	}
	j = 0;
	while (str[i])
	{
		if (str2[j] != str[i])
			return (-1);
		i++;
		j++;
	}
	return (1);
}
