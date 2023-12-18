/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlima-fe <rlima-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:14:12 by rlima-fe          #+#    #+#             */
/*   Updated: 2023/12/18 13:23:42 by rlima-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_p	philo;

	if (!(arg_checker(ac, av, &philo)))
		arg_error();
	philo.ph = malloc(sizeof(t_philo) * philo.s.philos);
	if (!philo.ph)
	{
		printf("Malloc error\n");
		return (0);
	}
	if (!init(&philo))
	{
		free(philo.ph);
		return (0);
	}
	stop(&philo);
	return (0);
}
