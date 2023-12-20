/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jsp2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfabre <gfabre@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:58:42 by gfabre            #+#    #+#             */
/*   Updated: 2023/11/10 14:57:44 by gfabre           ###   ########.fr       */
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
	newtotal = (strsize - negativesize) + replacesize + 1;
	return (newtotal);
}

int	ft_strstr2(const char *haystack, const char *needle)
{
	size_t	i;

	i = 0;
	if (*haystack == 0)
		return (0);
	if (haystack[i] == needle[i])
	{
		while (haystack[i] != '=' || needle[i])
		{
			if (haystack[i] != needle[i])
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

char	*get_newstr3(char *str, char *newstr, int i, int j)
{
	while (str[i] != ' ' && str[i] != '\0')
		i++;
	if (str[i] != '\0')
	{
		while (str[i])
		{
			newstr[j] = str[i];
			i++;
			j++;
		}
	}
	newstr[j] = '\0';
	return (newstr);
}
