/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcingdbl2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfabre <gfabre@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:45:16 by gfabre            #+#    #+#             */
/*   Updated: 2023/12/14 16:46:47 by gfabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_dbl_quote(t_int *val, char *str, char *newstr, char *replace)
{
	int	k;

	(*val).i = 0;
	(*val).j = 0;
	k = 0;
	while (str[(*val).i] != '\"')
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
	(*val).i = go_nextdbl((*val).i, str);
	while (str[(*val).i] && str[(*val).i] != '\"')
	{
		newstr[(*val).j] = str[(*val).i];
		(*val).i++;
		(*val).j++;
	}
	return (newstr);
}

int	go_nextdbl(int i, char *str)
{
	int	j;

	j = i + 1;
	while (str[j] && str[j] != '\"' && str[j] != ' ' && str[j] != '	')
		j++;
	return (j + 1);
}
