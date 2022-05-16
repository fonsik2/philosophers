/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smdyan <smdyan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 01:20:53 by smdyan            #+#    #+#             */
/*   Updated: 2022/05/14 02:46:46 by smdyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void act_slp(int phs_id, int t_slp);

void *f_action(void *param)
{
	t_par arg;

	arg = * (t_par*) param;
    act_slp(arg.phs_id, arg.t_slp);
	return NULL;
}

void act_slp(int phs_id, int t_slp)
{
    printf("time to sleep:%d", t_slp);
    printf("time:%lld ID:%d is sleeping\n", cur_time(), phs_id);
    usleep((useconds_t)t_slp * 1000);
    printf("time:%lld ID:%d wakeup\n", cur_time(), phs_id);
    }
