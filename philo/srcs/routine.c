/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/21 21:36:33 by idonado       #+#    #+#                 */
/*   Updated: 2021/10/21 21:36:48 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	*is_dead(void	*arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->data->stop)
	{
		if (pthread_mutex_lock(&philo->is_eating))
			return ((void *)0);
		if ((ft_time() - philo->last_ate) > philo->data->time_to_die)
		{
			take_action(philo, 1);
			philo->data->stop = 1;
			return ((void *)0);
		}
		if (pthread_mutex_unlock(&philo->is_eating))
			return ((void *)0);
		usleep(500);
	}
	return ((void *)0);
}

void	*routine(void	*arg)
{
	t_philo		*philo;
	pthread_t	th;

	philo = (t_philo *)arg;
	if (pthread_create(&th, 0, &is_dead, (void *)philo))
	{
		error("Error when making thread");
		return ((void *)0);
	}
	if (pthread_detach(th))
	{
		error("Error when detaching thread");
		return ((void *)0);
	}
	while (!philo->data->stop)
	{
		grab_forks(philo);
		start_eating(philo);
		sleep_and_start_thinking(philo);
	}
	return ((void *)0);
}

int	routine_end(t_data *data)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (data->stop == 1)
		return (1);
	if (data->times_all_eat > 0)
	{
		while (i < data->philos_amount)
		{
			if (data->philo[i].meals_eaten >= data->times_all_eat)
			{
				count++;
				if (count == data->philos_amount)
				{
					take_action(&data->philo[i], 0);
					data->stop = 1;
					return (1);
				}
			}
			i++;
		}
	}
	return (0);
}

int	routine_init(t_data *data)
{
	pthread_t	th;
	int			i;

	data->start = ft_time();
	i = 0;
	while (i < data->philos_amount)
	{
		if (pthread_create(&th, 0, &routine, (void *)&data->philo[i]))
		{
			error("Error when making thread");
			return (0);
		}
		data->philo[i].last_ate = ft_time();
		if (pthread_detach(th))
		{
			error("Error when detaching thread");
			return (0);
		}
		usleep(99);
		i++;
	}
	while (!routine_end(data))
		usleep(99);
	return (1);
}
