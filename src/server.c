/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:29:37 by marcgar2          #+#    #+#             */
/*   Updated: 2025/05/14 15:03:26 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

t_mt	*server_init(void)
{
	static t_mt	*talk = NULL;

	if (!talk) {
		talk = malloc(sizeof(t_mt));
		if (!talk)
		{
			ft_putstr("ERR -> Malloc failed!\n");
			exit(EXIT_FAILURE);
		}
		talk->pid_client = 0;
		talk->pid_serv = 0;
	}
	return (talk);
}

void	server_receive(int signal)
{
	static int	bit_move = 0;
	static char	msg = 0;
	t_mt		*talk;

	talk = server_init();
	if (signal == SIGINT)
	{
		write(1, "\e[1;31m\nSERVER IS CLOSING\n\e[0m", 19);
		free(talk);
		exit(EXIT_SUCCESS);
	}
	if (signal == SIGUSR2)
		msg |= (1 << bit_move);
	msg += ((signal & 1) << bit_move++);
	if (bit_move == 8)
	{
		write(1, &msg, 1);
		if (!msg)
			write(1, "\n", 1);
		bit_move = 0;
		msg = 0;
	}
}

void	server_loop(t_mt *talk)
{
	if ((signal(SIGUSR1, server_receive) == SIG_ERR)
		|| (signal(SIGUSR2, server_receive) == SIG_ERR)
		|| (signal(SIGINT, server_receive) == SIG_ERR))
	{
		ft_putstr("FATAL -> Signal failed!\n");
		free(talk);
		exit(EXIT_FAILURE);
	}
	while (1)
		pause();
}

int	main(int ac, char **av)
{
	t_mt	*talk;

	(void)av;
	talk = NULL;
	if (ac != 1)
	{
		ft_putstr("Usage: ./server <arg1>\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		talk = server_init();
		talk->pid_serv = getpid();
		ft_putstr("SUCCESS!, Server is ready :D! The PID: ");
		ft_putnbr(talk->pid_serv);
		write(1, "\n", 1);
		server_loop(talk);
	}
	free(talk);
	return (EXIT_SUCCESS);
}
