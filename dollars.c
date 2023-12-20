/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edilson <edilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:16:32 by gfabre            #+#    #+#             */
/*   Updated: 2023/12/11 15:04:46 by edilson          ###   ########.fr       */
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
	while (str[i] != ' ' && str[i] != '\0' && str[i] != '$')
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
	{
		free(replace);
		return (NULL);
	}
	while (env[j][i] != '=')
		i++;
	free(replace);
	i++;
	replace = ft_strdup(&env[j][i]);
	return (replace);
}

int	go_next(int i, char *str)
{
	int	j;

	j = i + 1;
	while (str[j] && str[j] != '$' && str[j] != ' ' && str[j] != '	')
		j++;
	return (j);
}

int	dol_aloc(char *str)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '$')
		i++;
	k = i;
	while (str[i] && str[i] != ' ' && str[i] != '	')
		i++;
	while (str[i])
	{
		i++;
		j++;
	}
	k = k + j;
	return (k);
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

char	*get_dol(t_int *val, char *str, char *newstr, char *replace)
{
	int	k;

	(*val).i = 0;
	(*val).j = 0;
	k = 0;
	while (str[(*val).i] != '$')
	{
		newstr[(*val).j] = str[(*val).i];
		(*val).i++;
		(*val).j++;
	}
	while (replace[k] != '\0')
	{
		newstr[(*val).j] = replace[k];
		(*val).j++;
		k++;
	}
	(*val).i = go_next((*val).i, str);
	while (str[(*val).i])
	{
		newstr[(*val).j] = str[(*val).i];
		(*val).i++;
		(*val).j++;
	}
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

//gerer multiple $