/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile_dollars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edilson <edilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 20:42:22 by edilson           #+#    #+#             */
/*   Updated: 2024/01/06 22:43:12 by edilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_analyse(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			i++;
			while (str[i] != '\'')
				i++;
			i++;
		}
		if (str[i] == '$')
			if (isenvchar(str[i + 1]) == 1)
				return (1);
		i++;
	}
	return (0);
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

int	go_next(int i, char *str)
{
	int	j;

	j = i + 1;
	while (str[j] && str[j] != '$' && str[j] != ' '
		&& str[j] != '	' && str[j] != '\'' && str[j] != '\"')
		j++;
	return (j);
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
int	isenvchar(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= '_')
		return (1);
	return (0);
}
