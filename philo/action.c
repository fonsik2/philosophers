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
    if (cfg->id % 2)
        usleep(500);
    else
        usleep(700);
    while(*(cfg->sim_on) && cfg->alive)
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

    idx1 = cfg->id - 1; //own fork
    idx2 = cfg->id; //neighbour fork
    if (cfg->id == cfg->n_phs)
    {
        idx2 = 0;
        ft_swap(&idx1, &idx2);
    }
    pthread_mutex_lock(cfg->fkl_set + idx1); //min first
    print_msg("has taken a fork", t_current(cfg->tv_srt), cfg->id, cfg->p_lock);
    pthread_mutex_lock(cfg->fkl_set + idx2);
    print_msg("has taken a fork", t_current(cfg->tv_srt), cfg->id, cfg->p_lock);
    act_eat(cfg);
    pthread_mutex_unlock(cfg->fkl_set + idx2); //max first
    usleep(100);
    pthread_mutex_unlock(cfg->fkl_set + idx1);
}

void act_eat(t_par *cfg)
{

    if (*(cfg->sim_on) && cfg->alive)
    {
        print_msg("is eating", t_current(cfg->tv_srt), cfg->id, cfg->p_lock);
        pthread_mutex_lock(cfg->a_lock);
        gettimeofday(&cfg->tv_eat, NULL); //reset timer
        if (cfg->n_eat > 0)
            cfg->n_eat -= 1;
        if (cfg->n_eat == 0)
            cfg->alive = 0;
        pthread_mutex_unlock(cfg->a_lock);
        usleep((useconds_t)cfg->t_eat * 1000);
    }
}

void act_slp(t_par *cfg)
{
    if (*(cfg->sim_on) && cfg->alive)
    {
        print_msg("is sleeping", t_current(cfg->tv_srt), cfg->id, cfg->p_lock);
        usleep((useconds_t)cfg->t_slp * 1000);
    }
}

void act_thk(t_par *cfg)
{
    if (*(cfg->sim_on) && cfg->alive)
        print_msg("is thinking", t_current(cfg->tv_srt), cfg->id, cfg->p_lock);
}