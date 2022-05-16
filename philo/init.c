/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smdyan <smdyan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 11:21:27 by smdyan            #+#    #+#             */
/*   Updated: 2022/05/05 23:54:04 by smdyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "philo.h"

void reset_arg(t_par *par)
{
	par->n_phs = 0;
	par->t_die = 0;
	par->t_eat = 0;
	par->t_slp = 0;
}

t_par	pars_arg(int argc, char **argv)
{
	t_par par;
	int i;

	reset_arg(&par);
	i = 0;
	if (argc == 5 || argc == 6)
	{
		par.n_phs = ft_atoi(*(argv + ++i));
		par.t_die = ft_atoi(*(argv + ++i));
		par.t_eat = ft_atoi(*(argv + ++i));
		par.t_slp = ft_atoi(*(argv + ++i));
		par.phs_id = 0;
		if (argc == 6)
			par.n_eat = ft_atoi(*(argv + ++i));
	}
	else
		ft_putstr("Error: n_phs t_die t_eat t_slp n_eat \n");
	return(par);
}

