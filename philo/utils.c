/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smdyan <smdyan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 13:00:02 by smdyan            #+#    #+#             */
/*   Updated: 2022/05/06 11:14:08 by smdyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		++str;
	}
}

void	ft_swap(int *a, int *b)
{
	int c;

	c = *b;
	*b = *a;
	*a = c;
}

int		ft_atoi(const char *str)
{
	int		sign;
	int		dig;
	long	res;

	sign = 1;
	dig = 0;
	res = 0;
	while (*str == '\n' || *str == '\t' || *str == '\v'
		|| *str == ' ' || *str == '\r' || *str == '\f')
		str++;
	while (*str == '0')
		str++;
	while ((*str >= '0') && (*str <= '9'))
	{
		res = res * 10 + (*str - '0');
		dig++;
		if (dig > 10 || (res * sign) > INT_MAX || (res * sign) < INT_MIN)
			ft_putstr("Error: Bad parameter");
		str++;
	}
	if (dig == 0 || res == 0)
		ft_putstr("Error: Bad parameter");
	return (int)(res * sign);
}

long long cur_time(void)
{
	long long time;
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	time = current_time.tv_sec * 1000 + current_time.tv_usec/1000;
	return (time);
}