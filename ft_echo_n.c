/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edilson <edilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:36:34 by edilson           #+#    #+#             */
/*   Updated: 2023/12/30 17:21:08 by edilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_echo(char **tab, int fd, char **env, char *str)
{
	char	**path;
	int		i;

	i = ft_strlen("echo") + 1;
	if (check_com(tab[0], "-n"))
		i = i + 3;
	if (!tab[0])
		return ;
	path = get_path2(find_path(env));
	if (!check_path_bult("echo", path))
		return ;
	ft_putstr_fd(&str[i], fd);
	if (check_com(tab[0], "-n") && tab[1])
	{
		ft_putstr_fd("\x1b[47m", fd);
		ft_putendl_fd("\x1b[30m%\x1b[0m", fd);
	}
	else if (!check_com(tab[0], "-n"))
		ft_putendl_fd("", fd);
}
