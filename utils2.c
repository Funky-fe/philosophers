/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlima-fe <rlima-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:18:00 by rlima-fe          #+#    #+#             */
/*   Updated: 2023/12/07 17:40:43 by rlima-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_print(t_philo *philo, const char *str)
{
	pthread_mutex_lock(&philo->info->print);
	if (!philo->info->death_occurred)
		printf("%lu %d %s\n", get_time(philo->info->t_start), philo->id, str);
	pthread_mutex_unlock(&philo->info->print);
}
