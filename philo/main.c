#include "philo.h"

t_par	pars_arg(int argc, char **argv)
{
	t_par par;
	int i;

	i = 0;
	if (argc == 5 || argc == 6)
	{
		par.num_phs = atoi(*(argv + ++i));
		par.time_die = atoi(*(argv + ++i));
		par.time_eat = atoi(*(argv + ++i));
		par.time_slp = atoi(*(argv + ++i));
		if (argc == 6)
			par.num_eat = atoi(*(argv + ++i));
	}
	else
	{
		par.num_phs = 0;
		printf("Error: %s\n", "required params NUM_PHS TIME_DIE TIME_EAT TIME_SLP [NUM_EAT]");
	}
	return(par);
}

int main(int argc, char **argv)
{
	t_par	arg;
	arg = pars_arg(argc, argv);
	if(arg.num_phs == 0)
		return(1);
	printf("time_die=%d\n", arg.time_die);
	return (0);
}
