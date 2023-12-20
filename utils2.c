/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfabre <gfabre@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:14:46 by gfabre            #+#    #+#             */
/*   Updated: 2023/12/20 01:30:55 by gfabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void	check_unset(char *cmd, char **env)
{
	int	i;

	i = 0;
	while (cmd[i] == ' ' || cmd[i] == '	')
		i++;
	if (cmd[i] == 'u' && cmd[i + 1] == 'n' && cmd[i + 2] == 's'
		&& cmd[i + 3] == 'e' && cmd[i + 4] == 't')
		ft_unset(cmd, env);
	return ;
}

void	check_export(char *cmd, char **env)
{
	int	i;

	i = 0;
	while (cmd[i] == ' ' || cmd[i] == '	')
		i++;
	if (cmd[i] == 'e' && cmd[i + 1] == 'x' && cmd[i + 2] == 'p'
		&& cmd[i + 3] == 'o' && cmd[i + 4] == 'r' && cmd[i + 5] == 't')
		ft_export(cmd, env);
	return ;
}

// va falloir faire un split chaque fois qu on a fini un ' ' ou " " donc peut etre en recursive pour garder le debut du tableau deja gerer ou alors mettre un nouveau caractere devant les
// premiers ' ou " pour pouvoir identifier a chaque fois a quel fct envoyer, genre + pour ' et = pour " ce qui permet de pas faire le split car on rappel la fct a chaque fois
// en utilisant le caractere d id pour utiliser single ou double, si un  seul n'es pas fermer on annule 

// intit char *cpy, prendre string, avant rentrer fcti check si il y a " ou ', il copie tout ce qu il y a dans la string dans cp jusqu a ' ou ",  