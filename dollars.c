/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edilson <edilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:16:32 by gfabre            #+#    #+#             */
/*   Updated: 2023/11/23 14:22:39 by edilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_analyse(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

char	*get_newstr(char *str, char **env)
{
	char	*replace;

	replace = get_str(str);
	replace = get_inpath(replace, env);
	str = get_newstr2(str, replace);
	return (str);
}

char	*get_str(char *str)
{
	int		i;
	int		j;
	char	*replace;

	i = 0;
	j = 0;
	while (str[i] != '$')
		i++;
	i++;
	while (str[i + j] != ' ' && str[i + j] != '\0')
		j++;
	replace = malloc(sizeof(char) * (j + 1));
	j = 0;
	while (str[i] != ' ' && str[i] != '\0')
	{
		replace[j++] = str[i];
		i++;
	}
	replace[j] = '\0';
	return (replace);
}

char	*get_inpath(char *replace, char **env)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (env[j])
	{
		if (ft_strstr2(env[j], replace) == 1)
			break ;
		j++;
	}
	if (env[j] == NULL)
		return (NULL);
	while (env[j][i] != '=')
		i++;
	k = ft_strlen(&env[j][i]);
	free (replace);
	replace = ft_calloc(k + 1, sizeof(char));
	k = 0;
	while (env[j][++i])
	{
		replace[k] = env[j][i];
		k++;
	}
	replace[k] = '\0';
	return (replace);
}

char	*get_newstr2(char *str, char *replace)
{
	int		newsize;
	char	*newstr;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	newsize = get_size(str, replace);
	newstr = malloc((newsize + 1) * sizeof(char));
	while (str[i] != '$')
	{
		newstr[j] = str[i];
		i++;
		j++;
	}
	while (replace[k] != '\0')
	{
		newstr[j] = replace[k];
		k++;
		j++;
	}
	newstr = get_newstr3(str, newstr, i, j);
	free(replace);
	return (newstr);
}

//gerer multiple $