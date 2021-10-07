#include <philo.h>

int	make_philos(t_data *data, t_philo *philo_data)
{
	int		i;
	char	*temp;

	i = 0;
	while (i < data->philos_amount)
	{
		philo_data[i].fork = 1;
		temp = ft_itoa((i + 1));
		philo_data[i].name = ft_strjoin("Philosopher ", temp);
		free(temp);
		philo_data[i].data = data;
		if (i == 0 && data->philos_amount > 1)
		{
			philo_data[i].previous = &philo_data[data->philos_amount - 1];
			philo_data[i].next = &philo_data[1];
		}
		else if (i == 0 && data->philos_amount == 1)
		{
			philo_data[i].previous = &philo_data[i];
			philo_data[i].next = &philo_data[i];
			return (0);
		}
		else if (i == data->philos_amount - 1)
		{
			philo_data[i].previous = &philo_data[i - 1];
			philo_data[i].next = &philo_data[0];
		}
		else
		{
			philo_data[i].previous = &philo_data[i - 1];
			philo_data[i].next = &philo_data[i + 1];
		}
		i++;
	}
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("Name: %s\n", philo->name);
	while (1)
	{
		usleep(100000);
		printf("%s is doing stuff\n", philo->name);
	}
	return (NULL);
}