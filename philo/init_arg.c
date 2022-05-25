/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smdyan <smdyan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 11:21:27 by smdyan            #+#    #+#             */
/*   Updated: 2022/05/05 23:54:04 by smdyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "philo.h"

void reset_arg(t_par *arg)
{
	arg->n_phs = 0;
	arg->t_die = 0;
	arg->t_eat = 0;
	arg->t_slp = 0;
	arg->id = 0;
	arg->n_eat = 0;
	arg->alive = 1;
	arg->ok = 1;
}

t_par	pars_arg(int argc, char **argv)
{
	t_par arg;
	int i;

	reset_arg(&arg);
	i = 0;
	if (argc == 5 || argc == 6)
	{
		arg.n_phs = ft_atoi(*(argv + ++i));
		arg.t_die = ft_atoi(*(argv + ++i));
		arg.t_eat = ft_atoi(*(argv + ++i));
		arg.t_slp = ft_atoi(*(argv + ++i));
		if (argc == 6)
			arg.n_eat = ft_atoi(*(argv + ++i));
	}
	else
		ft_putstr("Error: n_phs t_die t_eat t_slp n_eat \n");
	return(arg);
}

t_par *set_arg(int argc, char **argv)
{
	t_par	*arg_set;
	t_par	arg;
	int		inx;

	inx = 0;
	arg = pars_arg(argc, argv);
	arg.fkl_ptr = frk_init(arg.n_phs);
	arg.phs_ptr = phs_init(&arg);
	arg_set = (t_par*)malloc(sizeof(t_par)*arg.n_phs);
	if (arg_set == 0)
	{
		printf("Error: memory fault\n");
		free(arg.phs_ptr);
		free(arg.fkl_ptr);
		exit (-1);
	}
	while(inx < arg.n_phs)
	{
		arg.id++;
		*(arg_set + inx) =  arg;
		inx++;
	}
	return(arg_set);
}
