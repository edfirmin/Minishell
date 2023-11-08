/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jsp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfabre <gfabre@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:16:32 by gfabre            #+#    #+#             */
/*   Updated: 2023/11/08 15:42:12 by gfabre           ###   ########.fr       */
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
			return (i);
		i++;
	}
	return (-1);
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
	while (str[i] != ' ' && str[i] != '\0')
	{
		j++;
		i++;
	}
	replace = malloc(sizeof(char) * (j + 1));
	j = 0;
	i = 0;
	while (str[i] != '$')
		i++;
	i++;
	while (str[i] != ' ' && str[i] != '\0')
	{
		replace[j] = str[i];
		i++;
		j++;
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
		if (ft_strstr(env[j], replace) == 1)
			break ;
		j++;
	}
	if (env[j] == NULL)
		return (NULL);
	while (env[j][i] != '=')
		i++;
	i++;
	while (env[j][i])
	{
		replace[k] = env[j][i];
		k++;
		i++;
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
	newstr = malloc(sizeof (char) * (newsize + 1));
	while (str[i] != '$')
	{
		newstr[j] = str[i];
		i++;
		j++;
	}
	while (replace[k] != '\0')
	{
		newstr[j] = replace[k];
		j++;
		k++;
	}
	while (str[i] != ' ' && str[i] != '\0')
		i++;
	if (str[i] != '\0')
	{
		while (str[i])
		{
			newstr[j] = str[i];
			i++;
			j++;
		}
	}
	newstr[j] = '\0';
	return (newstr);
}
//gerer si il y a des chose derriere les $qlqchose genre cd $PATH | ls 