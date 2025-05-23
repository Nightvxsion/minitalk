/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:00:17 by marcgar2          #+#    #+#             */
/*   Updated: 2025/05/13 17:00:43 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	ft_atoi(const char *str)
{
	int	num;
	int	neg;

	num = 0;
	neg = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + (*str - '0');
		str++;
	}
	return (neg * num);
}

void	ft_putstr(char *str)
{
	if (*str != '\0')
	{
		while (*str != '\0')
		{
			write(1, str, 1);
			str++;
		}
	}
}

void	ft_putnbr(int num)
{
	char	c;

	if (num == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (num < 0)
		{
			write(1, "-", 1);
			num = -num;
			ft_putnbr(num);
		}
		else if (num < 10)
		{
			c = num + '0';
			write(1, &c, 1);
		}
		else
		{
			ft_putnbr(num / 10);
			c = (num % 10) + '0';
			write(1, &c, 1);
		}
	}
}
