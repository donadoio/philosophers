/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   program_init.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/21 21:38:52 by idonado       #+#    #+#                 */
/*   Updated: 2021/10/21 21:38:53 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	data_memory(t_data	*data)
{
	data->philo = malloc(sizeof(t_philo) * data->philos_amount);
	if (data->philo == NULL)
	{
		error("\033[1m\033[31mFailed allocating memory \
for philosophers structs (t_philo)\033[39m");
		return (0);
	}
	data->fork = malloc(sizeof(pthread_mutex_t) * data->philos_amount);
	if (data->fork == NULL)
	{
		error("\033[1m\033[31mFailed allocating memory \
for forks of type (pthread_mutex_t)\033[39m");
		return (0);
	}
	return (1);
}

t_data	data_init(void)
{
	t_data	data;

	data.time_to_die = 0;
	data.philos_amount = 0;
	data.eating_time = 0;
	data.times_all_eat = 0;
	data.sleeping_time = 0;
	data.stop = 0;
	return (data);
}

static int	mutexes_init(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philos_amount)
	{
		if (pthread_mutex_init(&data->fork[i], 0) != 0)
		{
			error("\033[1m\033[31mFailed to initialize mutex for data->fork. \
pthread_mutex_init() failed.\033[39m");
			return (0);
		}
		if (pthread_mutex_init(&data->philo[i].is_eating, 0) != 0)
		{
			error("\033[1m\033[31mFailed to initialize mutex for \
data->philo[n].is_eating. pthread_mutex_init() failed.\033[39m");
			return (0);
		}
		i++;
	}
	if (pthread_mutex_init(&data->register_ability, 0) != 0)
	{
		error("\033[1m\033[31mFailed to initialize mutex for \
data->register_ability. pthread_mutex_init() failed.\033[39m");
		return (0);
	}
	return (1);
}

int	program_init(t_data *data)
{
	int	i;

	i = 0;
	if (data_memory(data) == 0)
		return (0);
	if (mutexes_init(data) == 0)
		return (0);
	while (i < data->philos_amount)
	{
		data->philo[i].left_fork = i;
		data->philo[i].right_fork = (i + 1) % data->philos_amount;
		data->philo[i].philo_number = i + 1;
		data->philo[i].meals_eaten = 0;
		data->philo[i].data = data;
		i++;
	}
	return (1);
}
