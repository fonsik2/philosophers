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

int	frk_init(t_par *arg)
{
	pthread_mutex_t	*frk_set;
    int             ok;
    int             i;

    frk_set = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * (arg->n_phs + 2));
    if (frk_set == 0)
	{
		printf("Error: Memory fault\n");
		return (-1);
	}
	i = 0;
    while (i < arg->n_phs + 2)
	{
		ok = pthread_mutex_init(frk_set + i, NULL);
		if (ok != 0)
		{
			printf("Error: Creating mutex\n");
			free(frk_set);
			return (-1);
		}
		i++;
	}
	arg->fkl_set = frk_set;
	arg->a_lock = frk_set + arg->n_phs;
	arg->p_lock = frk_set + arg->n_phs + 1;
    return (0);
}

int	phs_init(t_par *arg)
{
    pthread_t	*phs_set;
	int			*sim_on;

	sim_on = (int*)malloc(sizeof(int));
	if (!sim_on)
	{
		printf("Error: Memory fault\n");
		free(arg->fkl_set);
		return (-1);
	}
	*sim_on = 0;
	phs_set = (pthread_t *)malloc(sizeof(pthread_t) * arg->n_phs + 1); //n_phs + 1 => tmr_ptr
	if (phs_set == 0)
	{
		printf("Error: Memory fault\n");
		free(sim_on);
		free(arg->fkl_set);
		return (-1);
	}
	arg->phs_set = phs_set;
	arg->monitor_p = phs_set + arg->n_phs;
	arg->sim_on = sim_on;
	return(0);
}

