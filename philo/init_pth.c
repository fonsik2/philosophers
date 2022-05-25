/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pth.c                                         :+:      :+:    :+:   */
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
	pthread_t	*life_set;	

	ok = pthread_create(arg_set->tmr_ptr, NULL, f_killer, arg_set); //&arg_set
	if (ok != 0)
		{
			printf("Error: Creating pthread\n");
			return (-1);
		}
	life_set = arg_set->phs_ptr;
	i = 0;
	while (i < arg_set[0].n_phs)
	{
		ok = pthread_create(life_set + i, NULL, f_action, arg_set + i);
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

	arg = *arg_set;
	pthread_join(*arg.tmr_ptr, NULL);
	i = 0;
	while (i < arg.n_phs)
	{
		ok = pthread_join(*(arg.phs_ptr + i), NULL);
		if (ok != 0)
		{
			printf("Error: Joining pthread\n");
			return (-1);
		}
		ok = pthread_mutex_destroy(arg.fkl_ptr + i);
		if (ok != 0)
		{
			printf("Error: mutex destroy\n");
			return (-1);
		}
		i++;
	}
	ok = pthread_mutex_destroy(arg.fkl_ptr + i);
	if (ok != 0)
	{
		printf("Error: mutex destroy\n");
		return (-1);
	}
	free(arg.tmr_ptr);
	free(arg.fkl_ptr);
	free(arg.phs_ptr);
	free(arg_set);
	return (0);
}
