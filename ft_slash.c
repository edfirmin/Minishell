/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edilson <edilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:28:30 by edilson           #+#    #+#             */
/*   Updated: 2023/11/23 14:46:44 by edilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_find(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*check_sl(char *str)
{
	char	*s1;
	char	*s2;
	char	*s3;
	int		i;
	int		j;

	i = 0;
	s2 = malloc(1);
	s3 = NULL;
	if (!ft_find(str, '\\'))
		return (str);
	while (str[i])
	{
		s1 = malloc(ft_strlen(str) * sizeof(char));
		j = 0;
		while (str[i] != '\\' && str[i])
		{
			s1[j] = str[i];
			i++;
			j++;
		}
		if (str[i] == '\\' && !str[i + 1])
		{
			s2 = ft_strjoin2(s2, s1);
			while (!s3)
			{
				s3 = readline("> ");
				if (!s3)
				{
					rl_replace_line("", 0);
					rl_redisplay();
				}
			}
			s2 = ft_strjoin2(s2, s3);
		}
		else if (str[i] == '\\' && str[i + 1] == '\\')
		{
			s1 = ft_strjoin(s1, "\\");
			s2 = ft_strjoin2(s2, s1);
			i++;
		}
		else if (str[i] == '\\' && str[i])
		{
			s2 = ft_strjoin2(s2, s1);
		}
		if (!str[i])
			s2 = ft_strjoin2(s2, s1);
		i++;
		free(s1);
	}
	free(str);
	str = ft_strdup(s2);
	return (str);
}
