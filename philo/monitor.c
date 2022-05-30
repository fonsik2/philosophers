/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smdyan <smdyan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 21:16:04 by smdyan            #+#    #+#             */
/*   Updated: 2022/05/25 21:16:59 by smdyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

struct timeval  set_tv_srt(t_par *arg_set);
void            feedup(t_par *arg_set);

void *f_killer(void *arg)
{
    struct timeval  tv_srt;
    long            stamp_die;
    long            stamp_cur;
    int             i;
    t_par           *arg_set;
    t_par           targ;

    arg_set = (t_par*)arg;
    tv_srt = set_tv_srt(arg_set); //start simulation time value
    i = 0;
    while(*(arg_set->sim_on))
    {     
        while(i < arg_set->n_phs)
        {
            pthread_mutex_lock(arg_set->a_lock);
            targ = arg_set[i];
            pthread_mutex_unlock(arg_set->a_lock);
            stamp_die = t_interval(tv_srt, targ.tv_eat) + targ.t_die;
            stamp_cur = t_current(tv_srt);
            if (stamp_cur >= stamp_die)
            {
                targ.alive = 0;
                *(targ.sim_on) = 0;
                print_msg("died", stamp_die, targ.id, targ.p_lock);
            }
            pthread_mutex_lock(arg_set->a_lock);
            arg_set[i] = targ;
            pthread_mutex_unlock(arg_set->a_lock);
            i++;
        }
        i = 0;
        usleep(100);
        feedup(arg_set); //stop simulation if all feedup
    }
    return NULL;
}

void feedup(t_par *arg_set)
{
    int     i;
    int     n;
    t_par   targ;

    i = 0;
    n = 0;
    pthread_mutex_lock(arg_set->a_lock);
    while (i < arg_set->n_phs)
    {
        targ = arg_set[i];
        n += targ.alive;
        i++;
    }
    if (n == 0)
        *(targ.sim_on) = 0;
    pthread_mutex_unlock(arg_set->a_lock);
}

struct timeval    set_tv_srt(t_par *arg_set)
{
    int             i;
    t_par           targ;
    struct timeval  tv;

    gettimeofday(&tv, NULL);
    i = 0;
    pthread_mutex_lock(arg_set->a_lock);
    while (i < arg_set->n_phs)
    {
        targ = arg_set[i];
        targ.tv_srt = tv;
        targ.tv_eat = tv;
        arg_set[i] = targ;
        i++;
    }
    pthread_mutex_unlock(arg_set->a_lock);
    return (tv);
}
