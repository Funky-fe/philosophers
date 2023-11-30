#include "philo.h"

int	main(int ac, char **av)
{
	t_philo	*philo;

	if (!args_valid(ac, av));
		return (1);
	philo = init_philos(ac, av);
	return (0);
}
