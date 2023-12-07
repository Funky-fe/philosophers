/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlima-fe <rlima-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:25:33 by rlima-fe          #+#    #+#             */
/*   Updated: 2023/12/07 17:49:20 by rlima-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atol(char *str)
{
	int		i;
	long	result;
	int		neg;

	i = 0;
	result = 0;
	neg = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	result = result * neg;
	if (result > INT_MAX || result < INT_MIN)
		return (66696669666);
	return (result);
}

void	philo_checker(t_philo *philo, int num_philo)
{
	int	death;
	int	max_eat;
	int	i;
	
	death = 0;
	max_eat = 0;
	while (1 && !death && !max_eat)
	{
		i = 0;
		while (i < num_philo)
		{
			if (should_philo_die(&philo[i]))
				death = 1;
			if (check_nbr_eats(&philo[i]))
				max_eat = 1;
			i++;
		}
	}
}

unsigned long	get_time(unsigned long t_start)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000 + tv.tv_usec / 1000) - t_start);
}

int	check_nbr_eats(t_philo *philo)
{
	int	nbr_eats;
	pthread_mutex_lock(&philo->info->print);
	nbr_eats = philo->eat_count;
	pthread_mutex_unlock(&philo->info->print);
	if (nbr_eats < philo->max_eat || philo->max_eat == -1)
		return (0);
	philo->info->max_eats = 1;
	return (1);
}

int	should_philo_die(t_philo *philo)
{
	int	last_ate;

	pthread_mutex_lock(&philo->info->print);
	last_ate = get_time(philo->t_start) - philo->last_meal;
	pthread_mutex_unlock(&philo->info->print);
	if (last_ate >= philo->time_to_die)
	{
		pthread_mutex_lock(&philo->info->print);
		if (!philo->info->death_occurred)
		{
			philo->info->death_occurred = 1;
			printf("%lu %d died\n", get_time(philo->t_start), philo->id);
		}
		pthread_mutex_unlock(&philo->info->print);
		return (1);
	}
	return (0);
}
