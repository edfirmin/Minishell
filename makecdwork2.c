/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makecdwork2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edilson <edilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:11:16 by edilson           #+#    #+#             */
/*   Updated: 2023/11/17 15:00:08 by edilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_noway(char *str)
{
	ft_putstr_fd(ft_strjoin("cd: no such file or directory: ", str), 2);
	ft_putchar_fd('\n', 2);
}

void	make_absolute(char *str, int index, int n)
{
	char	*way;
	char	*log;

	if (n == 0)
	{
		log = getenv("HOME=");
		way = ft_strjoin(log, ft_strdup(&str[index]));
	}
	if (n == 1)
		way = ft_strdup(&str[index]);
	if (chdir(way) == -1)
		print_noway(way);
	free(way);
}
