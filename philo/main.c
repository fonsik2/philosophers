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
	t_par			*arg_set;

	arg_set = set_arg(argc, argv);
	if (!arg_set || *(arg_set->sim_on) == 0)
		return (-1);
	life_run(arg_set);
	life_dwn(arg_set);
	printf("Done\n");
	return (0);
}
