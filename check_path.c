/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edilson <edilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:44:40 by edilson           #+#    #+#             */
/*   Updated: 2023/12/18 18:16:32 by edilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_path1(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '/')
		i++;
	return (ft_strdup(&str[i]));
}

char	**get_path2(char *env)
{
	char	**tab;
	char	*str;
	int		j;

	j = 0;
	str = get_path1(env);
	tab = ft_split(str, ':');
	free(str);
	while (tab[j])
	{
		tab[j] = ft_strjoin2(tab[j], "/");
		j++;
	}
	return (tab);
}

char	*find_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strstr(env[i], "PATH=") == 1)
			return (env[i]);
		i++;
	}
	return (NULL);
}

int	absolute(char *str)
{
	int		j;

	j = 0;
	j = access(str, X_OK);
	if (j == -1)
		return (0);
	return (1);
}

int	check_path_bult(char *com, char **env)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	j = 0;
	if (ft_strstr(com, "/") == 1)
		return (absolute(com));
	while (env[++i])
	{
		str = ft_strjoin(env[i], com);
		j = access(str, X_OK);
		if (j == -1 && !env[i + 1])
		{
			ft_putstr_fd("The commend does not exist !\n", 2);
			code_set = 127;
			return (0);
		}
		if (j != -1)
			return (1);
		free(str);
	}
	return (0);
}
