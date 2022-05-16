/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smdyan <smdyan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 10:16:21 by smdyan            #+#    #+#             */
/*   Updated: 2022/05/13 09:46:01 by smdyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

int main(int argc, char **argv)
{
	t_par			arg;
	pthread_t		*p_life;
	pthread_mutex_t	*fork_lock;
	int				ok;
	int 			i;

	arg = pars_arg(argc, argv);
	i = 0;
	fork_lock = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * arg.n_phs);
	p_life = (pthread_t *)malloc(sizeof(pthread_t) * arg.n_phs);
	if (fork_lock == 0 || p_life == 0)
	{
		ft_putstr("Error: Memory fault\n");
		return (0);
	}
	while (i < arg.n_phs)
	{
		ok = pthread_mutex_init(fork_lock + i, NULL);
		if (ok != 0)
		{
			perror("Creating mutex\n");
			return EXIT_FAILURE;	
		}
		arg.phs_id = i + 1;
		ok = pthread_create(p_life + i, NULL, f_action, &arg);
		if (ok != 0)
		{
			perror("Creating pthread\n");
			return EXIT_FAILURE;
		}
		i++;
	}
	i = 0;
	while (i < arg.n_phs)
	{
		ok = pthread_join(*(p_life + i), NULL);
		if (ok != 0)
		{
			perror("Joining first pthread\n");
			return EXIT_FAILURE;
		}
		i++;
	}
	free(fork_lock);
	free(p_life);
	ft_putstr("Done\n");
	return (0);
}
