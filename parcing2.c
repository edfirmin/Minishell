/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfabre <gfabre@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:38:46 by gfabre            #+#    #+#             */
/*   Updated: 2023/12/18 17:34:35 by gfabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_sgl_quote(t_int *val, char *str, char *newstr, char *replace)
{
	int	k;

	(*val).i = 0;
	(*val).j = 0;
	k = 0;
	while (str[(*val).i] != '\'')
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
	(*val).i = go_nextsgl((*val).i, str);
	while (str[(*val).i] && str[(*val).i] != '\'')
	{
		newstr[(*val).j] = str[(*val).i];
		(*val).i++;
		(*val).j++;
	}
	return (newstr);
}

int	go_nextsgl(int i, char *str)
{
	int	j;

	j = i + 1;
	while (str[j] && str[j] != '\'' && str[j] != ' ' && str[j] != '	')
		j++;
	return (j + 1);
}

// int	checkif_lockup(char *str)
// {
// 	int	dbl;
// 	int	i;
// 	int r;

// 	sgl = 0;
// 	dbl = 0;
// 	while (str[i] != '\0')
// 	{
// 		if (str[i] == '\'')
// 			sgl++;
// 		if (str[i] == '\"')
// 			dbl++;
// 		i++;
// 	}
// 	if (dbl == 0)
// 		return (0);
// 	if (dbl % 2 == 0)
// 	{
// 		r = check_place(str);
// 		return (r);
// 	}
// }
