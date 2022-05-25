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
	long long		tv_srt;
	int				t_eat;
	int				t_slp;
	int				n_eat;
	int				id;
	int				alive;
	int				ok;
	pthread_mutex_t	*fkl_ptr;
	pthread_t		*phs_ptr;
	pthread_t		*tmr_ptr;
	
}				t_par;

void			ft_putstr(char *str);
int				ft_atoi(const char *str);
void			ft_swap(int *a, int *b);
long long		cur_time(void);
void			*f_killer(void *arg);
void			*f_action(void *arg);
t_par			*set_arg(int argc, char **argv);
pthread_mutex_t *frk_init(int n_phs);
pthread_t		*phs_init(t_par *arg);
int				life_run(t_par *arg_set);
int				life_dwn(t_par *arg_set);

#endif
