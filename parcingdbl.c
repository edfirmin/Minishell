/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcingdbl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfabre <gfabre@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:50:22 by gfabre            #+#    #+#             */
/*   Updated: 2023/12/14 16:49:56 by gfabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	dbl(char *str)
{
	int	i;
	int	paircheck;

	i = 0;
	paircheck = 0;
	while (str[i])
	{
		if (str[i] == '\"')
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

char	*get_newstrdouble(char *str)
{
	char	*replace;

	replace = get_newstrdbl(str);
	str = get_newstrdbl2(str, replace);
	return (str);
}

char	*get_newstrdbl(char *str)
{
	int		i;
	int		j;
	char	*newstr;

	i = 0;
	j = 0;
	while (str[i] != '\"')
		i++;
	while (str[++i] != '\"')
		j++;
	newstr = malloc(sizeof(char) * (j + 1));
	i = 0;
	j = 0;
	while (str[i] != '\"')
		i++;
	while (str[++i] != '\"')
	{
		newstr[j] = str[i];
		j++;
	}
	newstr[j] = '\0';
	return (newstr);
}

char	*get_newstrdbl2(char *str, char *replace)
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
	newstr = get_dbl_quote(&val, str, newstr, replace);
	newstr = get_newstr3(str, newstr, val.i, val.j);
	free(replace);
	free(str);
	return (newstr);
}
