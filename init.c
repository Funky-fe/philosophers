/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlima-fe <rlima-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:34:18 by rlima-fe          #+#    #+#             */
/*   Updated: 2023/12/08 18:34:18 by rlima-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutex(t_p *p)
{
	pthread_mutex_init(&p->s.write_mutex, NULL);
	pthread_mutex_init(&p->s.dead_mutex, NULL);
	pthread_mutex_init(&p->s.time_eat_mutex, NULL);
	pthread_mutex_init(&p->s.finish_mutex, NULL);
}

int	init(t_p *p)
{
	int	i;

	i = 0;
	p->s.start_t = actual_time();
	p->s.stop = 0;
	p->s.number_philos_ate = 0;
	init_mutex(p);
	while (i < p->s.philos)
	{
		p->ph[i].id = i + 1;
		p->ph[i].finish = 0;
		p->ph[i].ms_eat = p->s.start_t;
		p->ph[i].nb_philo_ate = 0;
		p->ph[i].right_fork = NULL;
		pthread_mutex_init(&p->ph[i].left_fork, NULL);
		if (p->s.philos == 1)
			return (0);
		if (i == p->s.philos - 1)
			p->ph[i].right_fork = &p->ph[0].left_fork;
		else
			p->ph[i].right_fork = &p->ph[i + 1].left_fork;
		i++;
	}
	return (1);
}
