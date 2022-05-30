/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smdyan <smdyan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 20:25:24 by smdyan            #+#    #+#             */
/*   Updated: 2022/05/22 20:25:30 by smdyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int life_run(t_par *arg_set)
{
	int	i;
	int	ok;

	ok = pthread_create(arg_set->monitor_p, NULL, f_killer, arg_set);
	if (ok != 0)
	{
		printf("Error: Creating pthread\n");
		return (-1);
	}

	i = 0;
	while (i < arg_set->n_phs)
	{
		ok = pthread_create(arg_set->phs_set + i, NULL, f_action, arg_set + i);
		if (ok != 0)
		{
			printf("Error: Creating pthread\n");
			return (-1);
		}
		i++;
	}
	return(0);
}

int life_dwn(t_par *arg_set)
{
	int             ok;
    int             i;
	t_par			arg;

	i = 0;
	arg = *arg_set;
	while (i < arg.n_phs + 1)
	{
		ok = pthread_join(*(arg.phs_set + i), NULL);
		if (ok != 0)
		{
			printf("Error: Joining pthread\n");
			return (-1);
		}
		i++;
	}
	i = 0;
	while (i < arg.n_phs + 2)
	{
		ok = pthread_mutex_destroy(arg.fkl_set + i);
		if (ok != 0)
		{
			printf("Error: mutex destroy\n");
			return (-1);
		}
		i++;
	}
	free(arg.fkl_set);
	free(arg.phs_set);
	free(arg.sim_on);
	free(arg_set);
	return (0);
}
