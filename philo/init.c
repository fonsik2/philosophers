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
	par->num_phs = 0;
	par->time_die = 0;
	par->time_eat = 0;
	par->time_slp = 0;
}

t_par	pars_arg(int argc, char **argv)
{
	t_par par;
	int i;

	reset_arg(&par);
	i = 0;
	if (argc == 5 || argc == 6)
	{
		par.num_phs = ft_atoi(*(argv + ++i));
		par.time_die = ft_atoi(*(argv + ++i));
		par.time_eat = ft_atoi(*(argv + ++i));
		par.time_slp = ft_atoi(*(argv + ++i));
		if (argc == 6)
			par.num_eat = ft_atoi(*(argv + ++i));
	}
	else
		ft_putstr("Error: Bad parameter\n");
	return(par);
}

/*char *init_frk(t_par args)
{
	char	*array;
	int		i;

	i = args.num_phs;
	array = (char *)malloc(i * sizroff(char));
	if (!array)
	{
		ft_putstr("Error: memory fault\n");
		exit(0);
	}
	while(i)
	{
		i--;
		array[i] = 0;
	}
	return (array);
}*/
