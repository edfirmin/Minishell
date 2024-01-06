/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edilson <edilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 20:39:08 by edilson           #+#    #+#             */
/*   Updated: 2024/01/01 20:39:23 by edilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_ctrl(int sig)
{
	if (sig == SIGINT)
	{
		code_set = 130;
		ft_putendl_fd("", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	if (sig == SIGQUIT)
	{
		code_set = 127;
		rl_redisplay();
	}
}

void	print_ctl(int n)
{
	struct termios	termin;

	tcgetattr(STDIN_FILENO, &termin);
	if (n == 0)
		termin.c_lflag |= ECHOCTL;
	if (n == 1)
		termin.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &termin);
}
