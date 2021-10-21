/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   take_action.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/21 21:36:13 by idonado       #+#    #+#                 */
/*   Updated: 2021/10/21 21:36:15 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	check_actions(int action)
{
	if (action == 2)
		ft_putstr_fd(" grabbed a fork. \n", 1);
	else if (action == 3)
		ft_putstr_fd(" is eating.\n", 1);
	else if (action == 4)
		ft_putstr_fd(" is sleeping.\n", 1);
	else if (action == 5)
		ft_putstr_fd(" is thinking.\n", 1);
	return ;
}

void	take_action(t_philo *philo, int action)
{
	if (pthread_mutex_lock(&philo->data->register_ability) != 0)
		return ;
	ft_putnbr_fd(ft_time() - philo->data->start, 1);
	ft_putchar_fd('\t', 1);
	if (action == 0)
	{
		ft_putstr_fd("\033[1m\033[32mAll philosophers have eaten at least ", 1);
		ft_putnbr_fd(philo->data->times_all_eat, 1);
		ft_putstr_fd(" times.\033[39m \n", 1);
		return ;
	}
	ft_putstr_fd("Philosopher ", 1);
	ft_putnbr_fd(philo->philo_number, 1);
	if (action == 1)
	{
		ft_putstr_fd(" has \033[1m\033[31mdied.\033[39m \n", 1);
		return ;
	}
	check_actions(action);
	if (pthread_mutex_unlock(&philo->data->register_ability) != 0)
		return ;
}
