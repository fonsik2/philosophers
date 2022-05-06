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
	int	num_phs;
	int	time_die;
	int	time_eat;
	int	time_slp;
	int	num_eat;
}				t_par;

t_par	pars_arg(int argc, char **argv);
void	ft_putstr(char *str);
int		ft_atoi(const char *str);
char	init_frk(t_par args);
void	stamp_time(void);

#endif
