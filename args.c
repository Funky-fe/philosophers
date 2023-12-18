/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlima-fe <rlima-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:18:38 by rlima-fe          #+#    #+#             */
/*   Updated: 2023/12/08 18:15:19 by rlima-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	arg_error()
{
	printf("Error! Invalid Arguments, Use:\n");
	printf("./philo [Philos] [Die] [Eat] [Sleep] [Meals]\n");
}

int	arg_checker(int ac, char **av, t_p *p)
{
	if ((ac == 5 || ac == 6) && ft_isnum(av))
	{
		p->s.philos = ft_atoi(av[1]);
		p->s.time_to_die = ft_atoi(av[2]);
		p->s.time_to_eat = ft_atoi(av[3]);
		p->s.time_to_sleep = ft_atoi(av[4]);
		p->s.meals = -1; 
		if (ac == 6)
			p->s.meals = ft_atoi(av[5]);
		if (p->s.philos <= 0 || p->s.time_to_die <= 0 || p->s.time_to_eat <= 0 \
			|| p->s.time_to_sleep <= 0 || (ac == 6 && p->s.meals <= 0))
			return (0);
		return (1);
	}
	return (0);
}
