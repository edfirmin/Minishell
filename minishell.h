/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edilson <edilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:54:44 by edilson           #+#    #+#             */
/*   Updated: 2023/09/21 11:09:28 by edilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "lib/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h> 
# include <sys/stat.h> 
# include <unistd.h>
# include <signal.h>

int	error;
void	whereyougo(char *str, int index);
int	check_dblpnt(char *str, int index);
int	get_index(char *str, int index, char *pwd);
void	print_error(int checkpoint);
void	make_absolute(char *str, int index, int n);
void	print_noway(char *str);

#endif