/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smdyan <smdyan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 01:20:53 by smdyan            #+#    #+#             */
/*   Updated: 2022/05/14 02:46:46 by smdyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void hld_frk(t_par *cfg);
void act_eat(t_par *cfg);
void act_slp(t_par *cfg);
void act_thk(t_par *cfg);

void *f_action(void *arg)
{
	t_par   *cfg;
    
    cfg = (t_par*)arg;
    pthread_mutex_lock(cfg->fkl_ptr + cfg->n_phs);
    cfg->tv_srt = cur_time();
    pthread_mutex_unlock(cfg->fkl_ptr + cfg->n_phs);
    while(cfg->ok && cfg->alive)
    {
    hld_frk(cfg);
    act_slp(cfg);
    act_thk(cfg);
    }
	return NULL;
}

void hld_frk(t_par *cfg)
{
    int idx1;
    int idx2;

    idx1 = cfg->id - 1;
    idx2 = cfg->id;
    if (cfg->id == cfg->n_phs)
        idx2 = 0;
    if (cfg->id % 2)
        ft_swap(&idx1, &idx2);
    pthread_mutex_lock(cfg->fkl_ptr + idx1);
    printf("time:%lld ID:%d has taken a fork\n", cur_time(), cfg->id);
    pthread_mutex_lock(cfg->fkl_ptr + idx2);
    printf("time:%lld ID:%d has taken a fork\n", cur_time(), cfg->id);
    act_eat(cfg);
    pthread_mutex_unlock(cfg->fkl_ptr + idx2);
    pthread_mutex_unlock(cfg->fkl_ptr + idx1);
}

void act_eat(t_par *cfg)
{
    if (cfg->alive)
    {
        cfg->tv_srt = cur_time();
        printf("time:%lld ID:%d is eating\n", cur_time(), cfg->id);
        usleep((useconds_t)cfg->t_eat * 1000);
    }
}

void act_slp(t_par *cfg)
{
    if (cfg->alive)
    {
        printf("time:%lld ID:%d is sleeping\n", cur_time(), cfg->id);
        usleep((useconds_t)cfg->t_slp * 1000);
    }
}

void act_thk(t_par *cfg)
{
    if (cfg->alive)
    {
        printf("time:%lld ID:%d is thinking\n", cur_time(), cfg->id);
    }
}