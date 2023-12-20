/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfabre <gfabre@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:58:33 by gfabre            #+#    #+#             */
/*   Updated: 2023/12/18 17:33:48 by gfabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	single(char *str)
{
	int	i;
	int	paircheck;

	i = 0;
	paircheck = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			paircheck++;
		i++;
	}
	if (paircheck == 0)
		return (0);
	if (paircheck % 2 == 0)
		return (1);
	else
		return (0);
}

char	*get_newstrsgl(char *str)
{
	char	*replace;

	replace = get_newstrsingle(str);
	str = get_newstrsingle2(str, replace);
	return (str);
}

char	*get_newstrsingle2(char *str, char *replace)
{
	int		newsize;
	char	*newstr;
	t_int	val;

	val.i = 0;
	val.j = 0;
	newsize = 0;
	newstr = NULL;
	while (str[newsize])
		newsize++;
	newstr = malloc((newsize - 1) * sizeof(char));
	newstr = get_sgl_quote(&val, str, newstr, replace);
	newstr = get_newstr3(str, newstr, val.i, val.j);
	free(replace);
	free(str);
	return (newstr);
}

char	*get_newstrsingle(char *str)
{
	int		i;
	int		j;
	char	*newstr;

	i = 0;
	j = 0;
	while (str[i] != '\'')
		i++;
	while (str[++i] != '\'')
		j++;
	newstr = malloc(sizeof(char) * (j + 1));
	i = 0;
	j = 0;
	while (str[i] != '\'')
		i++;
	while (str[++i] != '\'')
	{
		newstr[j] = str[i];
		j++;
	}
	newstr[j] = '\0';
	return (newstr);
}
