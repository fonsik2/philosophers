/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smdyan <smdyan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 10:14:48 by smdyan            #+#    #+#             */
/*   Updated: 2022/05/05 23:56:46 by smdyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>
# include <stdio.h>

typedef struct params
{
	int				n_phs;
	int				t_die;
	struct timeval	tv_eat;
	struct timeval	tv_srt;
	int				t_eat;
	int				t_slp;
	int				n_eat;
	int				id;
	int				alive;
	int				*sim_on;
	pthread_mutex_t	*fkl_set;
	pthread_mutex_t	*p_lock;
	pthread_mutex_t	*a_lock;
	pthread_t		*phs_set;
	pthread_t		*monitor_p;
}				t_par;

int				ft_atoi(const char *str);
void			ft_swap(int *a, int *b);
long			t_interval(struct timeval tv1, struct timeval tv2);
long			t_current(struct timeval tv_srt);
void    		print_msg(const char *text, long t_v, int id, pthread_mutex_t *sout_lock);
void			*f_killer(void *arg);
void			*f_action(void *arg);
t_par			*set_arg(int argc, char **argv);
int				frk_init(t_par *arg);
int				phs_init(t_par *arg);
int				life_run(t_par *arg_set);
int				life_dwn(t_par *arg_set);

#endif
