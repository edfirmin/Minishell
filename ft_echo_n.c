/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edilson <edilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:36:34 by edilson           #+#    #+#             */
/*   Updated: 2023/11/26 21:44:15 by edilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_echo(char **tab, int fd)
{
	int	i;

	i = 0;
	if (!tab[0])
		return ;
	i++;
	while (tab[i])
	{
		ft_putstr_fd(tab[i], fd);
		if (tab[i + 1])
			ft_putchar_fd(' ', fd);
		i++;
	}
	if (check_com(tab[0], "-n") && tab[1])
	{
		ft_putstr_fd("\x1b[47m", fd);
		ft_putendl_fd("\x1b[30m%\x1b[0m", fd);
	}
	else if (!check_com(tab[0], "-n"))
		ft_putchar_fd('\n', fd);
}
