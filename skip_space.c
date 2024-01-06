/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edilson <edilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 20:35:27 by edilson           #+#    #+#             */
/*   Updated: 2024/01/01 20:57:38 by edilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	skip_quote(char c, char *s2, char *str, t_int *val)
{
	s2[(*val).j] = str[(*val).i];
	(*val).i++;
	(*val).j++;
	while (str[(*val).i] && str[(*val).i] != c)
	{
		s2[(*val).j] = str[(*val).i];
		(*val).i++;
		(*val).j++;
	}
	if (str[(*val).i] == c)
	{
		s2[(*val).j] = str[(*val).i];
		(*val).i++;
		(*val).j++;
	}
	else if (!str[(*val).i])
	{
		if (c == '\'')
			ft_putendl_fd("error : single quote open !", 2);
		if (c == '\"')
			ft_putendl_fd("error : double quote open !", 2);
		ft_free(str, s2);
	}
}

void	skip_space_2(char *str, char *s2, t_int *val)
{
	if ((str[(*val).i] == ' ' || str[(*val).i] == '	'))
	{
		s2[(*val).j] = str[(*val).i];
		(*val).i++;
		(*val).j++;
		while ((str[(*val).i] == ' ' || str[(*val).i] == '	') && str[(*val).i])
			(*val).i++;
	}
	else
	{
		s2[(*val).j] = str[(*val).i];
		(*val).j++;
		(*val).i++;
	}
}

char	*skip_space(char *str)
{
	char	*s2;
	t_int	val;

	val.i = 0;
	val.j = 0;
	s2 = ft_calloc(ft_strlen(str), sizeof (char));
	while (str[val.i] == ' ' || str[val.i] == '	')
		val.i++;
	while (str[val.i])
	{
		if (str[val.i] == '\'' || str[val.i] == '\"')
			skip_quote(str[val.i], s2, str, &val);
		if (!str && !s2)
			return (NULL);
		skip_space_2(str, s2, &val);
	}
	if (s2[val.j - 1] == ' ' || s2[val.j - 1] == '	')
		s2[val.j - 1] = '\0';
	else
		s2[val.j] = '\0';
	free (str);
	str = ft_strdup(s2);
	free(s2);
	return (str);
}
