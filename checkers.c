/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlima-fe <rlima-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:20:51 by rlima-fe          #+#    #+#             */
/*   Updated: 2023/12/18 12:54:31 by rlima-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo *ph, int i)
{
	pthread_mutex_lock(&ph->pa->dead_mutex);
	if (i)
		ph->pa->stop = i;
	if (ph->pa->stop)
	{
		pthread_mutex_unlock(&ph->pa->dead_mutex);
		return (1);
	}
	pthread_mutex_unlock(&ph->pa->dead_mutex);
	return (0);
}

void	stop(t_p *p)
{
	int	i;

	i = -1;
	while(!check_death(p->ph, 0))
		ft_usleep(1);
	while (++i < p->s.philos)
		pthread_join(p->ph[i].thread_id, NULL);
	i = -1;
	while (++i < p->s.philos)
		pthread_mutex_destroy(&p->ph[i].left_fork);
	pthread_mutex_destroy(&p->s.write_mutex);
	if (p->s.stop == 2)
		printf("Each philosofer ate %d times\n", p->s.meals);
	free(p->ph);
}
