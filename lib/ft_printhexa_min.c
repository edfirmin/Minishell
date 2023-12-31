/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa_min.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:14:00 by edfirmin          #+#    #+#             */
/*   Updated: 2023/06/22 09:20:37 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printhexa_min(unsigned int n)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789abcdef";
	if (n >= 16)
	{
		i = ft_printhexa_min(n / 16);
		ft_printchar(base[n % 16]);
	}
	else
		ft_printchar(base[(n % 16)]);
	return (i + 1);
}
