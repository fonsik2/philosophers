/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smdyan <smdyan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 21:16:04 by smdyan            #+#    #+#             */
/*   Updated: 2022/05/25 21:16:59 by smdyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void reset_ok(t_par *arg_set, int alive);

void *f_killer(void *arg)
{
    long long   tv_cur;
    long long   tv_die;
    int         i;
    t_par       *arg_set;

    arg_set = (t_par*)arg;
    i = 0;
    while(arg_set[0].ok)
    {
        usleep(1000);
        pthread_mutex_lock(arg_set[0].fkl_ptr + arg_set[0].n_phs);
        tv_cur = cur_time();
        pthread_mutex_unlock(arg_set[0].fkl_ptr + arg_set[0].n_phs);
        while(i < arg_set[0].n_phs)
        {
            tv_die = arg_set[i].tv_srt + arg_set[0].t_die;
            if (tv_die <= tv_cur)
            {
                arg_set[i].alive = 0;
                printf("time:%lld ID:%d died\n", tv_die, arg_set[i].id);
            }
            i++;
            reset_ok(arg_set, arg_set[i].alive);
        }
    }
    return NULL;
}

void reset_ok(t_par *arg_set, int alive)
{
    int i;

    i = 0;
    if (alive)
        i = arg_set[0].n_phs;
    while (i < arg_set[0].n_phs)
    {
        arg_set[i].ok = 0;
        i++;
    }
}
