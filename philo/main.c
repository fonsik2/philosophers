/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smdyan <smdyan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 10:16:21 by smdyan            #+#    #+#             */
/*   Updated: 2022/05/05 23:54:09 by smdyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philo.h"

void *live_func(void *arg)
{
	t_par local_args;

	local_args = * (t_par*) arg;
	usleep((useconds_t)local_args.time_slp);
	stamp_time();
	printf("philo %d is alive\n", local_args.num_phs);
	return NULL;
}

int main(int argc, char **argv)
{
	t_par	args;
	args = pars_arg(argc, argv);
	pthread_t live_pthread;
//	char	*frk_state;
	int		result;
	int 	i;

	stamp_time();
//	frk_state = init_frk(args);
	i = 0;
	while (i < args.num_phs)
	{
		result = pthread_create(&live_pthread, NULL, live_func, &args);
		if (result != 0)
		{
			perror("Creating first pthread\n");
			return EXIT_FAILURE;
		}
		i++;
	}
	result = pthread_join(live_pthread, NULL);
	if (result != 0)
	{
		perror("Joining first pthread\n");
		return EXIT_FAILURE;
	}
	ft_putstr("Done\n");
	printf("time_die=%d\n", args.time_die);
	return (0);
}
