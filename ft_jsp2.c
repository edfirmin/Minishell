/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jsp2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfabre <gfabre@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:58:42 by gfabre            #+#    #+#             */
/*   Updated: 2023/11/08 14:48:09 by gfabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_size(char *str, char *replace)
{
	int	strsize;
	int	replacesize;
	int	negativesize;
	int	newtotal;
	int	i;

	strsize = 0;
	replacesize = 0;
	negativesize = 0;
	i = 0;
	while (str[strsize])
		strsize++;
	while (replace[replacesize])
		replacesize++;
	while (str[i] != '$')
		i++;
	while (str[i] != ' ' && str[i] != '\0')
	{
		negativesize++;
		i++;
	}
	printf("strsize = %d\n", strsize);
	printf("replacesize = %d\n", replacesize);
	printf("negativesize = %d\n", negativesize);
	newtotal = (strsize - negativesize) + replacesize + 1;
	return (newtotal);
}
