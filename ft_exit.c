/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edilson <edilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:38:22 by edilson           #+#    #+#             */
/*   Updated: 2023/11/15 14:18:55 by edilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	bad_expres2(char *str, int i)
{
	if (i >= 1 && !str[i + 1])
			ft_putendl_fd("zsh: bad math expression: lvalue required", 2);
		i++;
		if (str[i] != '-' || str[i] != '+')
		{
		ft_putstr_fd("zsh: bad math expression: operator expected at `", 2);
		ft_putstr_fd(&str[i], 2);
		ft_putendl_fd("'", 2);
		return ;
		}
}

void	bad_expres(char *str)
{
	int	i;

	i = 0;
	if (str[i] != '-' || str[i] != '+')
	{
		ft_putstr_fd("zsh: bad math expression: operator expected at `", 2);
		ft_putstr_fd(&str[i], 2);
		ft_putendl_fd("'", 2);
		return ;
	}
	if (ft_strlen(str) == 1)
	{
		if (str[0] == '.')
			return ;
		else
			ft_putendl_fd("zsh: bad math expression: operand expected at end of string", 2);
	}
	while (str[i] == '-' || str[i] == '+')
	{
		bad_expres2 (str, i);
		return ;
	}
}

void	ft_exit(char **tab)
{
	long long int	n;
	int	i;

	i = 0;
	n = 0;
	if (tab[1])
	{
		ft_putstr_fd("exit: too many arguments\n", 2);
		return ;
	}
	if (!ft_isdigit(tab[0][0]) && (tab[0][0] != '-' && tab[0][0] != '+'))
		exit(n);
	else if (tab[0][0] == '-' || tab[0][0] == '+')
		i++;
	while (ft_isdigit(tab[0][i]) && tab[0][i])
		i++;
	if(tab[0][i])
		bad_expres(&tab[0][i]);
	else if (i >= 19)
		n = long_nbr(tab[0], i);
	else 
		n = ft_atoi(tab[0]);
	exit (n);
}
