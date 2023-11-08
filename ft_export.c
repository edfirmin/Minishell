/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfabre <gfabre@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:20:06 by gfabre            #+#    #+#             */
/*   Updated: 2023/10/06 21:50:10 by gfabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export(char *str, char **env)
{
	int	j;
	int	i;
	int	k;

	i = 6;
	k = 0;
	j = check_if_alrdy(str, env);
	while (str[i] == ' ' || str[i] == '	')
		i++;
	if (j != -1)
	{
		while (str[i])
		{
			env[j][k] = str[i];
			i++;
			k++;
		}
		env[j][k] = '\0';
	}
	else if (j == -1)
		ft_export2(str, env);
}

int	check_if_alrdy(char *str, char **env)
{
	int		j;
	char	*word;

	j = 0;
	word = get_word(str);
	while (env[j])
	{
		if (exist(word, env[j]) == 1)
			return (j);
		j++;
	}
	return (-1);
}

char	*get_word(char *str)
{
	int		i;
	int		j;
	char	*word;

	i = 6;
	j = 0;
	while (str[i] == ' ' || str[i] == '	')
		i++;
	j = i;
	while (str[j] != '=')
		j++;
	j = j - i;
	word = malloc(sizeof(char) * (j + 1));
	j = 0;
	while (str[i] != '=')
	{
		word[j] = str[i];
		j++;
		i++;
	}
	word[j] = '\0';
	return (word);
}

int	exist(char *word, char *env)
{
	int	i;

	i = 0;
	while (env[i] != '=')
	{
		if (env[i] != word[i])
			return (-1);
		i++;
	}
	return (1);
}

void	ft_export2(char *str, char **env)
{
	int		j;
	int		i;
	char	*bug;

	j = 0;
	i = 6;
	bug = ft_strdup(env[3]);
	while (env[j])
		j++;
	env[j + 1] = NULL;
	env[j] = ft_strdup(env[j - 1]);
	j--;
	while (str[i] == ' ' || str[i] == '	')
		i++;
	env[j] = ft_strdup(&str[i]);
	env[3] = ft_strdup(bug);
	return ;
}
