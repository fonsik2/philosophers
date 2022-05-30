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

void	ft_swap(int *a, int *b)
{
	int c;

	c = *b;
	*b = *a;
	*a = c;
}

int		ft_atoi(const char *str)
{
	int		dig;
	long	res;

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
		if (dig > 10 || res > INT_MAX)
		{
			printf("Error: Bad parameter\n");
			return (-1);
		}
		str++;
	}
	if (dig == 0)
	{
		printf("Error: Bad parameter\n");
		return (-1);
	}
	return (int)(res);
}

void    print_msg(const char *text, long t_v, int id, pthread_mutex_t *sout_lock)
{
    pthread_mutex_lock(sout_lock);
    printf("%ld ID:%d %s\n", t_v, id, text);
    pthread_mutex_unlock(sout_lock);
}

long t_interval(struct timeval tv1, struct timeval tv2)
{
    long    sec;
    long    msec;

    sec = tv2.tv_sec - tv1.tv_sec;
    msec = (sec * 1000 + tv2.tv_usec / 1000) - tv1.tv_usec / 1000;
    return (msec);
}

long t_current(struct timeval tv_srt)
{
	long    		sec;
    long    		msec;
	struct timeval	tv2;

    gettimeofday(&tv2, NULL);
    sec = tv2.tv_sec - tv_srt.tv_sec;
    msec = (sec * 1000 + tv2.tv_usec / 1000) - tv_srt.tv_usec / 1000;
    return (msec);
}