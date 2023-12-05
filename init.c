#include "philo.h"

t_philo	*init_philos(int ac, char **av)
{
	t_philo	*philo;
	int		i;
	int		num_philo;

	i = 0;
	num_philo = ft_atoi(av[1]);
	philo = (t_philo *)malloc(sizeof(t_philo) * num_philo);
	philo->is_dead = 0;
	while (i < num_philo)
	{
		philo[i].id = i + 1;
		philo[i].time_to_die = ft_atoi(av[2]);
		philo[i].time_to_eat = ft_atoi(av[3]);
		philo[i].time_to_sleep = ft_atoi(av[4]);
		philo[i].eat_count = 0;
		philo[i].last_meal = 0;
		if (ac == 6)
			philo[i].max_eat = ft_atoi(av[5]);
		else
			philo[i].max_eat = -1;
		i++;
	}
	init_forks(philo, num_philo, -1);
	return (philo);
}

t_philo	*init_forks(t_philo *philo, int num_plilo, int i)
{
	pthread_mutex_t	*forks;

	forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num_plilo);
	while (++i < num_plilo)
		pthread_mutex_init(&forks[i], NULL);
	i = -1;
	while (++i < num_plilo)
	{
		if (i + 1 != num_plilo)
		{
			philo[i].left_fork = &forks[i];
			philo[i].right_fork = &forks[(i + 1) % num_plilo];
		}
		else
		{
			philo[i].left_fork = &forks[(i + 1) % num_plilo];
			philo[i].right_fork = &forks[i];
		}
	}
	i = -1;
	init_threads(philo, num_plilo, -1);
	while(++i < num_plilo)
		pthread_mutex_destroy(&forks[i]);
	free(forks);
	return (philo);
}

int	init_threads(t_philo *philo, int num_philo, int i)
{
	pthread_t	*thread;
	t_info		info;

	pthread_mutex_init(&info.print, NULL);
	info.t_start = get_time(0);
	info.death_occurred = 0;
	info.max_eats = 0;
	info.num_philo = num_philo;
	thread = (pthread_t *)malloc(sizeof(pthread_t) * num_philo);
	while (++i < num_philo)
	{
		philo[i].info = &info;
		philo[i].t_start = info.t_start;
		if (pthread_create(&thread[i], NULL,  &philo[i]) != 0)
			return (1);
	}
	philo_checker(philo, num_philo);
	i = -1;
	while 
}
int	args_valid(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	if (ac < 5 || ac > 6)
		return (0);
	while (i < ac)
	{
		j = 0;
		while (av[i])
		{
			if (atol(av[i]) == 666966696669)
				return (0);
			j = 0;
			while (av[i][j])
			{
				if (av[i][j] < '0' || av[i][j] > '9')
					return (0);
				j++;
			}
		}
		i++;
	}
	return (1);
}
