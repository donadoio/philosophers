/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine_b.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/21 21:36:24 by idonado       #+#    #+#                 */
/*   Updated: 2021/10/21 21:36:26 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	grab_forks(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->data->fork[philo->left_fork]))
		return ;
	take_action(philo, 2);
	if (pthread_mutex_lock(&philo->data->fork[philo->right_fork]))
		return ;
	take_action(philo, 2);
	return ;
}

void	start_eating(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->is_eating))
		return ;
	take_action(philo, 3);
	philo->last_ate = ft_time();
	philo->meals_eaten++;
	if (pthread_mutex_unlock(&philo->is_eating))
		return ;
	usleep(1000 * philo->data->eating_time);
	if (pthread_mutex_unlock(&philo->data->fork[philo->left_fork]))
		return ;
	if (pthread_mutex_unlock(&philo->data->fork[philo->right_fork]))
		return ;
}

void	sleep_and_start_thinking(t_philo *philo)
{
	take_action(philo, 4);
	usleep(1000 * philo->data->sleeping_time);
	take_action(philo, 5);
	return ;
}
