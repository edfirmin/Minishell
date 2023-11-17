/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makecdwork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edilson <edilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:30:14 by gfabre            #+#    #+#             */
/*   Updated: 2023/11/17 14:57:20 by edilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_absolute(char *str, int index)
{
	if (str[index] == '~')
	{
		index++;
		make_absolute(str, index, 0);
		return (1);
	}
	if (str[index] == '/')
	{
		make_absolute(str, index, 1);
		return (1);
	}
	return (0);
}

void	whereyougo(char *str, int index)
{
	int		size;
	int		checkpoint;
	char	*pwd;
	char	*way;

	if (check_dblpnt(str, index) == 1)
		return ;
	if (check_absolute(str, index) == 1)
		return ;
	size = 0;
	checkpoint = index;
	pwd = getcwd(NULL, 0);
	while (pwd[size])
		size++;
	while (str[index])
	{
		size++;
		index++;
	}
	way = malloc(sizeof(char) * (size + 2));
	way = ft_strjoin(pwd, "/");
	way = ft_strjoin(way, &str[checkpoint]);
	if (chdir(way) == -1)
		print_noway(&str[checkpoint]);
	free(way);
}

int	check_dblpnt(char *str, int index)
{
	char	*pwd;
	char	*way;
	int		j;

	j = 0;
	if (str[index] == '.' && str[index + 1] == '.')
	{
		pwd = getcwd(NULL, 0);
		index = get_index(str, index + 2, pwd);
		way = malloc(sizeof(char) * (index + 1));
		while (j < index)
		{
			way[j] = pwd[j];
			j++;
		}
		chdir(way);
		free(way);
		return (1);
	}
	return (0);
}

int	get_index(char *str, int index, char *pwd)
{
	int	nbofpnt;
	int	checkpoint;

	nbofpnt = 1;
	while (str[index] == '.')
	{
		nbofpnt++;
		index++;
	}
	index = 0;
	checkpoint = nbofpnt;
	while (pwd[index])
		index++;
	while (index > 0 && nbofpnt > 0)
	{
		if (pwd[index] == '/')
			nbofpnt--;
		index--;
	}
	if (index == 0)
	{
		print_error(checkpoint);
		return (0);
	}
	return (index + 1);
}

void	print_error(int checkpoint)
{
	ft_putstr_fd("cd: no such file or directory: ", 2);
	while (checkpoint >= 0)
	{
		ft_putchar_fd('.', 2);
		checkpoint--;
	}
	ft_putchar_fd('\n', 2);
}
