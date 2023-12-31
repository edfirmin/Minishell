/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edilson <edilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 03:48:46 by edilson           #+#    #+#             */
/*   Updated: 2023/12/30 18:30:28 by edilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*doub_quote(char *copy, char *str, t_int *val, char **env)
{
	(*val).i++;
	while (str[(*val).i] != '\"' && str[(*val).i])
	{
		copy[(*val).j] = str[(*val).i];
		(*val).i++;
		(*val).j++;
	}
	if (!str[(*val).i])
	{
		ft_putendl_fd("error : double quote open !", 2);
		return (ft_free(str, copy));
	}
	(*val).i++;
	while (ft_analyse(copy))
		copy = get_newstr(copy, env);
	(*val).j = 0;
	while (copy[(*val).j])
		(*val).j++;
	return (copy);
}

char	*sim_quote(char *copy, char *str, t_int *val)
{
	(*val).i++;
	while (str[(*val).i] != '\'' && str[(*val).i])
	{
		copy[(*val).j] = str[(*val).i];
		(*val).i++;
		(*val).j++;
	}
	copy[(*val).j] = '\0';
	if (!str[(*val).i])
	{
		ft_putendl_fd("error : single quote open !", 2);
		return (ft_free(str, copy));
	}
	(*val).j = 0;
	while (copy[(*val).j])
		(*val).j++;
	(*val).i++;
	return (copy);
}

int	quote_aloc(char *str)
{
	int	i;
	int	j;
	int	n;

	n = ft_strlen(str);
	j = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			while (str[i] != '\'' && str[i])
				i++;
			j++;
		}
		if (str[i] == '\"')
		{
			while (str[i] != '\"' && str[i])
				i++;
			j++;
		}
		i++;
	}
	n = (n - j) + 1;
	return (n);
}

char	*quote(char *str, char **env)
{
	char	*copy;
	t_int	val;

	val.i = 0;
	val.j = 0;
	copy = ft_calloc(ft_strlen(str) + 1, sizeof (char));
	while (str[val.i])
	{
		if (str[val.i] == '\'')
			copy = sim_quote(copy, str, &val);
		if (!copy)
			return (NULL);
		if (str[val.i] == '\"')
			copy = doub_quote(copy, str, &val, env);
		if (!copy)
			return (NULL);
		if (str[val.i] && str[val.i] != '\"' && str[val.i] != '\'')
		{
			copy[val.j] = str[val.i];
			val.i++;
			val.j++;
		}
	}
	free(str);
	return (copy);
}

int	find_quote(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			return (1);
		i++;
	}
	return (0);
}
