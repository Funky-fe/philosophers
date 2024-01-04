/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlima-fe <rlima-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:02:25 by rlima-fe          #+#    #+#             */
/*   Updated: 2024/01/04 16:18:30 by rlima-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	Assign and check if the arguments are valid.
*/

int	args(int argc, char **argv, t_p *p)
{
	if ((argc == 5 || argc == 6) && is_number(argv, 0, 1))
	{
		p->a.philos = ft_atoi(argv[1]);
		p->a.time_to_die = ft_atoi(argv[2]);
		p->a.time_to_eat = ft_atoi(argv[3]);
		p->a.time_to_sleep = ft_atoi(argv[4]);
		p->a.meals = -1;
		if (argc == 6)
			p->a.meals = ft_atoi(argv[5]);
		if (p->a.philos <= 0 || p->a.time_to_die <= 0 || p->a.time_to_eat <= 0 \
			|| p->a.time_to_sleep <= 0 || (argc == 6 && p->a.meals <= 0))
			return (0);
		return (1);
	}
	return (0);
}
