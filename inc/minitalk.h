/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:56:05 by marcgar2          #+#    #+#             */
/*   Updated: 2025/05/13 17:03:13 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <signal.h>


typedef struct s_mt
{
	int	pid_serv;
	int	pid_client;
}	t_mt;

//LIBFT UTILS
int		ft_strlen(char *str);
int		ft_atoi(const char *str);
void	ft_putstr(char *str);
void	ft_putnbr(int num);


#endif