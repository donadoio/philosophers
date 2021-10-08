#include <philo.h>

t_philo	*philos_init(t_data *data)
{
	t_philo	*philo;
	t_philo	*temp;
	int		i;

	philo = NULL;
	i = 0;
	temp = philo;
	while (i < data->philos_amount)
	{
		temp = lst_philo_new(data, i + 1);
		lst_philo_add_back(&philo, temp);
		i++;
	}
	temp = lst_philo_last(philo);
	temp->next = philo;
	philo->previous = temp;
	return (philo);
}

int	up_next(t_philo *philo)
{
	unsigned long long		philo_time;
	unsigned long long		biggest;
	t_philo	*temp;

	philo_time = philo->last_ate;
	temp = philo;
	temp = temp->next;
	gettimeofday(&philo->current_time, NULL);
	biggest = philo->current_time.tv_usec - philo->last_ate;
	while (temp != philo)
	{
		if (philo->current_time.tv_usec - temp->last_ate > biggest)
			biggest = philo->current_time.tv_usec - temp->last_ate;
		temp = temp->next;
	}
	if (biggest > philo->current_time.tv_usec - philo->last_ate)
		return (0);
	return (1);
}

int	is_dead(t_philo *philo)
{
	unsigned long long		philo_time;

	gettimeofday(&philo->current_time, NULL);
	philo_time = philo->current_time.tv_usec - philo->last_ate;
	if (philo->data->dying_time > (int)philo_time)
		return (0);
	else
		return (1);
}

int	forks_available(t_philo	*philo)
{
	int	i;
	t_philo	*temp;

	i = 0;
	temp = philo;
	if (temp->fork == 1)
		i++;
	temp = temp->next;
	while (temp != philo)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	int		locker;

	philo = (t_philo *)arg;
	while (1)
	{
		gettimeofday(&philo->current_time, NULL);
		while (up_next(philo) == 0)
		{
			locker = 0;
			pthread_mutex_lock(&lock);
			if (is_dead(philo) == 1)
			{
				locker = 1;
				philo->data->philo_dead = 1;
				printf("%d Philosopher %d died.\n", philo->current_time.tv_usec, philo->num);
				pthread_mutex_unlock(&lock);
				return (NULL);
			}
				if (locker == 0)
			pthread_mutex_unlock(&lock);
		}
		if (up_next(philo) == 1)
		{
			while (forks_available(philo) < 2)
				usleep(1);
		}
		locker = 0;
		pthread_mutex_lock(&lock);
		if (philo->previous->fork == 1 && philo->fork == 1 && up_next(philo) == 1 && philo->data->philo_dead == 0)
		{
			locker = 1;
			philo->fork = 0;
			philo->previous->fork = 0;
			pthread_mutex_unlock(&lock);
			gettimeofday(&philo->current_time, NULL);
			philo->last_ate = philo->current_time.tv_usec;
			printf("%d Philosopher %d is eating.\n", philo->current_time.tv_usec, philo->num);
			usleep(philo->data->eating_time);
			pthread_mutex_lock(&lock);
			philo->fork = 1;
			philo->previous->fork = 1;
			pthread_mutex_unlock(&lock);
			gettimeofday(&philo->current_time, NULL);
			printf("%d Philosopher %d is sleeping.\n", philo->current_time.tv_usec, philo->num);
			usleep(philo->data->sleeping_time);
		}
		if (locker == 0)
			pthread_mutex_unlock(&lock);
		if (philo->data->philo_dead == 0)
			printf("%d Philosopher %d is thinking.\n", philo->current_time.tv_usec, philo->num);
		else
			return (NULL);
	}
	return (NULL);
}