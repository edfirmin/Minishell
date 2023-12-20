/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edilson <edilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:18:01 by edilson           #+#    #+#             */
/*   Updated: 2023/12/20 03:58:52 by edilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	big_v_exit(char *str)
{
	char	*s1;
	int		i;

	i = 0;
	s1 = "9223372036854775807\0";
	while (s1[i] == str[i] && (s1[i] && str[i]))
	{
		i++;
		if (!s1[i])
			return (1);
	}
	i = 0;
	s1 = "+9223372036854775807\0";
	while (s1[i] == str[i] && (s1[i] && str[i]))
	{
		i++;
		if (!s1[i])
			return (1);
	}
	return (0);
}

int	exit_check_ft(char *str)
{
	char	*s1;
	int		i;

	i = 0;
	s1 = "-9223372036854775808\0";
	while (s1[i] == str[i] && (s1[i] && str[i]))
	{
		i++;
		if (!s1[i])
		{
			free(str);
			str = ft_strdup("-922337203685477580");
			ft_putstr_fd("minishell: number truncated after 18 digits:", 2);
			ft_putendl_fd(" 9223372036854775808", 2);
			return (1);
		}
	}
	if ((str[0] != '-' || str[0] != '+') && str[0] < '9')
		return (1);
	if ((str[0] == '-' || str[0] == '+') && str[1] < '9')
		return (1);
	return (0);
}

char	*ft_truncat(char *str, int i)
{
	char	*nbr;
	int		j;
	int		k;

	if ((big_v_exit(str) || exit_check_ft(str)) && ft_strlen(str) <= 20)
		return (str);
	if (i == 19 && (str[0] == '-' || str[0] == '+'))
		return (str);
	j = 0;
	if (((str[0] == '-' || str[0] == '+') && str[1] < '9') || str[0] < '9')
		return ("0");
	else if (str[0] == '-' || str[0] == '+')
		k = 19;
	else
		k = 18;
	nbr = malloc(k * sizeof(char));
	while (str[j] && k > j)
	{
		nbr[j] = str[j];
		j++;
	}
	return (nbr);
}

long long int	long_nbr(char *nbr, int i)
{
	long long int		n;

	nbr = ft_truncat(nbr, i);
	n = ft_atoi(nbr);
	return (n);
}
