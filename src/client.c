/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:01:17 by marcgar2          #+#    #+#             */
/*   Updated: 2025/05/13 17:14:39 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

t_mt	*client_init(void)
{
	t_mt	*talk;

	talk = malloc(sizeof(t_mt));
	if (!talk)
	{
		ft_putstr("ERR -> Malloc failed!\n");
		exit(EXIT_FAILURE);
	}
	talk->pid_client = 0;
	talk->pid_serv = 0;
	return (talk);
}

void	client_send(t_mt *talk, char *msg)
{
	int	bit_move;
	int	i;
	int	signal;

	i = -1;
	while (++i <= ft_strlen(msg))
	{
		bit_move = -1;
		while (++bit_move < 7)
		{
			if ((msg[i] >> bit_move) & 1)
				signal = SIGUSR2;
			else
				signal = SIGUSR1;
			kill(talk->pid_serv, signal);
			usleep(200);
		}
	}
	return ;
}

int	main(int ac, char **av)
{
	
}