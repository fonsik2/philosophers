/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smdyan <smdyan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 20:25:24 by smdyan            #+#    #+#             */
/*   Updated: 2022/05/22 20:25:30 by smdyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t *frk_init(int n_phs)
{
	pthread_mutex_t	*frk_set;
    int             ok;
    int             i;

    frk_set = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * (n_phs + 1));
    if (frk_set == 0)
	{
		printf("Error: Memory fault\n");
		exit(-1);
	}
	i = 0;
    while (i <= n_phs)
	{
		ok = pthread_mutex_init(frk_set + i, NULL);
		if (ok != 0)
		{
			printf("Error: Creating mutex\n");
			free(frk_set);
			exit (-1);
		}
		i++;
	}
    return (frk_set);
}

pthread_t *phs_init(t_par *arg)
{
    pthread_t	*life_set;
	pthread_t	*tmr_ptr;

	tmr_ptr = (pthread_t *)malloc(sizeof(pthread_t));
	arg->tmr_ptr = tmr_ptr;
	life_set = (pthread_t *)malloc(sizeof(pthread_t) * arg->n_phs);
	if (life_set == 0)
	{
		printf("Error: Memory fault\n");
		free(arg->fkl_ptr);
		exit (-1);
	}
	return(life_set);
}

