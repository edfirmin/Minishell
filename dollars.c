/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edilson <edilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:16:32 by gfabre            #+#    #+#             */
/*   Updated: 2024/01/06 22:33:25 by edilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_newstr(char *str, char **env)
{
	char	*replace;

	replace = get_str(str);
	if (!replace)
		return (str);
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
	{
		if (str[i] == '\'')
		{
			i++;
			while (str[i] != '\'' && str[i] != '\0')
				i++;
			i++;
		}
		if (!str[i])
			break ;
		i++;
	}
	if (!str[i])
		return (NULL);
	i++;
	while (str[i + j] != ' ' && str[i + j] != '\0'
		&& str[i] != '\'' && str[i] != '\"')
		j++;
	replace = malloc(sizeof(char) * (j + 1));
	j = 0;
	while (str[i] != ' ' && str[i] != '\0'
		&& str[i] != '$' && str[i] != '\'' && str[i] != '\"')
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

	i = 0;
	j = 0;
	if (!ft_strncmp(replace, "?", 2))
	{
		free(replace);
		return (ft_itoa(code_set));
	}
	while (env[j])
	{
		if (ft_strstr2(env[j], replace) == 1)
			break ;
		j++;
	}
	if (!env[j])
		return (ft_free(replace, NULL));
	while (env[j][i] != '=')
		i++;
	free(replace);
	i++;
	replace = ft_strdup(&env[j][i]);
	return (replace);
}

char	*no_env(char *str, char *newstr)
{
	int	i;
	int	j;

	j = 0;
	i = dol_aloc(str);
	newstr = malloc((i + 1) * sizeof(char));
	i = -1;
	while (str[++i] != '$')
	{
		newstr[j] = str[i];
		j++;
	}
	i++;
	while (str[i] && str[i] != ' ' && str[i] != '	' && str[i] != '$')
		i++;
	while (str[i])
	{
		newstr[j] = str[i];
		i++;
		j++;
	}
	newstr[j] = '\0';
	free(str);
	return (newstr);
}

char	*get_newstr2(char *str, char *replace)
{
	int		newsize;
	char	*newstr;
	t_int	val;

	val.i = 0;
	val.j = 0;
	newstr = NULL;
	if (!replace)
		return (no_env(str, newstr));
	newsize = get_size(str, replace);
	newstr = malloc((newsize + 1) * sizeof(char));
	newstr = get_dol(&val, str, newstr, replace);
	newstr = get_newstr3(str, newstr, val.i, val.j);
	free(replace);
	free(str);
	return (newstr);
}
