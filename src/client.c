/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:01:17 by marcgar2          #+#    #+#             */
/*   Updated: 2025/05/13 19:04:52 by marcgar2         ###   ########.fr       */
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
	int	len;

	len = ft_strlen(msg);
	i = 0;
	while (i <= len)
	{
		bit_move = -1;
		while (++bit_move < 7)
		{
			if ((msg[i] >> bit_move) & 1)
				signal = SIGUSR2;
			else
				signal = SIGUSR1;
			kill(talk->pid_serv, signal);
			usleep(5);
		}
		i++;
	}
	return ;
}

int	main(int ac, char *av[])
{
	t_mt	*talk;

	talk = NULL;
	if (ac != 3)
	{
		ft_putstr("Usage: ./server with 3 args\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		talk = client_init();
		talk->pid_serv = ft_atoi(av[1]);
		if (talk->pid_serv <= 0)
		{
			ft_putstr("ERR -> PID is = or < than 0");
			free(talk);
			exit(EXIT_FAILURE);
		}
		client_send(talk, av[2]);
	}
	free(talk);
	exit(EXIT_SUCCESS);
}
