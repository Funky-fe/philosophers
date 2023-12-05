#include "philo.h"

void	pick_forks(t_philo *philo)
{
	pthread_t fork1;
	pthread_t fork2;

	fork1 = philo->left_fork;
	fork2 = philo->right_fork;
	pthread_mutex_lock(fork1);
	print_state(philo, "has taken a fork");
	if (philo->info->num_philo == 1)
		return ;
	pthread_mutex_lock(fork2);
	print_state(philo, "has taken a fork");
	pthread_mutex_lock(&philo->info->print);
	philo->last_meal = get_time(philo->info->t_start);
	philo->eat_count++;
	pthread_mutex_unlock(&philo->info->print);
}

void	eat_start(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->print);
	philo_print(philo->id, "is eating");
	pthread_mutex_unlock(&philo->info->print);
	usleep(philo->time_to_sleep * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	usleep(500);
}

void	thread_function(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		pick_forks(philo);
		if (philo->info->num_philo == 1)
			return (0);
		eat_start(philo);
		pthread_mutex_lock(&philo->info->print);
		if (philo->max_eat == philo->eat_count || philo->info->death_occurred)
		{
			pthread_mutex_unlock(&philo->info->print);
			break;
		}
		philo_print(philo->id, "is sleeping");
		usleep(philo->time_to_sleep * 1000);
		philo_print(philo->id, "is thinking");
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	t_philo	*philo;

	if (!args_valid(ac, av));
		return (1);
	philo = init_philos(ac, av);
	return (0);
}
