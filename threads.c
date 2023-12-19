/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlima-fe <rlima-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:44:38 by rlima-fe          #+#    #+#             */
/*   Updated: 2023/12/18 15:18:49 by rlima-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*is_dead(void *data)
{
	t_philo	*ph;

	ph = (t_philo *)data;
	ft_usleep(ph->pa->time_to_die);
	pthread_mutex_lock(&ph->pa->finish_mutex);
	pthread_mutex_lock(&ph->pa->time_eat_mutex);
	if (!check_death(ph, 0) && !ph->finish && ((actual_time()) - ph->ms_eat) \
		< ph->pa->time_to_die)
	{
		pthread_mutex_unlock(&ph->pa->finish_mutex);
		pthread_mutex_unlock(&ph->pa->time_eat_mutex);
		pthread_mutex_lock(&ph->pa->write_mutex);
		print_action("Died\n", ph);
		pthread_mutex_unlock(&ph->pa->write_mutex);
	}
}

void	*thread(void *data)
{
	t_philo	*ph;

	ph = (t_philo *)data;
	if (ph->id % 2 == 0)
		ft_usleep(ph->pa->time_to_eat / 10);
	while (!check_death(ph, 0))
	{
		simu(ph);
	}
}

/*
	Creates a thread for each philosopher.
*/

int	thread_philo(t_p *p)
{
	int	i;

	i = 0;
	while (i < p->s.philos)
	{
		p->ph[i].pa = &p->s;
		if (pthread_create(&p->ph[i].thread_id, NULL, thread, &p->ph[i]) != 0);
		{
			printf("Error! Pthread did not return 0\n");
			return (0);
		}
		i++;
	}
	return (1);
}